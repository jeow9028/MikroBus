******************************************
Author: 		Jean-Christophe Owens
USR:			jeow9028
Date:			09/28/2019
Project: 		MikroBus IP
Board:			Arty s7-50
******************************************
Release 1.0	| Revision 1.0
******************************************

Files:
Click_MikroBus_Xilinx_Demo.zip
	-Documentation	| Provides information for xilinx click boards
	-Source		| Provides RTL project and SDK to run
	-README		| Provides Guide to Project

Version 1 FLOW:
	Generate Bistream
	Export Hardware Bitream to Xilinx SDK
	Launch SDK 2019.1
	Import "MikroBus_SDK_Demo" Project and program FPGA
	Run Selected Project for Testing Individual Click Sensors OR Combined Project
******************************************
FPGA Peripherals
Outputs:
	-Click SunLED Sensor
	-Click Alcohol Sensor
	-FPGA LED Lights 
******************************************
MikroBus Click SunLED Board
	-GPIO:	Reset
	-CS  :	Latch
	-SPI :	Protocal for bit-shift registers for LED
	-PWM : 	Turn brightness to 100%


******************************************
MikroBus Click 2 Peripherals
	-GPIO : MEMB
	-I2C  : Protocol to read sensor
******************************************


END OF DOCUMENT



