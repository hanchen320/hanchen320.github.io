-- This file is not intended for synthesis, is is present so that simulators
-- see a complete view of the system.

-- You may use the entity declaration from this file as the basis for a
-- component declaration in a VHDL file instantiating this entity.

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;

entity alt_dspbuilder_product is
	generic (
		USEDEDICATEDMULT : natural := 0;
		SIGNED : natural := 0;
		LPM : natural := 0;
		MASKVALUE : string := "1";
		PIPELINE : natural := 0;
		WIDTH_B : natural := 8;
		WIDTH_A : natural := 8
	);
	port (
		result : out std_logic_vector(width_a + width_b-1 downto 0);
		aclr : in std_logic := '0';
		datab : in std_logic_vector(width_b-1 downto 0) := (others=>'0');
		dataa : in std_logic_vector(width_a-1 downto 0) := (others=>'0');
		user_aclr : in std_logic := '0';
		ena : in std_logic := '0';
		clock : in std_logic := '0'
	);
end entity alt_dspbuilder_product;

architecture rtl of alt_dspbuilder_product is

component alt_dspbuilder_product_GNO6FDVQSR is
	generic (
		USEDEDICATEDMULT : natural := 1;
		SIGNED : natural := 1;
		LPM : natural := 0;
		MASKVALUE : string := "1";
		PIPELINE : natural := 0;
		WIDTH_B : natural := 2;
		WIDTH_A : natural := 16
	);
	port (
		aclr : in std_logic := '0';
		clock : in std_logic := '0';
		dataa : in std_logic_vector(16-1 downto 0) := (others=>'0');
		datab : in std_logic_vector(2-1 downto 0) := (others=>'0');
		ena : in std_logic := '0';
		result : out std_logic_vector(18-1 downto 0);
		user_aclr : in std_logic := '0'
	);
end component alt_dspbuilder_product_GNO6FDVQSR;

begin

alt_dspbuilder_product_GNO6FDVQSR_0: if ((USEDEDICATEDMULT = 1) and (SIGNED = 1) and (LPM = 0) and (MASKVALUE = "1") and (PIPELINE = 0) and (WIDTH_B = 2) and (WIDTH_A = 16)) generate
	inst_alt_dspbuilder_product_GNO6FDVQSR_0: alt_dspbuilder_product_GNO6FDVQSR
		generic map(USEDEDICATEDMULT => 1, SIGNED => 1, LPM => 0, MASKVALUE => "1", PIPELINE => 0, WIDTH_B => 2, WIDTH_A => 16)
		port map(aclr => aclr, clock => clock, dataa => dataa, datab => datab, ena => ena, result => result, user_aclr => user_aclr);
end generate;

assert not (((USEDEDICATEDMULT = 1) and (SIGNED = 1) and (LPM = 0) and (MASKVALUE = "1") and (PIPELINE = 0) and (WIDTH_B = 2) and (WIDTH_A = 16)))
	report "Please run generate again" severity error;

end architecture rtl;

