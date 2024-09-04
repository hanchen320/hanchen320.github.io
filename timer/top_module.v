module timer(
    input clk,rst,key,
    output [6:0] seg_1,
    output [6:0] seg_2,
    output [6:0] seg_3,
    output [6:0] seg_4,
    output [6:0] seg_5,
    output [6:0] seg_6
    );
    wire clk_10;
    wire key_done;
    wire en;
    wire [23:0] count;
    clk10 u_clk10(clk,rst,clk_10);//调用时钟分频器
    key_debounce u_key_debounce(clk,rst,key,key_done);//调用消抖
    key_inverter u_key_inverter(clk,rst,key_done,en);//调用取反
    Count u_Count(clk_10,rst,en,count);//调用计数器主体
    num_7seg u_num_7seg_1(count[23:20],seg_1);//调用数码管显示全部数据
    num_7seg u_num_7seg_2(count[19:16],seg_2);
    num_7seg u_num_7seg_3(count[15:12],seg_3);
    num_7seg u_num_7seg_4(count[11:8],seg_4);
    num_7seg u_num_7seg_5(count[7:4],seg_5);
    num_7seg u_num_7seg_6(count[3:0],seg_6);   
endmodule