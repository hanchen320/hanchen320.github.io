module key_inverter(
    input clk,rst,key,
    output reg key_o
    );
    always @(posedge clk)
    begin
        if(rst)
            key_o<=0;
        else
            if(key)
                key_o<=~key_o;   
    end
endmodule