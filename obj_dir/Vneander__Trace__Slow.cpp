// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vneander__Syms.h"


//======================

void Vneander::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vneander::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vneander__Syms* __restrict vlSymsp = static_cast<Vneander__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vneander::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vneander::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vneander__Syms* __restrict vlSymsp = static_cast<Vneander__Syms*>(userp);
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vneander::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vneander__Syms* __restrict vlSymsp = static_cast<Vneander__Syms*>(userp);
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+25,"i_clk", false,-1);
        tracep->declBit(c+26,"i_rst", false,-1);
        tracep->declBus(c+27,"neander OP_NOP", false,-1, 7,0);
        tracep->declBus(c+28,"neander OP_STA", false,-1, 7,0);
        tracep->declBus(c+29,"neander OP_LDA", false,-1, 7,0);
        tracep->declBus(c+30,"neander OP_ADD", false,-1, 7,0);
        tracep->declBus(c+31,"neander OP_OR", false,-1, 7,0);
        tracep->declBus(c+32,"neander OP_AND", false,-1, 7,0);
        tracep->declBus(c+33,"neander OP_NOT", false,-1, 7,0);
        tracep->declBus(c+34,"neander OP_JMP", false,-1, 7,0);
        tracep->declBus(c+35,"neander OP_JN", false,-1, 7,0);
        tracep->declBus(c+36,"neander OP_JZ", false,-1, 7,0);
        tracep->declBus(c+37,"neander OP_HLT", false,-1, 7,0);
        tracep->declBus(c+38,"neander ULA_ADD", false,-1, 2,0);
        tracep->declBus(c+39,"neander ULA_OR", false,-1, 2,0);
        tracep->declBus(c+40,"neander ULA_AND", false,-1, 2,0);
        tracep->declBus(c+41,"neander ULA_NOT", false,-1, 2,0);
        tracep->declBit(c+25,"neander i_clk", false,-1);
        tracep->declBit(c+26,"neander i_rst", false,-1);
        tracep->declBus(c+1,"neander ACC", false,-1, 7,0);
        tracep->declBus(c+2,"neander ULA_SEL", false,-1, 2,0);
        tracep->declBus(c+3,"neander ULA_OUT", false,-1, 7,0);
        tracep->declBus(c+4,"neander ULA_Y", false,-1, 7,0);
        tracep->declBit(c+5,"neander ULA_Z", false,-1);
        tracep->declBit(c+6,"neander ULA_N", false,-1);
        tracep->declBit(c+7,"neander cargaAC", false,-1);
        tracep->declBit(c+8,"neander cargaNZ", false,-1);
        tracep->declBit(c+9,"neander cargaREM", false,-1);
        tracep->declBit(c+10,"neander cargaRDM", false,-1);
        tracep->declBit(c+11,"neander cargaRI", false,-1);
        tracep->declBit(c+12,"neander memRead", false,-1);
        tracep->declBit(c+13,"neander memWrite", false,-1);
        tracep->declBus(c+14,"neander RI", false,-1, 7,0);
        tracep->declBus(c+15,"neander REM", false,-1, 7,0);
        tracep->declBus(c+4,"neander RDM", false,-1, 7,0);
        tracep->declBit(c+16,"neander SEL", false,-1);
        tracep->declBit(c+17,"neander N", false,-1);
        tracep->declBit(c+18,"neander Z", false,-1);
        tracep->declBus(c+19,"neander STATE", false,-1, 2,0);
        tracep->declBus(c+20,"neander valorPC", false,-1, 7,0);
        tracep->declBus(c+21,"neander cargaPC_val", false,-1, 7,0);
        tracep->declBit(c+22,"neander cargaPC", false,-1);
        tracep->declBit(c+23,"neander incrementaPC", false,-1);
        tracep->declBit(c+24,"neander isJump", false,-1);
        tracep->declBus(c+38,"neander ula ADD", false,-1, 2,0);
        tracep->declBus(c+39,"neander ula OR", false,-1, 2,0);
        tracep->declBus(c+40,"neander ula AND", false,-1, 2,0);
        tracep->declBus(c+41,"neander ula NOT", false,-1, 2,0);
        tracep->declBus(c+1,"neander ula i_A", false,-1, 7,0);
        tracep->declBus(c+4,"neander ula i_B", false,-1, 7,0);
        tracep->declBus(c+2,"neander ula i_SEL", false,-1, 2,0);
        tracep->declBus(c+3,"neander ula o_OUT", false,-1, 7,0);
        tracep->declBit(c+5,"neander ula o_ZERO", false,-1);
        tracep->declBit(c+6,"neander ula o_NEG", false,-1);
        tracep->declBit(c+25,"neander PC i_clk", false,-1);
        tracep->declBit(c+26,"neander PC i_rst", false,-1);
        tracep->declBus(c+21,"neander PC i_preload", false,-1, 7,0);
        tracep->declBit(c+22,"neander PC i_preload_s", false,-1);
        tracep->declBit(c+23,"neander PC i_inc", false,-1);
        tracep->declBus(c+20,"neander PC o_PC", false,-1, 7,0);
        tracep->declBus(c+20,"neander PC internal_PC", false,-1, 7,0);
    }
}

