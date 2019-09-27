/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "sleep.h"
#include "MikroBus.h"


//#define GPIO_DEVICE_ID_LED
//#define GPIO_DEVICE_ID_MIKROBUS

XGpio	Gpio_MikroBus;
XGpio 	Gpio_Led;

int main()
{
	u32 Status;
	init_platform();

    xil_printf("Hello Jayson\n\r");


    // Init LED Driver
    Status = XGpio_Initialize(&Gpio_Led, GPIO_DEVICE_ID_LED);
	if (Status != XST_SUCCESS) {
		xil_printf("LED Gpio Initialization Failed\r\n");
		return XST_FAILURE;
	}

    //Init Mikro Bus Output Driver
    	Status = XGpio_Initialize(&Gpio_MikroBus, GPIO_DEVICE_ID_MIKROBUS);
    	if (Status != XST_SUCCESS) {
    		xil_printf("Gpio Initialization Failed\r\n");
    		return XST_FAILURE;
    	}
    //Set as an Outpus
    	XGpio_SetDataDirection(&Gpio_MikroBus, GPIO_MR_LEDBG_CHANNEL, 0);
    	XGpio_SetDataDirection(&Gpio_Led, LED_CHANNEL, 0);


    while (1) {
   	 XGpio_DiscreteWrite(&Gpio_MikroBus, GPIO_MR_LEDBG_CHANNEL, 0x0);
   	 XGpio_DiscreteWrite(&Gpio_Led, LED_CHANNEL, 0x0);
     xil_printf("MR LOW Active_HIGH\r\n");
   	 sleep(1);

   	 XGpio_DiscreteWrite(&Gpio_MikroBus, GPIO_MR_LEDBG_CHANNEL, 0x1);
   	 XGpio_DiscreteWrite(&Gpio_Led, LED_CHANNEL, 0x1);
     xil_printf("MR HIGH Active_HIGH\r\n");
   	 sleep(1);
    }

    cleanup_platform();
    return 0;
}
