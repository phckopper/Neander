// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vneander__Syms.h"


void Vneander::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vneander__Syms* __restrict vlSymsp = static_cast<Vneander__Syms*>(userp);
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vneander::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vneander__Syms* __restrict vlSymsp = static_cast<Vneander__Syms*>(userp);
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->neander__DOT__ACC),8);
            tracep->chgCData(oldp+1,(vlTOPp->neander__DOT__ULA_SEL),3);
            tracep->chgCData(oldp+2,(vlTOPp->neander__DOT__ULA_OUT),8);
            tracep->chgCData(oldp+3,(vlTOPp->neander__DOT__RDM),8);
            tracep->chgBit(oldp+4,(vlTOPp->neander__DOT__ULA_Z));
            tracep->chgBit(oldp+5,(vlTOPp->neander__DOT__ULA_N));
            tracep->chgBit(oldp+6,(vlTOPp->neander__DOT__cargaAC));
            tracep->chgBit(oldp+7,(vlTOPp->neander__DOT__cargaNZ));
            tracep->chgBit(oldp+8,(vlTOPp->neander__DOT__cargaREM));
            tracep->chgBit(oldp+9,(vlTOPp->neander__DOT__cargaRDM));
            tracep->chgBit(oldp+10,(vlTOPp->neander__DOT__cargaRI));
            tracep->chgBit(oldp+11,(vlTOPp->neander__DOT__memRead));
            tracep->chgBit(oldp+12,(vlTOPp->neander__DOT__memWrite));
            tracep->chgCData(oldp+13,(vlTOPp->neander__DOT__RI),8);
            tracep->chgCData(oldp+14,(vlTOPp->neander__DOT__REM),8);
            tracep->chgBit(oldp+15,(vlTOPp->neander__DOT__SEL));
            tracep->chgBit(oldp+16,(vlTOPp->neander__DOT__N));
            tracep->chgBit(oldp+17,(vlTOPp->neander__DOT__Z));
            tracep->chgCData(oldp+18,(vlTOPp->neander__DOT__STATE),3);
            tracep->chgCData(oldp+19,(vlTOPp->neander__DOT__PC__DOT__internal_PC),8);
            tracep->chgBit(oldp+20,(vlTOPp->neander__DOT__cargaPC));
            tracep->chgBit(oldp+21,(vlTOPp->neander__DOT__incrementaPC));
        }
        tracep->chgBit(oldp+22,(vlTOPp->i_clk));
        tracep->chgBit(oldp+23,(vlTOPp->i_rst));
    }
}

void Vneander::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vneander__Syms* __restrict vlSymsp = static_cast<Vneander__Syms*>(userp);
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
