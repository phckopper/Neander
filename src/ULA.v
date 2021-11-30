// Unidadade Lógica Aritmética

// 0000	NOP	Nenhuma operação
// 0001	STA end	Armazena acumulador no endereço “end” da memória
// 0010	LDA end	Carrega o acumulador com o conteúdo do endereço “end” da memória
// 0011	ADD end	Soma o conteúdo do endereço “end” da memória ao acumulador
// 0100	OR end	Efetua operação lógica “OU” do conteúdo do endereço “end” da memória ao acumulador
// 0101	AND end	Efetua operação lógica “E” do conteúdo do endereço “end” da memória ao acumulador
// 0110	NOT	Inverte todos os bits do acumulador

// Pegamos os 3 LSBs e utilizamos para o mux da ULA, simplificando o decodificador de instrução

module ULA (
    i_A, i_B, i_SEL, o_OUT, o_ZERO, o_NEG
);

    localparam ADD = 3'b011;
    localparam OR  = 3'b100;
    localparam AND = 3'b101;
    localparam NOT = 3'b110;

    input wire [7:0] i_A;
    input wire [7:0] i_B;
    input wire [2:0] i_SEL;

    output reg [7:0] o_OUT;
    output reg o_ZERO;
    output reg o_NEG;
    
    always @(i_A, i_B, i_SEL) begin
        case (i_SEL)
            ADD: o_OUT = i_A + i_B; // ADD
            OR:  o_OUT = i_A | i_B; // OR
            AND: o_OUT = i_A & i_B; // AND
            NOT: o_OUT = ~i_A; // NOT

            default: o_OUT = i_B; // ELSE
        endcase

        o_ZERO = o_OUT == 0;
        o_NEG  = o_OUT[7];
    end
endmodule