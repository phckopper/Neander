module neander (
    i_clk,
    i_rst
);

    localparam OP_NOP = 8'b00000000;
    localparam OP_STA = 8'b00000001;
    localparam OP_LDA = 8'b00000010;
    localparam OP_ADD = 8'b00000011;
    localparam OP_OR  = 8'b00000100;
    localparam OP_AND = 8'b00000101;
    localparam OP_NOT = 8'b00000110;

    localparam OP_JMP = 8'b00001000;
    localparam OP_JN  = 8'b00001001;
    localparam OP_JZ  = 8'b00001010;
    localparam OP_HLT = 8'b00001111;

    localparam ULA_ADD = 3'b011;
    localparam ULA_OR  = 3'b100;
    localparam ULA_AND = 3'b101;
    localparam ULA_NOT = 3'b110;

    input i_clk;
    input i_rst;

    reg [7:0] ACC;
    reg [2:0] ULA_SEL;
    wire [7:0] ULA_OUT;

    wire [7:0] ULA_Y;
    wire ULA_Z;
    wire ULA_N;

    reg cargaAC;
    reg cargaNZ;
    reg cargaREM;
    reg cargaRDM;
    reg cargaRI;
    reg memRead;
    reg memWrite;

    reg [7:0] RI;
    reg [7:0] REM;
    reg [7:0] RDM;
    reg SEL;
    reg N;
    reg Z;

    reg [2:0] STATE;

    assign ULA_Y = RDM;


    // /* verilator public */
    ULA ula(.i_A(ACC), .i_B(ULA_Y), .i_SEL(ULA_SEL), .o_OUT(ULA_OUT), .o_ZERO(ULA_Z), .o_NEG(ULA_N));


    reg [7:0] valorPC;
    wire [7:0] cargaPC_val;
    reg cargaPC;
    reg incrementaPC;

    assign cargaPC_val = RDM;

    counter PC(.i_clk(i_clk), .i_rst(i_rst), .i_preload(cargaPC_val), .i_preload_s(cargaPC), .i_inc(incrementaPC), .o_PC(valorPC));


    reg [7:0] memory [0:255];

    always @(posedge i_clk ) begin
        if (memWrite) begin
            memory[REM] <= RDM;
        end
    end

    always @(posedge i_clk ) begin
        if(memRead) begin
            RDM <= memory[REM];
        end
    end

    always @(posedge i_clk) begin
        if(cargaAC) begin
            ACC <= ULA_OUT;
        end

        if(cargaNZ) begin
            Z <= ULA_Z;
            N <= ULA_N;
        end

        if(SEL) begin
            if (cargaREM) begin
                REM <= RDM;
            end
        end else begin
            if (cargaREM) begin
                REM <= valorPC;
            end
        end

        if (cargaRDM) begin
            RDM <= ACC;
        end

        if (cargaRI) begin
            RI <= RDM;
        end

        case (STATE)
            3'd0: begin
                STATE <= 1;
            end
            3'd1: begin
                STATE <= 2;
            end
            3'd2: begin
                STATE <= 3;
            end
            3'd3: begin
                if(RI == OP_NOT) begin
                    STATE <= 0;
                end else begin
                    if(((RI == OP_JN) && ~N) | ((RI == OP_JZ) &&  ~Z)) begin
                        STATE <= 0;
                    end else begin
                        STATE <= 4;
                    end
                end
            end
            3'd4: begin
                STATE <= 5;
            end
            3'd5: begin
                if ((RI == OP_JMP) | (RI == OP_JN) | (RI == OP_JZ)) begin
                    STATE <= 0;
                end else begin
                    STATE <= 6;
                end
            end
            3'd6: begin
                STATE <= 7;
            end
            3'd7: begin
                STATE <= 0;
            end
        endcase
    end

    always @(STATE) begin
        case (STATE)
            3'd0: begin
                incrementaPC = 0;
                cargaAC = 0;
                cargaNZ = 0;
                cargaPC = 0;
                SEL = 0;
                memWrite = 0;
                memRead = 0;
                cargaREM = 1;
                //STATE <= 1;
            end
            3'd1: begin
                memRead = 1;
                incrementaPC = 1;
                cargaREM = 0;
                //STATE <= 2;
            end
            3'd2: begin
                memRead = 0;
                incrementaPC = 0;
                cargaRI = 1;
                //STATE <= 3;
            end
            3'd3: begin
                cargaRI = 0;
                if(RI == OP_NOT) begin
                    ULA_SEL = ULA_NOT;
                    cargaAC = 1;
                    cargaNZ = 1;
                    //STATE <= 0;
                end else begin
                    if(((RI == OP_JN) && ~N) | ((RI == OP_JZ) &&  ~Z)) begin
                        incrementaPC = 1;
                        //STATE <= 0;
                    end else begin
                        SEL = 0;
                        cargaREM = 1;
                        //STATE <= 4;
                    end
                end
            end
            3'd4: begin
                cargaREM = 0;
                memRead = 1;
                if ((RI == OP_JMP) | (RI == OP_JN) | (RI == OP_JZ)) begin
                    incrementaPC = 0;
                end else begin
                    incrementaPC = 1;
                end
                //STATE <= 5;
            end
            3'd5: begin
                incrementaPC = 0;
                if((RI == OP_JMP) | (RI == OP_JN) | (RI == OP_JZ)) begin
                    cargaPC = 1;
                    //STATE <= 0;
                end else begin
                    SEL = 1;
                    cargaREM = 1;
                    //STATE <= 6;
                end
            end
            3'd6: begin
                cargaREM = 0;
                if(RI == OP_STA) begin
                    cargaRDM = 1;
                end else begin
                    memRead = 1;
                end
                //STATE <= 7;
            end
            3'd7: begin
                cargaRDM = 0;
                if(RI == OP_STA) begin
                    memWrite = 1;
                end else begin
                    cargaAC = 1;
                    cargaNZ = 1;
                    ULA_SEL = RI[2:0];
                end

                //STATE <= 0;
            end
        endcase
    end


endmodule