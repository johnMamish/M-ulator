/* Mulator - An extensible {ARM} {e,si}mulator
 * Copyright 2011-2012  Pat Pannuto <pat.pannuto@gmail.com>
 *
 * This file is part of Mulator.
 *
 * Mulator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mulator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mulator.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "m3_ctl.h"

#include "memmap.h"

#include "cpu/periph.h"
#include "cpu/core.h"

#include "core/state_sync.h"

// CPU CONF REG'S
static uint32_t m3_ctl_reg_chip_id;
static uint32_t m3_ctl_reg_dma_info;
static uint32_t m3_ctl_reg_goc_ctrl;
static uint32_t m3_ctl_reg_pmu_ctrl;
static uint32_t m3_ctl_reg_wup_ctrl;
static uint32_t m3_ctl_reg_tstamp;

static uint32_t m3_ctl_reg_msg0;
static uint32_t m3_ctl_reg_msg1;
static uint32_t m3_ctl_reg_msg2;
static uint32_t m3_ctl_reg_msg3;
static uint32_t m3_ctl_reg_imsg0;
static uint32_t m3_ctl_reg_imsg1;
static uint32_t m3_ctl_reg_imsg2;
static uint32_t m3_ctl_reg_imsg3;

static void m3_ctl_reset(void) {
	m3_ctl_reg_chip_id = 0;
	m3_ctl_reg_dma_info = 0x02000080;
	//1 010 000 0 -- 10 10 01 1 0 11 0010
	// 1010 0000 --10 1001 1011 0010
	m3_ctl_reg_goc_ctrl = 0xa029b2;
}

static void recv_i2c_message(uint8_t addr, uint32_t length, uint8_t *data) {
	switch (addr) {
		case 0xe0:
			// I2C_CHIP_ID_REG_WR? XXX: Flesh out I2C interface
			// XXX: More details pending from ctrl doc
			if (length != 2)
				CORE_ERR_unpredictable("I2C_CHIP_ID_REG_WR bad length\n");
			SW(&m3_ctl_reg_chip_id, *((uint16_t *) data));
			break;
		case 0xe2:
			// I2C_DMA_INFO_REG_WR?
			if (length != 4)
				CORE_ERR_unpredictable("I2C_DMA_INFO_REG_WR bad length\n");
			SW(&m3_ctl_reg_dma_info, *((uint32_t *) data));
			break;
		case 0xe4:
			// I2C_GOC_CTRL_REG_WR?
			if (length != 4)
				CORE_ERR_unpredictable("I2C_GOC_CTRL_REG_WR bad length\n");
			SW(&m3_ctl_reg_goc_ctrl, *((uint32_t *) data) & 0x00ffffff);
			break;
		default:
			CORE_ERR_unpredictable("M3 CTL recv i2c bad addr\n");
	}
}

static void send_i2c_message(uint8_t addr, uint32_t length, uint8_t *data) {
	INFO("Would send I2C message to %02x of len %d bytes at %p",
			addr, length, data);
	CORE_ERR_not_implemented("send_i2c_message");
}

static void i2c_write(uint32_t addr, uint32_t val) {
	assert((addr & 0xfffff000) == 0xA0000000);
	uint8_t length = (addr >> 10) & 0x3;
	if (length == 0)
		length = 4;
	uint8_t address = (addr >> 2) & 0x7f;
	address <<= 1; // I2C Write, LSB is 0
	assert((addr & 0x3) == 0x0);

	CORE_ERR_not_implemented("Send I2C message");
	send_i2c_message(address, length, (uint8_t *)&val);
}

////////////////////////////////////////////////////////////////////////////////

static void print_m3_ctl_line(void) {
	;
}

static bool cpu_conf_regs_rd(uint32_t addr, uint32_t *val) {
	assert((addr & 0xfffff000) == 0xA0001000);
	switch (addr) {
		case CHIP_ID_REG_RD:
			*val = (uint16_t) SR(&m3_ctl_reg_chip_id);
			return true;
		case DMA_INFO_REG_RD:
			*val = SR(&m3_ctl_reg_dma_info);
			return true;
		case GOC_CTRL_REG_RD:
			*val = SR(&m3_ctl_reg_goc_ctrl) & 0x3fff; //XXX
			return true;
		case MSG_REG0_RD:
		case MSG_REG1_RD:
		case MSG_REG2_RD:
		case MSG_REG3_RD:
		case INT_MSG_REG0_RD:
		case INT_MSG_REG1_RD:
		case INT_MSG_REG2_RD:
		case INT_MSG_REG3_RD:
		case PMU_CTRL_REG_RD:
			INFO("Would read from %p", val);
			CORE_ERR_not_implemented("cpu config regs read");
		default:
			CORE_ERR_unpredictable("Bad CPU Config Reg Read");
	}
}

static void dma_write(uint32_t addr, uint32_t val) {
	assert((addr & 0xFF000000) == 0xA1000000);
	uint8_t target = (addr >> 19) & 0x1f;
	bool write = (addr >> 18) & 0x1;
	assert(0 == ((addr >> 15) & 0x7));
	uint16_t num_words = (addr >> 2) & 0x1fff;
	assert(0 == (addr & 0x3));

	uint16_t target_addr = (val >> 16) & 0xffff;
	uint16_t source_addr = val & 0xffff;

	uint8_t i2c_addr;
	// XXX: Set the X bits for each layer
	INFO("Would write to addres %04x on target layer (silence warn)", target_addr);
	switch (target) {
		case 0x0:
			// DSP CPU: 1001xxx0
			i2c_addr = 0x90;
			break;
		case 0x1:
			// CTL CPU (invalid, cannot send msg to self)
			CORE_ERR_unpredictable("Cannot send I2C to self");
		case 0x2:
			// RF: 1011xxx0
			i2c_addr = 0xb0;
			break;
		case 0x3:
			// IT: 1100xxx0 Imager/Timer (Imager)
			// IT: 1101xxx0 Imager/Timer (Timer)
			CORE_ERR_unpredictable("XXX: Specification ambiguity");
		default:
			if (target & 0x10) {
				// Write arbitrary layer
				i2c_addr = (target & 0xf) << 4;
			} else {
				CORE_ERR_unpredictable("Illegal DMA Write target");
			}
	}

	// The variable sent to us is 'is this a write', but a write means LSB
	// is 0 and a read means LSB is 1, hence the counterintuitive line:
	i2c_addr |= (!write);

	{
		uint32_t buf[num_words];
		int i;
		for (i=0; i<num_words; i++) {
			buf[i] = read_word(source_addr + i*4);
		}

		CORE_ERR_not_implemented("Send I2C Message");
		send_i2c_message(i2c_addr, num_words*4, (uint8_t *)buf);
	}
}

static void cpu_conf_regs_wr(uint32_t addr, uint32_t val) {
	assert((addr & 0xfffffff0) == 0xA2000000);
	switch (addr) {
		case CHIP_ID_REG_WR:
			SW(&m3_ctl_reg_chip_id, (uint16_t) val);
			break;
		case DMA_INFO_REG_WR:
			SW(&m3_ctl_reg_dma_info, val);
			break;
		case GOC_CTRL_REG_WR:
			SW(&m3_ctl_reg_goc_ctrl, val & 0x00ffffff);
			break;
		case PMU_CTRL_REG_WR:
			INFO("Would write %08x (silence warn)", val);
			CORE_ERR_not_implemented("cpu config regs write");
		default:
			CORE_ERR_unpredictable("Bad CPU Config Reg Write");
	}
}

static void pmu_special_wr(uint32_t addr, uint32_t val) {
	assert((addr & 0xfffffff0) & 0xA3000000);
	switch (val) {
		case 0x0:
			CORE_ERR_not_implemented("PMU DIV5 mode override");
		case 0x1:
			CORE_ERR_not_implemented("PMU power-on-reset");
		case 0x2:
			CORE_ERR_not_implemented("Ctrl CPU layer sleep");
		default:
			CORE_ERR_unpredictable("Bad CTRL PMU Special");
	}
}

__attribute__ ((constructor))
void register_led_periph(void) {
	union memmap_fn mem_fn;

	mem_fn.W_fn32 = i2c_write;
	register_memmap("M3 CTL I2C WR", true, 4, mem_fn, I2C_BOT_WR, I2C_TOP_WR);

	mem_fn.R_fn32 = cpu_conf_regs_rd;
	register_memmap("M3 CTL CONF RD", false, 4, mem_fn, MSG_REG0_RD, PMU_CTRL_REG_RD+4);

	mem_fn.W_fn32 = dma_write;
	register_memmap("M3 CTL DMA WR", true, 4, mem_fn, DMA_BOT_WR, DMA_TOP_WR);

	mem_fn.W_fn32 = cpu_conf_regs_wr;
	INFO("%d %x\n", CHIP_ID_REG_WR, CHIP_ID_REG_WR);
	INFO("%d %x\n", PMU_CTRL_REG_WR+4, PMU_CTRL_REG_WR+4);
	register_memmap("M3 CTL CONF WR", true, 4, mem_fn, CHIP_ID_REG_WR, PMU_CTRL_REG_WR+4);

	mem_fn.W_fn32 = pmu_special_wr;
	register_memmap("M3 CTL PMU SPECIAL", true, 1, mem_fn, PMU_SPECIAL, PMU_SPECIAL+1);

	register_periph_printer(print_m3_ctl_line);
}