-- This file is not intended for synthesis, is is present so that simulators
-- see a complete view of the system.

-- You may use the entity declaration from this file as the basis for a
-- component declaration in a VHDL file instantiating this entity.

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;

entity alt_dspbuilder_testbench_clock is
	generic (
		SIMULATION_START_CYCLE : natural := 4;
		INITIAL_CLOCK : natural := 1;
		RESET_REGISTER_CASCADE_DEPTH : natural := 0;
		PHASE_DELAY : string := "0 ns";
		PERIOD : string := "20 ns";
		RESET_LATENCY : natural := 0
	);
	port (
		reg_aclr_out : out std_logic;
		clock_out : out std_logic;
		aclr_out : out std_logic;
		tb_aclr : out std_logic
	);
end entity alt_dspbuilder_testbench_clock;

architecture rtl of alt_dspbuilder_testbench_clock is

component alt_dspbuilder_testbench_clock_GNCGUFKHRR is
	generic (
		SIMULATION_START_CYCLE : natural := 4;
		INITIAL_CLOCK : natural := 1;
		RESET_REGISTER_CASCADE_DEPTH : natural := 0;
		PHASE_DELAY : string := "0 fs";
		PERIOD : string := "20 ns";
		RESET_LATENCY : natural := 0
	);
	port (
		aclr_out : out std_logic;
		clock_out : out std_logic;
		reg_aclr_out : out std_logic;
		tb_aclr : out std_logic
	);
end component alt_dspbuilder_testbench_clock_GNCGUFKHRR;

begin

alt_dspbuilder_testbench_clock_GNCGUFKHRR_0: if ((SIMULATION_START_CYCLE = 4) and (INITIAL_CLOCK = 1) and (RESET_REGISTER_CASCADE_DEPTH = 0) and (PHASE_DELAY = "0 fs") and (PERIOD = "20 ns") and (RESET_LATENCY = 0)) generate
	inst_alt_dspbuilder_testbench_clock_GNCGUFKHRR_0: alt_dspbuilder_testbench_clock_GNCGUFKHRR
		generic map(SIMULATION_START_CYCLE => 4, INITIAL_CLOCK => 1, RESET_REGISTER_CASCADE_DEPTH => 0, PHASE_DELAY => "0 fs", PERIOD => "20 ns", RESET_LATENCY => 0)
		port map(aclr_out => aclr_out, clock_out => clock_out, reg_aclr_out => reg_aclr_out, tb_aclr => tb_aclr);
end generate;

assert not (((SIMULATION_START_CYCLE = 4) and (INITIAL_CLOCK = 1) and (RESET_REGISTER_CASCADE_DEPTH = 0) and (PHASE_DELAY = "0 fs") and (PERIOD = "20 ns") and (RESET_LATENCY = 0)))
	report "Please run generate again" severity error;

end architecture rtl;

