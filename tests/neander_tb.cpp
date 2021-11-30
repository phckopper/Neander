////////////////////////////////////////////////////////////////////////////////
//
// Filename: 	helloworld_tb.cpp
//
// Project:	Verilog Tutorial Example file
//
// Purpose:	To demonstrate a Verilog main() program that calls a local
//		serial port co-simulator.
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
//
// Written and distributed by Gisselquist Technology, LLC
//
// This program is hereby granted to the public domain.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
// FITNESS FOR A PARTICULAR PURPOSE.
//
////////////////////////////////////////////////////////////////////////////////
//
//
#include <verilatedos.h>
#include <iostream>
#include <memory>
#include <sys/types.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vneander.h"

#include "utils.cpp"

#define N_CYCLES 50

int	main(int argc, char **argv) {
	//const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
	Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
	Verilated::commandArgs(argc, argv);

	// Create an instance of our module under test
	Vneander *top = new Vneander;

	top->trace(tfp, 99);
	tfp->open("trace.vcd");

	uint8_t addr = 0;
    top->neander__DOT__memory[addr++] = OP_LDA;
	top->neander__DOT__memory[addr++] = 128;
	top->neander__DOT__memory[addr++] = OP_ADD;
	top->neander__DOT__memory[addr++] = 129;
	top->neander__DOT__memory[addr++] = OP_STA;
	top->neander__DOT__memory[addr++] = 130;

	top->neander__DOT__memory[128] = 24;
	top->neander__DOT__memory[129] = 9;

	for (size_t i = 0; i < N_CYCLES; i++)
	{
		tfp->dump(i);
		printf("Cycle [%d]\n", i);
		//dump_mem(top);
		printf("130: %d\n", top->neander__DOT__memory[130]);
		dump_state(top);
		puts("-----");
		tick(top);
	}

	tfp->close();
	
	printf("\n\nSimulation complete\n");
}
