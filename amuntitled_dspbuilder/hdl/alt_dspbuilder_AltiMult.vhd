--------------------------------------------------------------------------------------------
-- DSP Builder (Version 9.1)
-- Quartus II development tool and MATLAB/Simulink Interface
-- 
-- Legal Notice: © 2001 Altera Corporation. All rights reserved.  Your use of Altera 
-- Corporation's design tools, logic functions and other software and tools, and its 
-- AMPP partner logic functions, and any output files any of the foregoing 
-- (including device programming or simulation files), and any associated 
-- documentation or information are expressly subject to the terms and conditions 
-- of the Altera Program License Subscription Agreement, Altera MegaCore Function 
-- License Agreement, or other applicable license agreement, including, without 
-- limitation, that your use is for the sole purpose of programming logic devices 
-- manufactured by Altera and sold by Altera or its authorized distributors.  
-- Please refer to the applicable agreement for further details.
--------------------------------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;

library LPM;
use LPM.LPM_COMPONENTS.all;

library altera;
use altera.alt_dspbuilder_package.all;


library lpm;
use lpm.lpm_components.all;

entity alt_dspbuilder_AltiMult is
		generic (    
				lpm_widtha		:	positive 	:=8 	;
				lpm_widthb		:	positive 	:=8 	;
				dspb_widthr		:	positive 	:=16 	;
				lpm_hint		:	string 		:= "UNUSED";
				cst_val			:	std_logic_vector 	:= "01010101";
				one_input		:	integer 	:=0 	;
				pipeline		: 	natural		:=2		;
				SequenceLength	:	positive 	:=1	;
				SequenceValue	: 	std_logic_vector 	:="1"	;
				lpm				:	natural 	:=0);
					
		port 	( 
				dataa		: 	in std_logic_vector(lpm_widtha-1 downto 0);
				datab		: 	in std_logic_vector(lpm_widthb-1 downto 0) :=(others=>'0');
				clock		: 	in std_logic :='0';
				ena			: 	in std_logic :='1';
				aclr		: 	in std_logic :='0';
				user_aclr	: 	in std_logic :='0';
				part_sclr	: 	in std_logic :='0';
				result		: 	out std_logic_vector(dspb_widthr-1 downto 0)
				);

end alt_dspbuilder_AltiMult;

architecture AltMult_SYNTH of alt_dspbuilder_AltiMult is

	function  GetPipeInt(dd:integer) return integer is
		variable res : integer ;
		begin
			if (dd>0) then
				res := dd-1;
			else
				res :=dd;
			end if;
			return res; 
		end ;	

	constant pipeint 	: natural := GetPipeInt(pipeline);
	
	signal resdtb	: std_logic_vector(lpm_widtha+lpm_widthb-1 downto 0);
			
	signal delaydtb : STD_LOGIC_2DSPBUILDER(ToNatural(pipeline-1) downto 0 , lpm_widtha+lpm_widthb-1 downto 0);
	signal preresdtb : std_logic_vector(lpm_widtha+lpm_widthb-1 downto 0);
	
	signal seqenable	: std_logic ;
	signal enadff		: std_logic ;

	signal dataaint		: 	std_logic_vector(lpm_widtha-1 downto 0);
	signal databint		: 	std_logic_vector(lpm_widthb-1 downto 0);

	signal aclr_i : std_logic;
