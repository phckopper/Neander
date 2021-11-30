// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vneander.h for the primary calling header

#include "Vneander_ULA.h"
#include "Vneander__Syms.h"

//==========

VL_CTOR_IMP(Vneander_ULA) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vneander_ULA::__Vconfigure(Vneander__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Vneander_ULA::~Vneander_ULA() {
}

void Vneander_ULA::_settle__TOP__neander__ula__1(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vneander_ULA::_settle__TOP__neander__ula__1\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander__ula.__PVT__o_OUT = (0xffU 
                                               & ((3U 
                                                   == (IData)(vlSymsp->TOP__neander__ula.__PVT__i_SEL))
                                                   ? 
                                                  ((IData)(vlSymsp->TOP__neander__ula.__PVT__i_A) 
                                                   + (IData)(vlSymsp->TOP__neander__ula.__PVT__i_B))
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSymsp->TOP__neander__ula.__PVT__i_SEL))
                                                    ? 
                                                   ((IData)(vlSymsp->TOP__neander__ula.__PVT__i_A) 
                                                    | (IData)(vlSymsp->TOP__neander__ula.__PVT__i_B))
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSymsp->TOP__neander__ula.__PVT__i_SEL))
                                                     ? 
                                                    ((IData)(vlSymsp->TOP__neander__ula.__PVT__i_A) 
                                                     & (IData)(vlSymsp->TOP__neander__ula.__PVT__i_B))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSymsp->TOP__neander__ula.__PVT__i_SEL))
                                                      ? 
                                                     (~ (IData)(vlSymsp->TOP__neander__ula.__PVT__i_B))
                                                      : (IData)(vlSymsp->TOP__neander__ula.__PVT__i_B))))));
}

void Vneander_ULA::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vneander_ULA::_ctor_var_reset\n"); );
    // Body
    __PVT__i_A = VL_RAND_RESET_I(8);
    __PVT__i_B = VL_RAND_RESET_I(8);
    __PVT__i_SEL = VL_RAND_RESET_I(3);
    __PVT__o_OUT = VL_RAND_RESET_I(8);
}
