// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vneander.h for the primary calling header

#include "Vneander_neander.h"
#include "Vneander__Syms.h"

//==========

VL_INLINE_OPT void Vneander_neander::_combo__TOP__neander__2(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_combo__TOP__neander__2\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander__PC.__PVT__i_clk = vlSymsp->TOP__neander.i_clk;
}

VL_INLINE_OPT void Vneander_neander::_sequent__TOP__neander__6(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_sequent__TOP__neander__6\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander.__Vdly__ACC = vlSymsp->TOP__neander.__PVT__ACC;
    vlSymsp->TOP__neander.__Vdly__ACC = vlSymsp->TOP__neander.__PVT__ULA_OUT;
    vlSymsp->TOP__neander.__PVT__ACC = vlSymsp->TOP__neander.__Vdly__ACC;
    vlSymsp->TOP__neander__ula.__PVT__i_B = vlSymsp->TOP__neander.__PVT__ACC;
}

VL_INLINE_OPT void Vneander_neander::_sequent__TOP__neander__7(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_sequent__TOP__neander__7\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander.__PVT__PC_val = vlSymsp->TOP__neander__PC.__PVT__o_PC;
    vlSymsp->TOP__neander.__PVT__ULA_A = vlSymsp->TOP__neander.__PVT__PC_val;
    vlSymsp->TOP__neander__ula.__PVT__i_A = vlSymsp->TOP__neander.__PVT__ULA_A;
}

VL_INLINE_OPT void Vneander_neander::_combo__TOP__neander__8(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_combo__TOP__neander__8\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander__PC.__PVT__i_rst = vlSymsp->TOP__neander.i_rst;
}

VL_INLINE_OPT void Vneander_neander::_combo__TOP__neander__9(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_combo__TOP__neander__9\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander.__PVT__ULA_OUT = vlSymsp->TOP__neander__ula.__PVT__o_OUT;
}
