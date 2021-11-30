#include <verilatedos.h>
#include <iostream>
#include <memory>
#include <sys/types.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vneander.h"

#include "utils.cpp"

void run_to_completion(Vneander *tb) {
	uint8_t curr_inst = 0;
	while(curr_inst != OP_HLT)
	{
		uint8_t pc = tb->neander__DOT__PC__DOT__internal_PC;
		curr_inst = tick_instruction(tb);

		printf("Running %s @ [%d] \n", instr_mapping.at(curr_inst).c_str(), pc);
		//dump_state(top);
		puts("----- NEXT -----");
	}
}

void test_lda(Vneander *tb) {
	puts(YEL "\nNow testing LDA..." RESET);
	reset(tb);
	uint8_t test_val = rand();
	uint8_t addr = 0;
    tb->neander__DOT__memory[addr++] = OP_LDA;
	tb->neander__DOT__memory[addr++] = 128;
	tb->neander__DOT__memory[addr++] = OP_HLT;

	tb->neander__DOT__memory[128] = test_val;

	run_to_completion(tb);
	(tb->neander__DOT__ACC == test_val) ? puts(GRN "LDA Passed!") : printf(RED "LDA Failed! Was %d but expected %d\n", tb->neander__DOT__ACC, test_val);
}

void test_sta(Vneander *tb) {
	puts(YEL "\nNow testing STA (depends on LDA)..." RESET);
	reset(tb);
	uint8_t test_val = rand();
	uint8_t addr = 0;
    tb->neander__DOT__memory[addr++] = OP_LDA;
	tb->neander__DOT__memory[addr++] = 128;
	tb->neander__DOT__memory[addr++] = OP_STA;
	tb->neander__DOT__memory[addr++] = 129;
	tb->neander__DOT__memory[addr++] = OP_HLT;

	tb->neander__DOT__memory[128] = test_val;

	run_to_completion(tb);
	(tb->neander__DOT__memory[129] == test_val) ? puts(GRN "STA Passed!") : printf(RED "STA Failed! Was %d but expected %d\n", tb->neander__DOT__memory[129], test_val);
}

void test_add(Vneander *tb) {
	puts(YEL "\nNow testing ADD (depends on LDA)..." RESET);
	reset(tb);
	uint8_t test_val1 = rand();
	uint8_t test_val2 = rand();
	uint8_t addr = 0;
    tb->neander__DOT__memory[addr++] = OP_LDA;
	tb->neander__DOT__memory[addr++] = 128;
	tb->neander__DOT__memory[addr++] = OP_ADD;
	tb->neander__DOT__memory[addr++] = 129;
	tb->neander__DOT__memory[addr++] = OP_HLT;

	tb->neander__DOT__memory[128] = test_val1;
	tb->neander__DOT__memory[129] = test_val2;

	run_to_completion(tb);
	(tb->neander__DOT__ACC == test_val1 + test_val2) ? puts(GRN "ADD Passed!") : printf(RED "ADD Failed! Was %d but expected %d\n", tb->neander__DOT__ACC, test_val1 + test_val2);
}

void test_and(Vneander *tb) {
	puts(YEL "\nNow testing AND (depends on LDA)..." RESET);
	reset(tb);
	uint8_t test_val1 = rand();
	uint8_t test_val2 = rand();
	uint8_t addr = 0;
    tb->neander__DOT__memory[addr++] = OP_LDA;
	tb->neander__DOT__memory[addr++] = 128;
	tb->neander__DOT__memory[addr++] = OP_AND;
	tb->neander__DOT__memory[addr++] = 129;
	tb->neander__DOT__memory[addr++] = OP_HLT;

	tb->neander__DOT__memory[128] = test_val1;
	tb->neander__DOT__memory[129] = test_val2;

	run_to_completion(tb);
	(tb->neander__DOT__ACC == test_val1 & test_val2) ? puts(GRN "AND Passed!") : printf(RED "AND Failed! Was %d but expected %d\n", tb->neander__DOT__ACC, test_val1 & test_val2);
}

void test_or(Vneander *tb) {
	puts(YEL "\nNow testing OR (depends on LDA)..." RESET);
	reset(tb);
	uint8_t test_val1 = rand();
	uint8_t test_val2 = rand();
	uint8_t addr = 0;
    tb->neander__DOT__memory[addr++] = OP_LDA;
	tb->neander__DOT__memory[addr++] = 128;
	tb->neander__DOT__memory[addr++] = OP_OR;
	tb->neander__DOT__memory[addr++] = 129;
	tb->neander__DOT__memory[addr++] = OP_HLT;

	tb->neander__DOT__memory[128] = test_val1;
	tb->neander__DOT__memory[129] = test_val2;

	run_to_completion(tb);
	(tb->neander__DOT__ACC == test_val1 | test_val2) ? puts(GRN "OR Passed!") : printf(RED "OR Failed! Was %d but expected %d\n", tb->neander__DOT__ACC, test_val1 | test_val2);
}

