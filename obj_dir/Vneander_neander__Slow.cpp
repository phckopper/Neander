// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vneander.h for the primary calling header

#include "Vneander_neander.h"
#include "Vneander__Syms.h"

//==========

VL_CTOR_IMP(Vneander_neander) {
    VL_CELL(__PVT__ula, Vneander_ULA);
    VL_CELL(__PVT__PC, Vneander_counter);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vneander_neander::__Vconfigure(Vneander__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Vneander_neander::~Vneander_neander() {
}

void Vneander_neander::_initial__TOP__neander__1(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_initial__TOP__neander__1\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander.__PVT__PC_preload = 0U;
    vlSymsp->TOP__neander.__PVT__PC_preload_s = 0U;
    vlSymsp->TOP__neander.__PVT__PC_halt = 0U;
    vlSymsp->TOP__neander.__PVT__ULA_SEL = 4U;
    vlSymsp->TOP__neander__PC.__PVT__i_preload = vlSymsp->TOP__neander.__PVT__PC_preload;
    vlSymsp->TOP__neander__PC.__PVT__i_preload_s = vlSymsp->TOP__neander.__PVT__PC_preload_s;
    vlSymsp->TOP__neander__PC.__PVT__i_halt = vlSymsp->TOP__neander.__PVT__PC_halt;
    vlSymsp->TOP__neander__ula.__PVT__i_SEL = vlSymsp->TOP__neander.__PVT__ULA_SEL;
}

void Vneander_neander::_settle__TOP__neander__3(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_settle__TOP__neander__3\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander__ula.__PVT__i_B = vlSymsp->TOP__neander.__PVT__ACC;
    vlSymsp->TOP__neander__PC.__PVT__i_preload = vlSymsp->TOP__neander.__PVT__PC_preload;
    vlSymsp->TOP__neander__PC.__PVT__i_preload_s = vlSymsp->TOP__neander.__PVT__PC_preload_s;
    vlSymsp->TOP__neander__PC.__PVT__i_halt = vlSymsp->TOP__neander.__PVT__PC_halt;
    vlSymsp->TOP__neander__ula.__PVT__i_SEL = vlSymsp->TOP__neander.__PVT__ULA_SEL;
    vlSymsp->TOP__neander__PC.__PVT__i_rst = vlSymsp->TOP__neander.i_rst;
    vlSymsp->TOP__neander__PC.__PVT__i_clk = vlSymsp->TOP__neander.i_clk;
}

void Vneander_neander::_settle__TOP__neander__4(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_settle__TOP__neander__4\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander.__PVT__PC_val = vlSymsp->TOP__neander__PC.__PVT__o_PC;
    vlSymsp->TOP__neander.__PVT__ULA_A = vlSymsp->TOP__neander.__PVT__PC_val;
    vlSymsp->TOP__neander__ula.__PVT__i_A = vlSymsp->TOP__neander.__PVT__ULA_A;
}

void Vneander_neander::_settle__TOP__neander__5(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_settle__TOP__neander__5\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander.__PVT__ULA_OUT = vlSymsp->TOP__neander__ula.__PVT__o_OUT;
}

void Vneander_neander::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vneander_neander::_ctor_var_reset\n"); );
    // Body
    i_clk = VL_RAND_RESET_I(1);
    i_rst = VL_RAND_RESET_I(1);
    __PVT__ACC = VL_RAND_RESET_I(8);
    __PVT__ULA_SEL = VL_RAND_RESET_I(3);
    __PVT__ULA_A = VL_RAND_RESET_I(8);
    __PVT__ULA_OUT = VL_RAND_RESET_I(8);
    __PVT__PC_val = VL_RAND_RESET_I(8);
    __PVT__PC_preload = VL_RAND_RESET_I(8);
    __PVT__PC_preload_s = VL_RAND_RESET_I(1);
    __PVT__PC_halt = VL_RAND_RESET_I(1);
    __Vdly__ACC = VL_RAND_RESET_I(8);
}
