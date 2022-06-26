import Types::*;
import ProcTypes::*;
import CMemTypes::*;
import RFile::*;
import IMemory::*;
import DMemory::*;
import Decode::*;
import Exec::*;
import CsrFile::*;
import Vector::*;
import Fifo::*;
import Ehr::*;
import GetPut::*;
//import Cop::*;


typedef enum {Fetch, Execute, Memory, WriteBack} Stage deriving(Bits, Eq);



(*synthesize*)
module mkProc(Proc);
  Reg#(Addr)    pc  <- mkRegU;
  RFile         rf  <- mkRFile;
  IMemory     iMem  <- mkIMemory;
  DMemory     dMem  <- mkDMemory;
  CsrFile     csrf <- mkCsrFile;

  Reg#(ProcStatus)   stat		<- mkRegU;
  Reg#(Stage)		 stage		<- mkRegU;

  Fifo#(1,ProcStatus) statRedirect <- mkBypassFifo;

  Reg#(Instruction)		f2e 	<- mkRegU;
  Reg#(ExecInst) e2mw <- mkRegU;

  Bool memReady = iMem.init.done() && dMem.init.done();
  rule test (!memReady);
    let e = tagged InitDone;
    iMem.init.request.put(e);
    dMem.init.request.put(e);
  endrule

  rule doFetch(csrf.started && stat == AOK && stage == Fetch);
    let inst = iMem.req(pc);

    $display("Fetch : from Pc %d , expanded inst : %x, \n", pc, inst, showInst(inst));
    stage <= Execute;
    f2e <= inst;  
  endrule

  rule doExecute(csrf.started && stat == AOK && stage == Execute);
    /* TODO: Divide the doExecute rule into doExecute, doMemory and doWriteBack rules */
    /* The doMemory rule should be skipped whenever it is not required. */
    let inst   = f2e;

	  /* Decode */
    DecodedInst dInst = decode(inst);

    // read general purpose register values 
    let rVal1 = isValid(dInst.src1) ? rf.rd1(validValue(dInst.src1)) : ?;
    let rVal2 = isValid(dInst.src2) ? rf.rd2(validValue(dInst.src2)) : ?;
    let csrVal = isValid(dInst.csr) ? csrf.rd(validValue(dInst.csr)) : ?;

    /* Execute */
    ExecInst eInst = exec(dInst, rVal1, rVal2, pc, ?, csrVal);  
    e2mw <= eInst;
    if(eInst.iType==Ld || eInst.iType==St) begin
	    stage <= Memory;
    end
    else begin
	    stage <= WriteBack;
    end
  endrule


  rule doMemory(csrf.started && stat == AOK && stage == Memory);

    let eInst = e2mw;
    let iType = eInst.iType;
    case(iType)
      Ld: begin
	eInst.data <- dMem.req(MemReq{op: Ld, addr: eInst.addr, data: ?});
	end
      St: begin
        let d <- dMem.req(MemReq{op: St, addr: eInst.addr, data: eInst.data});
        end
    endcase

    e2mw <= eInst; 
    stage <= WriteBack;
  endrule


  rule doWriteBack(csrf.started && stat == AOK && stage == WriteBack);

    let eInst = e2mw;
    if(isValid(eInst.dst)) begin
	rf.wr(fromMaybe(?, eInst.dst), eInst.data);
    end

    pc <= eInst.brTaken ? eInst.addr : pc + 4;

    csrf.wr(eInst.iType == Csrw ? eInst.csr : Invalid, eInst.data);
    
    e2mw <= eInst;
    stage <= Fetch;
  endrule


  method ActionValue#(CpuToHostData) cpuToHost;
    let retV <- csrf.cpuToHost;
    return retV;
  endmethod

  method Action hostToCpu(Bit#(32) startpc) if (!csrf.started);
    csrf.start(0);
    stage <= Fetch;
    pc <= startpc;
    stat <= AOK;
  endmethod

  interface iMemInit = iMem.init;
  interface dMemInit = dMem.init;

endmodule
