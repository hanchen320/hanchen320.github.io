module Count(
    input clk,rst,en,
    output [23:0]count
    );
    wire [7:0] count1,count2,count3;
    wire eno1,eno2,eno3;
    BCDcount59 u_BCDcount59_1(clk,rst,en&eno2&eno3,count1,eno1);
    BCDcount59 u_BCDcount59_2(clk,rst,en&eno3,count2,eno2);
    BCDcount99 u_BCDcount99(clk,rst,en,count3,eno3);
    assign count={count1,count2,count3};
endmodule