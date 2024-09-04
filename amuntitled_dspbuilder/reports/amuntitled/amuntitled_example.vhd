library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;
entity amuntitled_example is  
	port(
		StreamMod : out STD_LOGIC_VECTOR(18 downto 0);
		Noise : in STD_LOGIC;
		Sinln2 : out STD_LOGIC_VECTOR(15 downto 0);
		aclr : in STD_LOGIC;
		SinDelay : out STD_LOGIC_VECTOR(15 downto 0);
		Sinln : in STD_LOGIC_VECTOR(15 downto 0);
		Clock : in STD_LOGIC;
		StreamBit : out STD_LOGIC); 
end entity;
architecture rtl of amuntitled_example is
component amuntitled
	  
	port(
		StreamMod : out STD_LOGIC_VECTOR(18 downto 0);
		Noise : in STD_LOGIC;
		Sinln2 : out STD_LOGIC_VECTOR(15 downto 0);
		aclr : in STD_LOGIC;
		SinDelay : out STD_LOGIC_VECTOR(15 downto 0);
		Sinln : in STD_LOGIC_VECTOR(15 downto 0);
		Clock : in STD_LOGIC;
		StreamBit : out STD_LOGIC); 
end component;
begin
	amuntitled_instance : 
		component amuntitled
			port map(
				StreamMod => StreamMod,
				Noise => Noise,
				Sinln2 => Sinln2,
				aclr => aclr,
				SinDelay => SinDelay,
				Sinln => Sinln,
				Clock => Clock,
				StreamBit => StreamBit);
end architecture rtl;
