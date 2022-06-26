/*
 * Generated by Bluespec Compiler, version 2021.12.1 (build fd50140)
 * 
 * On Mon May  2 19:31:35 KST 2022
 * 
 */

/* Generation options: */
#ifndef __mkProc_h__
#define __mkProc_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkCsrFile.h"
#include "mkDMemory.h"
#include "mkIMemory.h"
#include "mkRFile.h"
#include "module_exec.h"
#include "module_decode.h"


/* Class declaration for the mkProc module */
class MOD_mkProc : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_mkCsrFile INST_csrf;
  MOD_mkDMemory INST_dMem;
  MOD_Reg<tUWide> INST_e2mw;
  MOD_Reg<tUInt32> INST_f2e;
  MOD_mkIMemory INST_iMem;
  MOD_Reg<tUInt32> INST_pc;
  MOD_mkRFile INST_rf;
  MOD_Reg<tUInt8> INST_stage;
  MOD_Reg<tUInt8> INST_stat;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_ehrReg;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_ignored_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_ignored_wires_1;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_virtual_reg_0;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_virtual_reg_1;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_wires_1;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_ignored_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_ignored_wires_1;
  MOD_Reg<tUInt8> INST_statRedirect_deqP_virtual_reg_0;
  MOD_Reg<tUInt8> INST_statRedirect_deqP_virtual_reg_1;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_wires_1;
  MOD_Reg<tUInt8> INST_statRedirect_empty_ehrReg;
  MOD_Wire<tUInt8> INST_statRedirect_empty_ignored_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_empty_ignored_wires_1;
  MOD_Wire<tUInt8> INST_statRedirect_empty_ignored_wires_2;
  MOD_Reg<tUInt8> INST_statRedirect_empty_virtual_reg_0;
  MOD_Reg<tUInt8> INST_statRedirect_empty_virtual_reg_1;
  MOD_Reg<tUInt8> INST_statRedirect_empty_virtual_reg_2;
  MOD_Wire<tUInt8> INST_statRedirect_empty_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_empty_wires_1;
  MOD_Wire<tUInt8> INST_statRedirect_empty_wires_2;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_ignored_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_ignored_wires_1;
  MOD_Reg<tUInt8> INST_statRedirect_enqP_virtual_reg_0;
  MOD_Reg<tUInt8> INST_statRedirect_enqP_virtual_reg_1;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_wires_1;
  MOD_Reg<tUInt8> INST_statRedirect_full_ehrReg;
  MOD_Wire<tUInt8> INST_statRedirect_full_ignored_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_full_ignored_wires_1;
  MOD_Wire<tUInt8> INST_statRedirect_full_ignored_wires_2;
  MOD_Reg<tUInt8> INST_statRedirect_full_virtual_reg_0;
  MOD_Reg<tUInt8> INST_statRedirect_full_virtual_reg_1;
  MOD_Reg<tUInt8> INST_statRedirect_full_virtual_reg_2;
  MOD_Wire<tUInt8> INST_statRedirect_full_wires_0;
  MOD_Wire<tUInt8> INST_statRedirect_full_wires_1;
  MOD_Wire<tUInt8> INST_statRedirect_full_wires_2;
  MOD_module_exec INST_instance_exec_1;
  MOD_module_decode INST_instance_decode_0;
 
 /* Constructor */
 public:
  MOD_mkProc(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUInt8 PORT_EN_dMemInit_request_put;
  tUInt8 PORT_EN_iMemInit_request_put;
  tUWide PORT_dMemInit_request_put;
  tUWide PORT_iMemInit_request_put;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_dMemInit_request_put;
  tUInt8 DEF_WILL_FIRE_iMemInit_request_put;
  tUInt8 DEF_dMem_RDY_init_request_put____d29;
  tUInt8 DEF_iMem_RDY_init_request_put____d28;
  tUInt8 DEF_csrf_started____d38;
  tUInt8 DEF_dMem_init_done____d33;
  tUInt8 DEF_iMem_init_done____d31;
 
 /* Local definitions */
 private:
  tUWide DEF_exec___d219;
  tUWide DEF_decode___d203;
  tUInt32 DEF_pc___d45;
  tUWide DEF_e2mw___d227;
  tUInt32 DEF__read_data__h6531;
  tUInt32 DEF__read_addr__h6532;
  tUInt8 DEF_e2mw_27_BITS_88_TO_85___d228;
  tUWide DEF_e2mw_27_BITS_88_TO_66_40_CONCAT_IF_e2mw_27_BIT_ETC___d243;
  tUWide DEF__1_CONCAT_DONTCARE___d37;
  tUWide DEF_NOT_e2mw_27_BITS_88_TO_85_28_EQ_2_29_32_CONCAT_ETC___d239;
 
 /* Rules */
 public:
  void RL_statRedirect_data_0_canonicalize();
  void RL_statRedirect_empty_canonicalize();
  void RL_statRedirect_full_canonicalize();
  void RL_test();
  void RL_doFetch();
  void RL_doExecute();
  void RL_doMemory();
  void RL_doWriteBack();
 
 /* Methods */
 public:
  tUInt64 METH_cpuToHost();
  tUInt8 METH_RDY_cpuToHost();
  void METH_hostToCpu(tUInt32 ARG_hostToCpu_startpc);
  tUInt8 METH_RDY_hostToCpu();
  void METH_iMemInit_request_put(tUWide ARG_iMemInit_request_put);
  tUInt8 METH_RDY_iMemInit_request_put();
  tUInt8 METH_iMemInit_done();
  tUInt8 METH_RDY_iMemInit_done();
  void METH_dMemInit_request_put(tUWide ARG_dMemInit_request_put);
  tUInt8 METH_RDY_dMemInit_request_put();
  tUInt8 METH_dMemInit_done();
  tUInt8 METH_RDY_dMemInit_done();
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkProc &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkProc &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkProc &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkProc &backing);
};

#endif /* ifndef __mkProc_h__ */
