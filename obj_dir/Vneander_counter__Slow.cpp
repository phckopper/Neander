// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vneander.h for the primary calling header

#include "Vneander_counter.h"
#include "Vneander__Syms.h"

//==========

VL_CTOR_IMP(Vneander_counter) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vneander_counter::__Vconfigure(Vneander__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Vneander_counter::~Vneander_counter() {
}

void Vneander_counter::_settle__TOP__neander__PC__1(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vneander_counter::_settle__TOP__neander__PC__1\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander__PC.__PVT__o_PC = vlSymsp->TOP__neander__PC.__PVT__internal_PC;
}

void Vneander_counter::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vneander_counter::_ctor_var_reset\n"); );
    // Body
    __PVT__i_clk = VL_RAND_RESET_I(1);
    __PVT__i_rst = VL_RAND_RESET_I(1);
    __PVT__i_preload = VL_RAND_RESET_I(8);
    __PVT__i_preload_s = VL_RAND_RESET_I(1);
    __PVT__i_halt = VL_RAND_RESET_I(1);
    __PVT__o_PC = VL_RAND_RESET_I(8);
    __PVT__internal_PC = VL_RAND_RESET_I(8);
    __Vdly__internal_PC = VL_RAND_RESET_I(8);
}
