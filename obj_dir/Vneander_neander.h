// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vneander.h for the primary calling header

#ifndef _VNEANDER_NEANDER_H_
#define _VNEANDER_NEANDER_H_  // guard

#include "verilated.h"

//==========

class Vneander__Syms;
class Vneander_VerilatedVcd;
class Vneander_ULA;
class Vneander_counter;


//----------

VL_MODULE(Vneander_neander) {
  public:
    // CELLS
    Vneander_ULA* __PVT__ula;
    Vneander_counter* __PVT__PC;
    
    // PORTS
    VL_IN8(i_clk,0,0);
    VL_IN8(i_rst,0,0);
    
    // LOCAL SIGNALS
    CData/*7:0*/ __PVT__ACC;
    CData/*2:0*/ __PVT__ULA_SEL;
    CData/*7:0*/ __PVT__ULA_A;
    CData/*7:0*/ __PVT__ULA_OUT;
    CData/*7:0*/ __PVT__PC_val;
    CData/*7:0*/ __PVT__PC_preload;
    CData/*0:0*/ __PVT__PC_preload_s;
    CData/*0:0*/ __PVT__PC_halt;
    
    // LOCAL VARIABLES
    CData/*7:0*/ __Vdly__ACC;
    
    // INTERNAL VARIABLES
  private:
    Vneander__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vneander_neander);  ///< Copying not allowed
  public:
    Vneander_neander(const char* name = "TOP");
    ~Vneander_neander();
    
    // INTERNAL METHODS
    void __Vconfigure(Vneander__Syms* symsp, bool first);
    static void _combo__TOP__neander__2(Vneander__Syms* __restrict vlSymsp);
    static void _combo__TOP__neander__8(Vneander__Syms* __restrict vlSymsp);
    static void _combo__TOP__neander__9(Vneander__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP__neander__1(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__neander__6(Vneander__Syms* __restrict vlSymsp);
    static void _sequent__TOP__neander__7(Vneander__Syms* __restrict vlSymsp);
    static void _settle__TOP__neander__3(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__neander__4(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__neander__5(Vneander__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
