library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;
entity tb_amuntitled_example is   
end entity;
architecture rtl of tb_amuntitled_example is
component tb_amuntitled
	   
end component;
begin
	tb_amuntitled_instance : 
		component tb_amuntitled
			port map();
end architecture rtl;