void Vneander::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vneander::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vneander__Syms* __restrict vlSymsp = static_cast<Vneander__Syms*>(userp);
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vneander::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vneander__Syms* __restrict vlSymsp = static_cast<Vneander__Syms*>(userp);
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->neander__DOT__ACC),8);
        tracep->fullCData(oldp+2,(vlTOPp->neander__DOT__ULA_SEL),3);
        tracep->fullCData(oldp+3,(vlTOPp->neander__DOT__ULA_OUT),8);
        tracep->fullCData(oldp+4,(vlTOPp->neander__DOT__RDM),8);
        tracep->fullBit(oldp+5,(vlTOPp->neander__DOT__ULA_Z));
        tracep->fullBit(oldp+6,(vlTOPp->neander__DOT__ULA_N));
        tracep->fullBit(oldp+7,(vlTOPp->neander__DOT__cargaAC));
        tracep->fullBit(oldp+8,(vlTOPp->neander__DOT__cargaNZ));
        tracep->fullBit(oldp+9,(vlTOPp->neander__DOT__cargaREM));
        tracep->fullBit(oldp+10,(vlTOPp->neander__DOT__cargaRDM));
        tracep->fullBit(oldp+11,(vlTOPp->neander__DOT__cargaRI));
        tracep->fullBit(oldp+12,(vlTOPp->neander__DOT__memRead));
        tracep->fullBit(oldp+13,(vlTOPp->neander__DOT__memWrite));
        tracep->fullCData(oldp+14,(vlTOPp->neander__DOT__RI),8);
        tracep->fullCData(oldp+15,(vlTOPp->neander__DOT__REM),8);
        tracep->fullBit(oldp+16,(vlTOPp->neander__DOT__SEL));
        tracep->fullBit(oldp+17,(vlTOPp->neander__DOT__N));
        tracep->fullBit(oldp+18,(vlTOPp->neander__DOT__Z));
        tracep->fullCData(oldp+19,(vlTOPp->neander__DOT__STATE),3);
        tracep->fullCData(oldp+20,(vlTOPp->neander__DOT__PC__DOT__internal_PC),8);
        tracep->fullCData(oldp+21,(vlTOPp->neander__DOT__cargaPC_val),8);
        tracep->fullBit(oldp+22,(vlTOPp->neander__DOT__cargaPC));
        tracep->fullBit(oldp+23,(vlTOPp->neander__DOT__incrementaPC));
        tracep->fullBit(oldp+24,((1U & ((IData)(vlTOPp->neander__DOT__RI) 
                                        >> 3U))));
        tracep->fullBit(oldp+25,(vlTOPp->i_clk));
        tracep->fullBit(oldp+26,(vlTOPp->i_rst));
        tracep->fullCData(oldp+27,(0U),8);
        tracep->fullCData(oldp+28,(1U),8);
        tracep->fullCData(oldp+29,(2U),8);
        tracep->fullCData(oldp+30,(3U),8);
        tracep->fullCData(oldp+31,(4U),8);
        tracep->fullCData(oldp+32,(5U),8);
        tracep->fullCData(oldp+33,(6U),8);
        tracep->fullCData(oldp+34,(8U),8);
        tracep->fullCData(oldp+35,(9U),8);
        tracep->fullCData(oldp+36,(0xaU),8);
        tracep->fullCData(oldp+37,(0xfU),8);
        tracep->fullCData(oldp+38,(3U),3);
        tracep->fullCData(oldp+39,(4U),3);
        tracep->fullCData(oldp+40,(5U),3);
        tracep->fullCData(oldp+41,(6U),3);
    }
}
