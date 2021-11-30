// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vneander.h for the primary calling header

#include "Vneander_counter.h"
#include "Vneander__Syms.h"

//==========

VL_INLINE_OPT void Vneander_counter::_sequent__TOP__neander__PC__2(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vneander_counter::_sequent__TOP__neander__PC__2\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__neander__PC.__Vdly__internal_PC = vlSymsp->TOP__neander__PC.__PVT__internal_PC;
    if ((1U & (~ (IData)(vlSymsp->TOP__neander__PC.__PVT__i_rst)))) {
        vlSymsp->TOP__neander__PC.__Vdly__internal_PC 
            = (0xffU & ((IData)(vlSymsp->TOP__neander__PC.__PVT__i_halt)
                         ? 0U : VL_SEL_IIII(8,32,32,32, 
                                            ((IData)(vlSymsp->TOP__neander__PC.__PVT__i_preload_s)
                                              ? VL_EXTEND_II(32,8, (IData)(vlSymsp->TOP__neander__PC.__PVT__i_preload))
                                              : ((IData)(1U) 
                                                 + 
                                                 VL_EXTEND_II(32,8, (IData)(vlSymsp->TOP__neander__PC.__PVT__internal_PC)))), 0U, 8U)));
    }
    vlSymsp->TOP__neander__PC.__PVT__internal_PC = vlSymsp->TOP__neander__PC.__Vdly__internal_PC;
    vlSymsp->TOP__neander__PC.__PVT__o_PC = vlSymsp->TOP__neander__PC.__PVT__internal_PC;
}
