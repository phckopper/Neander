#include <stdlib.h>

#include "Vneander.h"
#include "verilated.h"


#define OP_NOP 0b00000000;
#define OP_STA 0b00000001;
#define OP_LDA 0b00000010;
#define OP_ADD 0b00000011;
#define OP_OR  0b00000100;
#define OP_AND 0b00000101;
#define OP_NOT 0b00000110;

#define OP_JMP 0b00001000;
#define OP_JN  0b00001001;
#define OP_JZ  0b00001010;
#define OP_HLT 0b00001111;

void tick(Vneander *tb) {
    tb->eval();
    tb->i_clk = 1;
    tb->eval();
    tb->i_clk = 0;
    tb->eval();
}

void reset(Vneander *tb) {
    tb->i_rst = 1;
    tick(tb);
    tb->i_rst = 0;
}

void dump_state(Vneander *tb) {
    printf("[PC] = %d | [STATE] = %d\n", tb->neander__DOT__PC__DOT__internal_PC, tb->neander__DOT__STATE);
    printf("[X/ACC] = %d | [Y] = %d | [OUT] = %d\n", 
        tb->neander__DOT__ACC, tb->neander__DOT__RDM,
        tb->neander__DOT__ULA_OUT);
    printf("[REM] = %d | [RDM] = %d\n", tb->neander__DOT__REM, tb->neander__DOT__RDM);
    printf("[SEL] = %d | [RI] = %d\n", tb->neander__DOT__SEL, tb->neander__DOT__RI);
}

void dump_mem(Vneander *tb) {
    for (size_t i = 0; i < 256; i++)
    {
        printf("[%02x] = %02x\n", i, tb->neander__DOT__memory[i]);
    }
    
}