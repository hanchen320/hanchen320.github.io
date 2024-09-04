library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

library altera;
use altera.alt_dspbuilder_package.all;

library lpm;
use lpm.lpm_components.all;
entity alt_dspbuilder_bus_build_GNGCK3JP43 is
	generic		( 			width : natural := 2);

	port(
		output : out std_logic_vector(1 downto 0);
		in0 : in std_logic;
		in1 : in std_logic);		
end entity;



architecture rtl of alt_dspbuilder_bus_build_GNGCK3JP43 is 
Begin

	output(0) <= in0;
	output(1) <= in1;
				
end architecture;