// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vneander.h for the primary calling header

#include "Vneander.h"
#include "Vneander__Syms.h"

//==========

VL_CTOR_IMP(Vneander) {
    Vneander__Syms* __restrict vlSymsp = __VlSymsp = new Vneander__Syms(this, name());
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vneander::__Vconfigure(Vneander__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vneander::~Vneander() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vneander::_settle__TOP__2(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_settle__TOP__2\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (~ ((IData)(vlTOPp->neander__DOT__STATE) 
                  >> 2U)))) {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            vlTOPp->neander__DOT__cargaRI = (1U & (~ (IData)(vlTOPp->neander__DOT__STATE)));
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((1U != (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__cargaNZ = 1U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((6U == (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__cargaNZ = 1U;
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                vlTOPp->neander__DOT__cargaNZ = 0U;
            }
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((1U == (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__memWrite = 1U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->neander__DOT__STATE) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                vlTOPp->neander__DOT__memWrite = 0U;
            }
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((1U & (~ ((IData)(vlTOPp->neander__DOT__STATE) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((((8U == (IData)(vlTOPp->neander__DOT__RI)) 
                      | (9U == (IData)(vlTOPp->neander__DOT__RI))) 
                     | (0xaU == (IData)(vlTOPp->neander__DOT__RI)))) {
                    vlTOPp->neander__DOT__cargaPC = 1U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->neander__DOT__STATE) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                vlTOPp->neander__DOT__cargaPC = 0U;
            }
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                vlTOPp->neander__DOT__cargaREM = 0U;
            }
        } else {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((1U & (~ (((8U == (IData)(vlTOPp->neander__DOT__RI)) 
                               | (9U == (IData)(vlTOPp->neander__DOT__RI))) 
                              | (0xaU == (IData)(vlTOPp->neander__DOT__RI)))))) {
                    vlTOPp->neander__DOT__cargaREM = 1U;
                }
            } else {
                vlTOPp->neander__DOT__cargaREM = 0U;
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((6U != (IData)(vlTOPp->neander__DOT__RI))) {
                    if ((1U & (~ (((9U == (IData)(vlTOPp->neander__DOT__RI)) 
                                   & (~ (IData)(vlTOPp->neander__DOT__N))) 
                                  | ((0xaU == (IData)(vlTOPp->neander__DOT__RI)) 
                                     & (~ (IData)(vlTOPp->neander__DOT__Z))))))) {
                        vlTOPp->neander__DOT__cargaREM = 1U;
                    }
                }
            }
        } else {
            vlTOPp->neander__DOT__cargaREM = (1U & 
                                              (~ (IData)(vlTOPp->neander__DOT__STATE)));
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((1U & (~ ((IData)(vlTOPp->neander__DOT__STATE) 
                      >> 1U)))) {
            vlTOPp->neander__DOT__incrementaPC = (1U 
                                                  & ((~ (IData)(vlTOPp->neander__DOT__STATE)) 
                                                     & (~ 
                                                        (((8U 
                                                           == (IData)(vlTOPp->neander__DOT__RI)) 
                                                          | (9U 
                                                             == (IData)(vlTOPp->neander__DOT__RI))) 
                                                         | (0xaU 
                                                            == (IData)(vlTOPp->neander__DOT__RI))))));
        }
    } else {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((6U != (IData)(vlTOPp->neander__DOT__RI))) {
                    if ((((9U == (IData)(vlTOPp->neander__DOT__RI)) 
                          & (~ (IData)(vlTOPp->neander__DOT__N))) 
                         | ((0xaU == (IData)(vlTOPp->neander__DOT__RI)) 
                            & (~ (IData)(vlTOPp->neander__DOT__Z))))) {
                        vlTOPp->neander__DOT__incrementaPC = 1U;
                    }
                }
            } else {
                vlTOPp->neander__DOT__incrementaPC = 0U;
            }
        } else {
            vlTOPp->neander__DOT__incrementaPC = (1U 
                                                  & (IData)(vlTOPp->neander__DOT__STATE));
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((1U & (~ ((IData)(vlTOPp->neander__DOT__STATE) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((1U & (~ (((8U == (IData)(vlTOPp->neander__DOT__RI)) 
                               | (9U == (IData)(vlTOPp->neander__DOT__RI))) 
                              | (0xaU == (IData)(vlTOPp->neander__DOT__RI)))))) {
                    vlTOPp->neander__DOT__SEL = 1U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((6U != (IData)(vlTOPp->neander__DOT__RI))) {
                    if ((1U & (~ (((9U == (IData)(vlTOPp->neander__DOT__RI)) 
                                   & (~ (IData)(vlTOPp->neander__DOT__N))) 
                                  | ((0xaU == (IData)(vlTOPp->neander__DOT__RI)) 
                                     & (~ (IData)(vlTOPp->neander__DOT__Z))))))) {
                        vlTOPp->neander__DOT__SEL = 0U;
                    }
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                vlTOPp->neander__DOT__SEL = 0U;
            }
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((1U != (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__ULA_SEL = 
                        (7U & (IData)(vlTOPp->neander__DOT__RI));
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((6U == (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__ULA_SEL = 6U;
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                if ((1U != (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__memRead = 1U;
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                vlTOPp->neander__DOT__memRead = 1U;
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                vlTOPp->neander__DOT__memRead = 0U;
            }
        } else {
            vlTOPp->neander__DOT__memRead = (1U & (IData)(vlTOPp->neander__DOT__STATE));
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                vlTOPp->neander__DOT__cargaRDM = 0U;
            } else {
                if ((1U == (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__cargaRDM = 1U;
                }
            }
        }
    }
    if ((4U & (IData)(vlTOPp->neander__DOT__STATE))) {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((1U != (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__cargaAC = 1U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->neander__DOT__STATE))) {
            if ((1U & (IData)(vlTOPp->neander__DOT__STATE))) {
                if ((6U == (IData)(vlTOPp->neander__DOT__RI))) {
                    vlTOPp->neander__DOT__cargaAC = 1U;
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->neander__DOT__STATE)))) {
                vlTOPp->neander__DOT__cargaAC = 0U;
            }
        }
    }
    vlTOPp->neander__DOT__ULA_OUT = (0xffU & ((4U & (IData)(vlTOPp->neander__DOT__ULA_SEL))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->neander__DOT__ULA_SEL))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->neander__DOT__ULA_SEL))
                                                    ? (IData)(vlTOPp->neander__DOT__RDM)
                                                    : 
                                                   (~ (IData)(vlTOPp->neander__DOT__ACC)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->neander__DOT__ULA_SEL))
                                                    ? 
                                                   ((IData)(vlTOPp->neander__DOT__ACC) 
                                                    & (IData)(vlTOPp->neander__DOT__RDM))
                                                    : 
                                                   ((IData)(vlTOPp->neander__DOT__ACC) 
                                                    | (IData)(vlTOPp->neander__DOT__RDM))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->neander__DOT__ULA_SEL))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->neander__DOT__ULA_SEL))
                                                    ? 
                                                   ((IData)(vlTOPp->neander__DOT__ACC) 
                                                    + (IData)(vlTOPp->neander__DOT__RDM))
                                                    : (IData)(vlTOPp->neander__DOT__RDM))
                                                   : (IData)(vlTOPp->neander__DOT__RDM))));
    vlTOPp->neander__DOT__ULA_Z = (0U == (IData)(vlTOPp->neander__DOT__ULA_OUT));
    vlTOPp->neander__DOT__ULA_N = (1U & ((IData)(vlTOPp->neander__DOT__ULA_OUT) 
                                         >> 7U));
}

void Vneander::_eval_initial(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_eval_initial\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
}

void Vneander::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::final\n"); );
    // Variables
    Vneander__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vneander::_eval_settle(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_eval_settle\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vneander::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_ctor_var_reset\n"); );
    // Body
    i_clk = VL_RAND_RESET_I(1);
    i_rst = VL_RAND_RESET_I(1);
    neander__DOT__ACC = VL_RAND_RESET_I(8);
    neander__DOT__ULA_SEL = VL_RAND_RESET_I(3);
    neander__DOT__ULA_OUT = VL_RAND_RESET_I(8);
    neander__DOT__ULA_Z = VL_RAND_RESET_I(1);
    neander__DOT__ULA_N = VL_RAND_RESET_I(1);
    neander__DOT__cargaAC = VL_RAND_RESET_I(1);
    neander__DOT__cargaNZ = VL_RAND_RESET_I(1);
    neander__DOT__cargaREM = VL_RAND_RESET_I(1);
    neander__DOT__cargaRDM = VL_RAND_RESET_I(1);
    neander__DOT__cargaRI = VL_RAND_RESET_I(1);
    neander__DOT__memRead = VL_RAND_RESET_I(1);
    neander__DOT__memWrite = VL_RAND_RESET_I(1);
    neander__DOT__RI = VL_RAND_RESET_I(8);
    neander__DOT__REM = VL_RAND_RESET_I(8);
    neander__DOT__RDM = VL_RAND_RESET_I(8);
    neander__DOT__SEL = VL_RAND_RESET_I(1);
    neander__DOT__N = VL_RAND_RESET_I(1);
    neander__DOT__Z = VL_RAND_RESET_I(1);
    neander__DOT__STATE = VL_RAND_RESET_I(3);
    neander__DOT__cargaPC = VL_RAND_RESET_I(1);
    neander__DOT__incrementaPC = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            neander__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }}
    neander__DOT__PC__DOT__internal_PC = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
