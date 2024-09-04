-- This file is not intended for synthesis, is is present so that simulators
-- see a complete view of the system.

-- You may use the entity declaration from this file as the basis for a
-- component declaration in a VHDL file instantiating this entity.

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;

entity amuntitled is
	port (
		Clock : in std_logic;
		Noise : in std_logic;
		SinDelay : out std_logic_vector(16-1 downto 0);
		Sinln : in std_logic_vector(16-1 downto 0);
		Sinln2 : out std_logic_vector(16-1 downto 0);
		StreamBit : out std_logic;
		StreamMod : out std_logic_vector(19-1 downto 0);
		aclr : in std_logic
	);
end entity amuntitled;

architecture rtl of amuntitled is

component amuntitled_GN is
	port (
		Clock : in std_logic;
		Noise : in std_logic;
		SinDelay : out std_logic_vector(16-1 downto 0);
		Sinln : in std_logic_vector(16-1 downto 0);
		Sinln2 : out std_logic_vector(16-1 downto 0);
		StreamBit : out std_logic;
		StreamMod : out std_logic_vector(19-1 downto 0);
		aclr : in std_logic
	);
end component amuntitled_GN;

begin

amuntitled_GN_0: if true generate
	inst_amuntitled_GN_0: amuntitled_GN
		port map(Clock => Clock, Noise => Noise, SinDelay => SinDelay, Sinln => Sinln, Sinln2 => Sinln2, StreamBit => StreamBit, StreamMod => StreamMod, aclr => aclr);
end generate;

end architecture rtl;

