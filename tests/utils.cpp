#include <stdlib.h>

#include "Vneander.h"
#include "verilated.h"

#include <map>
#include <string>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define OP_NOP 0b00000000
#define OP_STA 0b00000001
#define OP_LDA 0b00000010
#define OP_ADD 0b00000011
#define OP_OR  0b00000100
#define OP_AND 0b00000101
#define OP_NOT 0b00000110

#define OP_JMP 0b00001000
#define OP_JN  0b00001001
#define OP_JZ  0b00001010
#define OP_HLT 0b00001111

std::map<uint8_t, std::string> instr_mapping = {
    {OP_NOP, "NOP"},
    {OP_STA, "STA"},
    {OP_LDA, "LDA"},
    {OP_ADD, "ADD"},
    {OP_OR,  "OR "},
    {OP_AND, "AND"},
    {OP_NOT, "NOT"},

    {OP_JMP, "JMP"},
    {OP_JN,  "JN "},
    {OP_JZ,  "JZ "},
    {OP_HLT, "HLT"},
};

VerilatedVcdC* tfp = new VerilatedVcdC;
static uint32_t _time = 0;

void tick(Vneander *tb) {
    tb->eval();
    tb->i_clk = 1;
    tb->eval();
    tb->i_clk = 0;
    tb->eval();
    tfp->dump(_time++);
}

void reset(Vneander *tb) {
    tb->i_rst = 1;
    tick(tb);
    tb->i_rst = 0;
}


uint8_t tick_instruction(Vneander *tb) {
    if(tb->neander__DOT__STATE != 0) {
        puts("State is not zero!");
        return OP_HLT;
    }
    
    do { tick(tb); } while(tb->neander__DOT__STATE != 0);

    return tb->neander__DOT__RI;
}

void dump_state(Vneander *tb) {
    printf("[PC] = %d | [STATE] = %d\n", tb->neander__DOT__PC__DOT__internal_PC, tb->neander__DOT__STATE);
    printf("[X/ACC] = %d | [Y] = %d | [OUT] = %d\n", 
        tb->neander__DOT__ACC, tb->neander__DOT__RDM,
        tb->neander__DOT__ULA_OUT);
    printf("[REM] = %d | [RDM] = %d\n", tb->neander__DOT__REM, tb->neander__DOT__RDM);
    printf("[SEL] = %d | [RI] = %d\n", tb->neander__DOT__SEL, tb->neander__DOT__RI);
}

void dump_mem(Vneander *tb, uint8_t start, uint8_t end) {
    for (uint8_t i = start; i < end; i++)
    {
        printf("[%03d] = %02x\n", i, tb->neander__DOT__memory[i]);
    }
    
}