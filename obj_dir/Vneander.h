// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VNEANDER_H_
#define _VNEANDER_H_  // guard

#include "verilated.h"

//==========

class Vneander__Syms;
class Vneander_VerilatedVcd;


//----------

VL_MODULE(Vneander) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_clk,0,0);
    VL_IN8(i_rst,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ neander__DOT__ACC;
    CData/*2:0*/ neander__DOT__ULA_SEL;
    CData/*7:0*/ neander__DOT__ULA_OUT;
    CData/*0:0*/ neander__DOT__ULA_Z;
    CData/*0:0*/ neander__DOT__ULA_N;
    CData/*0:0*/ neander__DOT__cargaAC;
    CData/*0:0*/ neander__DOT__cargaNZ;
    CData/*0:0*/ neander__DOT__cargaREM;
    CData/*0:0*/ neander__DOT__cargaRDM;
    CData/*0:0*/ neander__DOT__cargaRI;
    CData/*0:0*/ neander__DOT__memRead;
    CData/*0:0*/ neander__DOT__memWrite;
    CData/*7:0*/ neander__DOT__RI;
    CData/*7:0*/ neander__DOT__REM;
    CData/*7:0*/ neander__DOT__RDM;
    CData/*0:0*/ neander__DOT__SEL;
    CData/*0:0*/ neander__DOT__N;
    CData/*0:0*/ neander__DOT__Z;
    CData/*2:0*/ neander__DOT__STATE;
    CData/*7:0*/ neander__DOT__cargaPC_val;
    CData/*0:0*/ neander__DOT__cargaPC;
    CData/*0:0*/ neander__DOT__incrementaPC;
    CData/*7:0*/ neander__DOT__PC__DOT__internal_PC;
    CData/*7:0*/ neander__DOT__memory[256];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__i_clk;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vneander__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vneander);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vneander(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vneander();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vneander__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vneander__Syms* symsp, bool first);
  private:
    static QData _change_request(Vneander__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vneander__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vneander__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vneander__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
