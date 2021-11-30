// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vneander.h for the primary calling header

#include "Vneander_ULA.h"
#include "Vneander__Syms.h"

//==========

VL_INLINE_OPT void Vneander_ULA::_combo__TOP__neander__ula__2(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vneander_ULA::_combo__TOP__neander__ula__2\n"); );
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
