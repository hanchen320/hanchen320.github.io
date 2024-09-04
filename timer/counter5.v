module BCDcount5(
    input clk,rst,en,
    output reg [3:0]count,
    output eno
);
always @(posedge clk)
    begin
        if(rst)
            count<=0;
        else if(en)begin
            if(count==5)
                count<=0;
            else
                count<=count+1;
        end
        else
            count<=count;
    end
assign eno=(count==5);
endmodule