begin
	aclr_i <= aclr or user_aclr;	

	gsq:if pipeline>0 generate
		gnoseq: if ((SequenceLength=1) and (SequenceValue="1")) generate 
			enadff <= ena;
		end generate gnoseq;	
		gseq: if not ((SequenceLength=1) and (SequenceValue="1")) generate 
			u:alt_dspbuilder_vecseq		generic map 	(SequenceLength=>SequenceLength,SequenceValue=>SequenceValue)
					port map		(clock=>clock, ena=>ena, aclr=>aclr_i, sclr=>part_sclr, yout=> seqenable);	
			enadff <= 	seqenable and ena;
		end generate gseq;
	end generate gsq;

	gnsq:if pipeline=0 generate
		enadff<='0';
	end generate gnsq;

	gcst:if (one_input>0) generate		
		U0:alt_dspbuilder_CST_MULT GENERIC MAP(widthin     => lpm_widtha                                ,   
				                widthcoef   => lpm_widthb                                ,   
				                widthr      => dspb_widthr                                ,   
				                cst         => cst_val                                   ,
				                lpm_hint	=> "INPUT_B_IS_CONSTANT=YES,MAXIMIZE_SPEED=5",
				                pipeline    => pipeline)
			        PORT MAP   (clock	    => clock,
						        aclr	    => aclr_i,
								part_sclr   => part_sclr,
						        ena         => enadff,
						        data	    => dataa,
						        result	    => result);
	end generate gcst;

	gncst: if one_input=0 generate
		genseq :if pipeline>0 generate							
			pab:process(clock,aclr_i)
			begin
				if aclr_i='1' then
					dataaint <= (others=>'0');
					databint <= (others=>'0');
				elsif clock'event and clock='1' then
					if part_sclr='1' then 
						dataaint <= (others=>'0');
						databint <= (others=>'0');
					elsif enadff ='1' then 
						dataaint <= dataa;
						databint <= datab;
					end if ;				
				end if;
			end process pab;
		end generate genseq ;
	
		gennseq :if pipeline=0 generate
				dataaint <= dataa;
				databint <= datab;
		end generate gennseq;
	
		glpm:if lpm>0 generate						
			nopipe:if (pipeint=0) generate
				L:LPM_MULT generic map (LPM_WIDTHA => lpm_widtha,
									LPM_WIDTHB 	=> lpm_widthb,
									LPM_WIDTHS 	=> lpm_widtha+lpm_widthb,
									LPM_WIDTHP 	=> lpm_widtha+lpm_widthb,
									LPM_HINT 	=> LPM_HINT, 
									LPM_REPRESENTATION => "SIGNED")
							port map (dataa	=>dataaint,
									datab	=>databint,
									RESULT	=>resdtb);
			end generate 	nopipe;
	
			pipe:if (pipeint>0) generate
				L:LPM_MULT generic map (LPM_WIDTHA 		=> lpm_widtha,
									LPM_WIDTHB 			=> lpm_widthb,
									LPM_WIDTHS 			=> lpm_widtha+lpm_widthb,
									LPM_WIDTHP 			=> lpm_widtha+lpm_widthb,
									LPM_HINT 			=> LPM_HINT, 
									LPM_pipeline 		=> pipeint,
									LPM_REPRESENTATION => "SIGNED")
							port map (	dataa				=>dataaint,
										datab				=>databint,
										CLOCK 				=> clock,
										clken				=> enadff,
										aclr				=> aclr_i,
										RESULT				=>resdtb);
			end generate pipe;
			
			genr:if dspb_widthr>lpm_widtha+lpm_widthb generate
				RESULT(lpm_widtha+lpm_widthb-1 downto 0) <= resdtb(lpm_widtha+lpm_widthb-1 downto 0);
				genl:for i in lpm_widtha+lpm_widthb to dspb_widthr-1 generate
					RESULT(i) <= resdtb(lpm_widtha+lpm_widthb-1);
				end generate ;
			end generate genr ;
			
			genrr:if not (dspb_widthr>lpm_widtha+lpm_widthb) generate
				RESULT(dspb_widthr-1 downto 0) <= resdtb(dspb_widthr-1 downto 0);
			end generate genrr ;
	
		end generate glpm;
		
		
		gnolpm:if lpm=0 generate		
			nopipe:if (pipeint=0) generate
				resdtb <= dataaint * databint;	
			end generate nopipe;
	
			unpipe:if (pipeint=1) generate
				process(clock,aclr_i)
				begin
					if aclr_i='1' then
						resdtb <= 	(others=>'0');
					elsif clock'event and clock='1' then
						if part_sclr='1' then
							resdtb <= 	(others=>'0');
						elsif enadff = '1' then 
							resdtb <= 	dataaint * databint;
						end if ;
					end if;
				end process;				
			end generate unpipe ;
	
			pipe:if (pipeint>1) generate
				preresdtb <=dataaint * databint;
				process(clock,aclr_i)
				begin					
					if aclr_i='1' then
						for w in 0 to lpm_widtha+lpm_widthb-1 loop
							delaydtb(0,w) <= '0';
							for d in 1 to pipeint-1 loop
								delaydtb(d,w) <= '0';
							end loop;
						end loop;
					elsif clock'event and clock='1' then
						if part_sclr='1' then 
							for w in 0 to lpm_widtha+lpm_widthb-1 loop
								delaydtb(0,w) <= '0';
								for d in 1 to pipeint-1 loop
									delaydtb(d,w) <= '0';
								end loop;
							end loop;
						elsif enadff = '1' then 	
							for w in 0 to lpm_widtha+lpm_widthb-1 loop
								delaydtb(0,w) <= preresdtb(w);
								for d in 1 to pipeint-1 loop
									delaydtb(d,w) <= delaydtb(d-1,w);
								end loop;
							end loop;
						end if;												
					end if;
				end process;				
				grsct:for w in 0 to lpm_widtha+lpm_widthb-1 generate
					resdtb(w) <= delaydtb(pipeint-1,w); 
				end generate;
			end generate pipe;		
				
			gr:if dspb_widthr>lpm_widtha+lpm_widthb generate
				RESULT(lpm_widtha+lpm_widthb-1 downto 0) <= resdtb(lpm_widtha+lpm_widthb-1 downto 0);
				genl:for i in lpm_widtha+lpm_widthb to dspb_widthr-1 generate
					RESULT(i) <= resdtb(lpm_widtha+lpm_widthb-1);
				end generate;
			end generate gr ;
			
			grr:if not (dspb_widthr>lpm_widtha+lpm_widthb) generate
				RESULT(dspb_widthr-1 downto 0) <= resdtb(dspb_widthr-1 downto 0);
			end generate grr;
		end generate gnolpm ;

	
	end generate gncst;
	
	
	
end AltMult_SYNTH;



