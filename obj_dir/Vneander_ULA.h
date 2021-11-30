// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vneander.h for the primary calling header

#ifndef _VNEANDER_ULA_H_
#define _VNEANDER_ULA_H_  // guard

#include "verilated.h"

//==========

class Vneander__Syms;
class Vneander_VerilatedVcd;


//----------

VL_MODULE(Vneander_ULA) {
  public:
    
    // PORTS
    VL_IN8(__PVT__i_A,7,0);
    VL_IN8(__PVT__i_B,7,0);
    VL_IN8(__PVT__i_SEL,2,0);
    VL_OUT8(__PVT__o_OUT,7,0);
    
    // INTERNAL VARIABLES
  private:
    Vneander__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vneander_ULA);  ///< Copying not allowed
  public:
    Vneander_ULA(const char* name = "TOP");
    ~Vneander_ULA();
    
    // INTERNAL METHODS
    void __Vconfigure(Vneander__Syms* symsp, bool first);
    static void _combo__TOP__neander__ula__2(Vneander__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _settle__TOP__neander__ula__1(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
