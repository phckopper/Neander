// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vneander.h for the primary calling header

#include "Vneander.h"
#include "Vneander__Syms.h"

//==========

void Vneander::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vneander::eval\n"); );
    Vneander__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/neander.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vneander::_eval_initial_loop(Vneander__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/neander.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vneander::_sequent__TOP__1(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_sequent__TOP__1\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__neander__DOT__memory__v0;
    CData/*7:0*/ __Vdlyvval__neander__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__neander__DOT__memory__v0;
    CData/*7:0*/ __Vdly__neander__DOT__REM;
    CData/*7:0*/ __Vdly__neander__DOT__PC__DOT__internal_PC;
    // Body
    __Vdly__neander__DOT__PC__DOT__internal_PC = vlTOPp->neander__DOT__PC__DOT__internal_PC;
    __Vdlyvset__neander__DOT__memory__v0 = 0U;
    __Vdly__neander__DOT__REM = vlTOPp->neander__DOT__REM;
    if (vlTOPp->i_rst) {
        __Vdly__neander__DOT__PC__DOT__internal_PC = 0U;
    } else {
        if (vlTOPp->neander__DOT__incrementaPC) {
            __Vdly__neander__DOT__PC__DOT__internal_PC 
                = (0xffU & ((IData)(1U) + (IData)(vlTOPp->neander__DOT__PC__DOT__internal_PC)));
        } else {
            if (vlTOPp->neander__DOT__cargaPC) {
                __Vdly__neander__DOT__PC__DOT__internal_PC 
                    = vlTOPp->neander__DOT__RDM;
            }
        }
    }
    if (vlTOPp->neander__DOT__memWrite) {
        __Vdlyvval__neander__DOT__memory__v0 = vlTOPp->neander__DOT__RDM;
        __Vdlyvset__neander__DOT__memory__v0 = 1U;
        __Vdlyvdim0__neander__DOT__memory__v0 = vlTOPp->neander__DOT__REM;
    }
    vlTOPp->neander__DOT__STATE = ((4U & (IData)(vlTOPp->neander__DOT__STATE))
                                    ? ((2U & (IData)(vlTOPp->neander__DOT__STATE))
                                        ? ((1U & (IData)(vlTOPp->neander__DOT__STATE))
                                            ? 0U : 7U)
                                        : ((1U & (IData)(vlTOPp->neander__DOT__STATE))
                                            ? ((((8U 
                                                  == (IData)(vlTOPp->neander__DOT__RI)) 
                                                 | (9U 
                                                    == (IData)(vlTOPp->neander__DOT__RI))) 
                                                | (0xaU 
                                                   == (IData)(vlTOPp->neander__DOT__RI)))
                                                ? 0U
                                                : 6U)
                                            : 5U)) : 
                                   ((2U & (IData)(vlTOPp->neander__DOT__STATE))
                                     ? ((1U & (IData)(vlTOPp->neander__DOT__STATE))
                                         ? ((6U == (IData)(vlTOPp->neander__DOT__RI))
                                             ? 0U : 
                                            ((((9U 
                                                == (IData)(vlTOPp->neander__DOT__RI)) 
                                               & (~ (IData)(vlTOPp->neander__DOT__N))) 
                                              | ((0xaU 
                                                  == (IData)(vlTOPp->neander__DOT__RI)) 
                                                 & (~ (IData)(vlTOPp->neander__DOT__Z))))
                                              ? 0U : 4U))
                                         : 3U) : ((1U 
                                                   & (IData)(vlTOPp->neander__DOT__STATE))
                                                   ? 2U
                                                   : 1U)));
    if (vlTOPp->neander__DOT__cargaNZ) {
        vlTOPp->neander__DOT__N = vlTOPp->neander__DOT__ULA_N;
    }
    if (vlTOPp->neander__DOT__cargaNZ) {
        vlTOPp->neander__DOT__Z = vlTOPp->neander__DOT__ULA_Z;
    }
    if (vlTOPp->neander__DOT__SEL) {
        if (vlTOPp->neander__DOT__cargaREM) {
            __Vdly__neander__DOT__REM = vlTOPp->neander__DOT__RDM;
        }
    } else {
        if (vlTOPp->neander__DOT__cargaREM) {
            __Vdly__neander__DOT__REM = vlTOPp->neander__DOT__PC__DOT__internal_PC;
        }
    }
    if (vlTOPp->neander__DOT__cargaRI) {
        vlTOPp->neander__DOT__RI = vlTOPp->neander__DOT__RDM;
    }
    vlTOPp->neander__DOT__PC__DOT__internal_PC = __Vdly__neander__DOT__PC__DOT__internal_PC;
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
    if (vlTOPp->neander__DOT__memRead) {
        vlTOPp->neander__DOT__RDM = vlTOPp->neander__DOT__memory
            [vlTOPp->neander__DOT__REM];
    }
    if (vlTOPp->neander__DOT__cargaRDM) {
        vlTOPp->neander__DOT__RDM = vlTOPp->neander__DOT__ACC;
    }
    vlTOPp->neander__DOT__REM = __Vdly__neander__DOT__REM;
    if (__Vdlyvset__neander__DOT__memory__v0) {
        vlTOPp->neander__DOT__memory[__Vdlyvdim0__neander__DOT__memory__v0] 
            = __Vdlyvval__neander__DOT__memory__v0;
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
    if (vlTOPp->neander__DOT__cargaAC) {
        vlTOPp->neander__DOT__ACC = vlTOPp->neander__DOT__ULA_OUT;
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
                                                   (~ (IData)(vlTOPp->neander__DOT__RDM)))
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

void Vneander::_eval(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_eval\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
}

VL_INLINE_OPT QData Vneander::_change_request(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_change_request\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vneander::_change_request_1(Vneander__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_change_request_1\n"); );
    Vneander* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vneander::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vneander::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_rst & 0xfeU))) {
        Verilated::overWidthError("i_rst");}
}
#endif  // VL_DEBUG
