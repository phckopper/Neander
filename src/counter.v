// Neander Program Counter

module counter (
    i_clk,
    i_rst,
    i_preload,
    i_preload_s,
    i_inc,
    
    o_PC
);
    input i_clk;
    input i_rst;
    input [7:0] i_preload;
    input i_preload_s;
    input i_inc;

    output [7:0] o_PC;

    reg [7:0] internal_PC;

    always @(posedge i_clk) begin
        if(!i_rst) begin
            if(i_inc) 
                internal_PC <= internal_PC + 1;
            else
                if (i_preload_s) begin
                    internal_PC <= i_preload;
                end
            
        end
        else
            internal_PC <= 8'b0;
    end

    assign o_PC = internal_PC;
    
endmodule