// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vneander.h for the primary calling header

#ifndef _VNEANDER_COUNTER_H_
#define _VNEANDER_COUNTER_H_  // guard

#include "verilated.h"

//==========

class Vneander__Syms;
class Vneander_VerilatedVcd;


//----------

VL_MODULE(Vneander_counter) {
  public:
    
    // PORTS
    VL_IN8(__PVT__i_clk,0,0);
    VL_IN8(__PVT__i_rst,0,0);
    VL_IN8(__PVT__i_preload,7,0);
    VL_IN8(__PVT__i_preload_s,0,0);
    VL_IN8(__PVT__i_halt,0,0);
    VL_OUT8(__PVT__o_PC,7,0);
    
    // LOCAL SIGNALS
    CData/*7:0*/ __PVT__internal_PC;
    
    // LOCAL VARIABLES
    CData/*7:0*/ __Vdly__internal_PC;
    
    // INTERNAL VARIABLES
  private:
    Vneander__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vneander_counter);  ///< Copying not allowed
  public:
    Vneander_counter(const char* name = "TOP");
    ~Vneander_counter();
    
    // INTERNAL METHODS
    void __Vconfigure(Vneander__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__neander__PC__2(Vneander__Syms* __restrict vlSymsp);
    static void _settle__TOP__neander__PC__1(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
