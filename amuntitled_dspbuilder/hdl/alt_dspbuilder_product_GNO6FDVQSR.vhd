library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

library altera;
use altera.alt_dspbuilder_package.all;

library lpm;
use lpm.lpm_components.all;
entity alt_dspbuilder_product_GNO6FDVQSR is
	generic		( 			UseDedicatedMult : natural := 1;
			Signed : natural := 1;
			lpm : natural := 0;
			MaskValue : string := "1";
			pipeline : natural := 0;
			width_b : natural := 2;
			width_a : natural := 16);

	port(
		aclr : in std_logic;
		clock : in std_logic;
		dataa : in std_logic_vector((width_a)-1 downto 0);
		datab : in std_logic_vector((width_b)-1 downto 0);
		ena : in std_logic;
		result : out std_logic_vector((width_a + width_b)-1 downto 0);
		user_aclr : in std_logic);		
end entity;

architecture rtl of alt_dspbuilder_product_GNO6FDVQSR is 

signal signed_a: STD_LOGIC_VECTOR(width_a downto 0);
signal signed_b: STD_LOGIC_VECTOR(width_b downto 0);
signal signed_r: STD_LOGIC_VECTOR(width_a + width_b + 1 downto 0);

Begin

-- Extend data ports to one extra bit when the type is unsigned
signed_a(width_a) <= '0';
signed_b(width_b) <= '0';
signed_a(width_a-1 downto 0) <= dataa(width_a-1 downto 0);
signed_b(width_b-1 downto 0) <= datab(width_b-1 downto 0);

-- Product Operator - Simulink Block "Product1"
Product1i : alt_dspbuilder_AltiMult generic map (
				PIPELINE		=>	0,
				one_input		=>	0,
				lpm      		=>	0,				
				lpm_hint		=>	 "DEDICATED_MULTIPLIER_CIRCUITRY=YES,MAXIMIZE_SPEED=1" ,
				cst_val 		=>	"00000000",
				SequenceLength  => 1,
				SequenceValue   => "1",				
				LPM_WIDTHA		=>	16,
				LPM_WIDTHB		=>	2,
				dspb_widthr		=>	18)
		port map (
				DATAA		=>	signed_a(width_a-1 downto 0),
				DATAB		=>	signed_b(width_b-1 downto 0),
				clock		=>	clock,
				ena   		=>	ena,
				aclr   		=>	aclr,
				user_aclr	=>	user_aclr,
				part_sclr	=>	'0',
				result		=>	signed_r(width_a + width_b - 1 downto 0));

result(width_a + width_b - 1 downto 0) <= signed_r(width_a + width_b - 1 downto 0);

end architecture;				