void test_not(Vneander *tb) {
	puts(YEL "\nNow testing NOT (depends on LDA)..." RESET);
	reset(tb);
	uint8_t test_val = rand();
	uint8_t addr = 0;
    tb->neander__DOT__memory[addr++] = OP_LDA;
	tb->neander__DOT__memory[addr++] = 128;
	tb->neander__DOT__memory[addr++] = OP_NOT;
	tb->neander__DOT__memory[addr++] = OP_HLT;

	tb->neander__DOT__memory[128] = test_val;

	uint8_t expected = ~test_val;

	run_to_completion(tb);
	(tb->neander__DOT__ACC == expected) ? puts(GRN "NOT Passed!") : printf(RED "NOT Failed! Was %d but expected %d\n", tb->neander__DOT__ACC, expected);
}

void test_jmp(Vneander *tb) {
	puts(YEL "\nNow testing JMP..." RESET);
	reset(tb);
	uint8_t test_val = rand();
	uint8_t addr = 0;
    tb->neander__DOT__memory[addr++] = OP_JMP;
	tb->neander__DOT__memory[addr++] = 128;

	tb->neander__DOT__memory[128] = OP_HLT;

	run_to_completion(tb);
	(tb->neander__DOT__PC__DOT__internal_PC == 129) ? puts(GRN "JMP Passed!") : printf(RED "JMP Failed! PC was %d but expected %d\n", tb->neander__DOT__PC__DOT__internal_PC, 129);
}

void test_jn(Vneander *tb) {
	puts(YEL "\nNow testing JN..." RESET);
	reset(tb);
	uint8_t test_val = rand();
	uint8_t addr = 0;
	tb->neander__DOT__memory[addr++] = OP_LDA;
	tb->neander__DOT__memory[addr++] = 128;
    tb->neander__DOT__memory[addr++] = OP_JN;
	tb->neander__DOT__memory[addr++] = 129;
	tb->neander__DOT__memory[addr++] = OP_HLT;

	tb->neander__DOT__memory[128] = 5;
	tb->neander__DOT__memory[129] = OP_HLT;

	run_to_completion(tb);
	(tb->neander__DOT__PC__DOT__internal_PC == 5) ? puts(GRN "JN Passed (positive)!") : printf(RED "JN Failed! PC was %d but expected %d\n", tb->neander__DOT__PC__DOT__internal_PC, 5);

	puts(RESET);
	reset(tb);
	tb->neander__DOT__memory[128] = -9;
	run_to_completion(tb);
	(tb->neander__DOT__PC__DOT__internal_PC == 130) ? puts(GRN "JN Passed (negative)!") : printf(RED "JN Failed! PC was %d but expected %d\n", tb->neander__DOT__PC__DOT__internal_PC, 130);
}

void test_jz(Vneander *tb) {
	puts(YEL "\nNow testing JZ..." RESET);
	reset(tb);
	uint8_t test_val = rand();
	uint8_t addr = 0;
	tb->neander__DOT__memory[addr++] = OP_LDA;
	tb->neander__DOT__memory[addr++] = 128;
    tb->neander__DOT__memory[addr++] = OP_JZ;
	tb->neander__DOT__memory[addr++] = 129;
	tb->neander__DOT__memory[addr++] = OP_HLT;

	tb->neander__DOT__memory[128] = 5;
	tb->neander__DOT__memory[129] = OP_HLT;

	run_to_completion(tb);
	(tb->neander__DOT__PC__DOT__internal_PC == 5) ? puts(GRN "JZ Passed (non zero)!") : printf(RED "JZ Failed! PC was %d but expected %d\n", tb->neander__DOT__PC__DOT__internal_PC, 5);

	puts(RESET);
	reset(tb);
	tb->neander__DOT__memory[128] = 0;
	run_to_completion(tb);
	(tb->neander__DOT__PC__DOT__internal_PC == 130) ? puts(GRN "JZ Passed (zero)!") : printf(RED "JZ Failed! PC was %d but expected %d\n", tb->neander__DOT__PC__DOT__internal_PC, 130);
}

int	main(int argc, char **argv) {
	//const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
	Verilated::traceEverOn(true);

	Verilated::commandArgs(argc, argv);

	// Create an instance of our module under test
	Vneander *top = new Vneander;

	top->trace(tfp, 99);
	tfp->open("trace.vcd");
	
	test_lda(top);
	test_sta(top);
	test_add(top);
	test_and(top);
	test_or(top);
	test_not(top);

	test_jmp(top);
	test_jn(top);
	test_jz(top);

	puts(RESET);

	tfp->close();
	
	printf("\n\nSimulation complete\n");
}
