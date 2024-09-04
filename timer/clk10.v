module clk10(
    input clk,rst,
    output reg clk_o
    );
    reg [3:0]count;
    always @(posedge clk)begin
        if(rst)begin
        count<=0;
        clk_o=0;
        end
        else
        if(count==9)begin
            count<=0;
            clk_o<=~clk_o;
            end
        else
            count<=count+1;
        end
endmodule