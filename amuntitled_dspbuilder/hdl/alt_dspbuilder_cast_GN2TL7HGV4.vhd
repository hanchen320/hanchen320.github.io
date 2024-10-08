library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

library altera;
use altera.alt_dspbuilder_package.all;

library lpm;
use lpm.lpm_components.all;
entity alt_dspbuilder_cast_GN2TL7HGV4 is
	generic		( 			round : natural := 0;
			saturate : natural := 0);

	port(
		input : in std_logic_vector(1 downto 0);
		output : out std_logic);		
end entity;



architecture rtl of alt_dspbuilder_cast_GN2TL7HGV4 is 
Begin

-- Output - I/O assignment from Simulink Block  "Output"
Outputi : alt_dspbuilder_SBF generic map(
				width_inl=> 2 ,
				width_inr=> 0,
				width_outl=> 1,
				width_outr=> 0,
				lpm_signed=>  BusIsUnsigned ,
				round=> round,
				satur=> saturate)
		port map (
								xin(1 downto 0)  => input,
																yout(0) => output
				);
				
end architecture;