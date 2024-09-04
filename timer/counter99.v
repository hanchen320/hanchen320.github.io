module BCDcount99(
    input clk,rst,en,
    output [7:0]count,
    output eno
    );
    wire [3:0] count1,count2;
    wire eno2,eno1;
    BCDcount9 u_BCDcount9_1(clk,rst,eno2,count1,eno1);
    BCDcount9 u_BCDcount9_2(clk,rst,en,count2,eno2);
    assign count={count1,count2};
    assign eno=(count==16'h99);
endmodule