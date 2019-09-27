/*
 /* LED_BarGraph.h
 *
 *  Created on: Sep 10, 2019
 *      Author: jaysonb
 *
 *
 *  Created on: Aug 21, 2019
 *      Author: jeanchri
 */
//#include "MikroBus.c"




/************************** Constant Definitions ******************************/
//SPi
#define SPI_DEVICE_ID       XPAR_SPI_0_DEVICE_ID
#define BASE_ADDR			XPAR_SPI_0_BASEADDR
#define SS_SPI				XPAR_SPI_0_NUM_SS_BITS
#define DTR_SPI				XPAR_SPI_0_NUM_TRANSFER_BITS

//Timer
#define TIMER_DEVICE_ID		XPAR_MIKROBUS_AXI_TIMER_0_DEVICE_ID
#define TIMER_BASE			XPAR_MIKROBUS_AXI_TIMER_0_BASEADDR
#define TIMER_COUNTER_0		0
#define DELAY				100000000	//<-----adjust the Time as you like

//GPIO
#define GPIO_DEVICE_ID_LED_LED  	XPAR_GPIO_2_DEVICE_ID
#define GPIO_DEVICE_ID_MIKROBUS		XPAR_GPIO_0_DEVICE_ID
#define LED_CHANNEL 1
#define MIKRO_CHANNEL 1


//PWM
#define PWM_PERIOD              500000000    /* PWM period in (500 ms) */
#define TMRCTR_0                0            /* Timer 0 ID */
#define TMRCTR_1                1            /* Timer 1 ID */
#define CYCLE_PER_DUTYCYCLE     10           /* Clock cycles per duty cycle */
#define MAX_DUTYCYCLE           100          /* Max duty cycle */
#define DUTYCYCLE_DIVISOR       4            /* Duty cycle Divisor */
#define WAIT_COUNT              PWM_PERIOD   /* Interrupt wait counter */

//Intc
#define INTC_DEVICE_ID          XPAR_INTC_0_DEVICE_ID
#define INTC_HANDLER            XIntc_InterruptHandler

//******************* End of Header File ************************



