//*******************************************************************
//Author: Yejoong Kim
//Description: SRAM_test_0
//             test the basic functionality of SRAM
//*******************************************************************
#include "PREv12.h"
#include "mbus.h"

#define PRC_ADDR    0x1
#define FLS_ADDR    0x4

//********************************************************************
// Global Variables
//********************************************************************
volatile uint32_t enumerated;
volatile uint32_t num_cyc;

//*******************************************************************
// INTERRUPT HANDLERS
//*******************************************************************
void init_interrupt (void) {
  *NVIC_ICPR = 0x1FFFF; //Clear All Pending Interrupts
  *NVIC_ISER = 0x0; //0x18000: Enable only GPIO
}

void handler_ext_int_0(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_1(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_2(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_3(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_4(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_5(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_6(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_7(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_8(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_9(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_10(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_11(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_12(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_13(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_14(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_15(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_16(void) __attribute__ ((interrupt ("IRQ")));

void handler_ext_int_0(void)  {/*TIMER32*/  *NVIC_ICPR = (0x1 <<  0); }
void handler_ext_int_1(void)  {/*TIMER16*/  *NVIC_ICPR = (0x1 <<  1); }
void handler_ext_int_2(void)  {/*REG0*/     *NVIC_ICPR = (0x1 <<  2); }
void handler_ext_int_3(void)  {/*REG1*/     *NVIC_ICPR = (0x1 <<  3); }
void handler_ext_int_4(void)  {/*REG2*/     *NVIC_ICPR = (0x1 <<  4); }
void handler_ext_int_5(void)  {/*REG3*/     *NVIC_ICPR = (0x1 <<  5); }
void handler_ext_int_6(void)  {/*REG4*/     *NVIC_ICPR = (0x1 <<  6); }
void handler_ext_int_7(void)  {/*REG5*/     *NVIC_ICPR = (0x1 <<  7); }
void handler_ext_int_8(void)  {/*REG6*/     *NVIC_ICPR = (0x1 <<  8); }
void handler_ext_int_9(void)  {/*REG7*/     *NVIC_ICPR = (0x1 <<  9); }
void handler_ext_int_10(void) {/*MEM_WR*/   *NVIC_ICPR = (0x1 << 10); }
void handler_ext_int_11(void) {/*MBUS_RX*/  *NVIC_ICPR = (0x1 << 11); }
void handler_ext_int_12(void) {/*MBUS_TX*/  *NVIC_ICPR = (0x1 << 12); }
void handler_ext_int_13(void) {/*MBUS_FWD*/ *NVIC_ICPR = (0x1 << 13); }
void handler_ext_int_14(void) {/*GOCEP*/    *NVIC_ICPR = (0x1 << 14); }
void handler_ext_int_15(void) {/*SPI*/      *NVIC_ICPR = (0x1 << 15); }
void handler_ext_int_16(void) {/*GPIO*/     *NVIC_ICPR = (0x1 << 16); }

//*******************************************************************
// USER FUNCTIONS
//*******************************************************************
void initialization (void) {

    enumerated = 0xDEADBEEF;
    num_cyc = 0;

    //Set Halt
    set_halt_until_mbus_rx();
    //set_halt_until_mbus_tx();
    //set_halt_disable();
//	write_regfile(REG_IRQ_CTRL, 0x0001A000);

	//delay(1000);

	//mbus_write_message32(0xBB, 0xBBBBBBBB);
	//delay(1000);

    //set_halt_until_mbus_tx();

    //Enumeration
    mbus_enumerate(FLS_ADDR);

//	delay(1000);


    //Set Halt
    set_halt_until_mbus_tx();
//	delay(1000);
}

void cycle0(void) { mbus_write_message32(0xA0, num_cyc); delay(1000);}
void cycle1(void) { mbus_write_message32(0xA1, num_cyc); delay(1000);}
void cycle2(void) { mbus_write_message32(0xA2, num_cyc); delay(1000);}
void cycle3(void) { mbus_write_message32(0xA3, num_cyc); delay(1000);}
void cycle4(void) { mbus_write_message32(0xA4, num_cyc); delay(1000);}
void cycle5(void) { mbus_write_message32(0xA5, num_cyc); delay(1000);}
void cycle6(void) { mbus_write_message32(0xA6, num_cyc); delay(1000);}
void cycle7(void) { mbus_write_message32(0xA7, num_cyc); delay(1000);}
void cycle8(void) { mbus_write_message32(0xA8, num_cyc); delay(1000);}
void cycle9(void) { mbus_write_message32(0xA9, num_cyc); delay(1000);}
void cycle10(void) { mbus_write_message32(0xAA, num_cyc); delay(1000);}
void cycle11(void) { mbus_write_message32(0xAB, num_cyc); delay(1000);}
void cycle12(void) { mbus_write_message32(0xAC, num_cyc); delay(1000);}
void cycle13(void) { mbus_write_message32(0xAD, num_cyc); delay(1000);}
void cycle14(void) { mbus_write_message32(0xAE, num_cyc); delay(1000);}
void cycle15(void) { mbus_write_message32(0xAF, num_cyc); delay(1000);}

//********************************************************************
// MAIN function starts here             
//********************************************************************

int main() {
	uint32_t i;

    //Initialize Interrupts
    init_interrupt();
  
    // Initialization Sequence
    if (enumerated != 0xDEADBEEF) { 
        initialization(); // Enumeration.
    }

	for (i=0; i<100; i++) {
		if (num_cyc == 0){
			delay(1000);
			break;
		}
		else if ((i % 16) == 0) cycle0();
		else if ((i % 16) == 1) cycle1();
		else if ((i % 16) == 2) cycle2();
		else if ((i % 16) == 3) cycle3();
		else if ((i % 16) == 4) cycle4();
		else if ((i % 16) == 5) cycle5();
		else if ((i % 16) == 6) cycle6();
		else if ((i % 16) == 7) cycle7();
		else if ((i % 16) == 8) cycle8();
		else if ((i % 16) == 9) cycle9();
		else if ((i % 16) == 10) cycle10();
		else if ((i % 16) == 11) cycle11();
		else if ((i % 16) == 12) cycle12();
		else if ((i % 16) == 13) cycle13();
		else if ((i % 16) == 14) cycle14();
		else if ((i % 16) == 15) cycle15();

		num_cyc++;
		delay(1000);
	}

	if (num_cyc != 999) {
		num_cyc++;
    		mbus_write_message32(0xDD, 0x0EA7F00D);
		delay(1000);
		set_wakeup_timer (2, 1, 1);
    		mbus_sleep_all();
	}
	else { 
		mbus_write_message32(0xDD, 0x0EA70EA7);
		delay(1000);
    		while(1);
	}

    return 1;
}
