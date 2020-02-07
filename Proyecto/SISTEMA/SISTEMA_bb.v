
module SISTEMA (
	clk_clk,
	clk_sdram_clk,
	ldr_external_interface_sclk,
	ldr_external_interface_cs_n,
	ldr_external_interface_dout,
	ldr_external_interface_din,
	pll_locked_export,
	reset_reset_n,
	sdram_wire_addr,
	sdram_wire_ba,
	sdram_wire_cas_n,
	sdram_wire_cke,
	sdram_wire_cs_n,
	sdram_wire_dq,
	sdram_wire_dqm,
	sdram_wire_ras_n,
	sdram_wire_we_n);	

	input		clk_clk;
	output		clk_sdram_clk;
	output		ldr_external_interface_sclk;
	output		ldr_external_interface_cs_n;
	input		ldr_external_interface_dout;
	output		ldr_external_interface_din;
	output		pll_locked_export;
	input		reset_reset_n;
	output	[12:0]	sdram_wire_addr;
	output	[1:0]	sdram_wire_ba;
	output		sdram_wire_cas_n;
	output		sdram_wire_cke;
	output		sdram_wire_cs_n;
	inout	[15:0]	sdram_wire_dq;
	output	[1:0]	sdram_wire_dqm;
	output		sdram_wire_ras_n;
	output		sdram_wire_we_n;
endmodule
