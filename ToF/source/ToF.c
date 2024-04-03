/*
 * Copyright 2016-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    ToF.c
 * @brief   Application entry point.
 */
//includes
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"
#include "vl53l5cx_api.h"
#include "platform.h"
#include "oled.h"
#include "arm_svm_example.h"

//defines
#define I2C_OLED ((I2C_Type *)I2C1_BASE)

//variables
int status;
volatile int IntCount;
uint8_t p_data_ready;
VL53L5CX_Configuration 	Dev;
VL53L5CX_ResultsData 	Results;
uint8_t resolution, isAlive;
uint16_t idx;
char sbuff[32];
float32_t datas[64];


void delay_ms(uint32_t delay)
{
	for(volatile int j=delay*100000; j > 0;j--);
}

void cbToF_Ready(pint_pin_int_t pintr, uint32_t pmatch_status) {
	status = vl53l5cx_get_resolution(&Dev, &resolution);
	status = vl53l5cx_get_ranging_data(&Dev, &Results);
	int index=0;
	for(int j = 0; j < resolution/8;j++) {
		for(int i = 0; i < resolution/8;i++) {

			PRINTF("%4d ", Results.distance_mm[(VL53L5CX_NB_TARGET_PER_ZONE * i)+(8*j)]);
			datas[index++]=(float32_t)Results.distance_mm[(VL53L5CX_NB_TARGET_PER_ZONE * i)+(8*j)];

		}
		PRINTF("\r\n");
	}
	int out=predict(datas);
	//PRINTF("--------------------------------------\r\n");
	OLED_Puts(0, 42, "gesture recognition:");
	if(out==0){
		sprintf(sbuff, "[   piesc    ], [%d]", out);
		PRINTF("--------------piesc-------------------\r\n");
	}
	else if(out ==1){
		sprintf(sbuff, "[otwarta dlon], [%d]", out);
		PRINTF("---------otwarta-dlon-----------------\r\n");
	}
	else if(out ==2){
			sprintf(sbuff, "[  dwa palce ], [%d]", out);
			PRINTF("---------dwa-palce--------------------\r\n");
	}
	else{
		sprintf(sbuff, "[nie wykryto], [%d]", out);
		PRINTF("---------nie-wykryto------------------\r\n");
	}

	OLED_Puts(0, 52, sbuff);
	OLED_Refresh_Gram();
}


/*
 * @brief   Application entry point.
 * Main program
 */
int main(void) {

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();

#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
#endif
	/*init DSP SVM*/
	initParams();

	/* Initialize OLED */
	OLED_Init(I2C_OLED);
	OLED_Puts(52, 0, "Run");
	OLED_Draw_Line(0,10, 127,10);
	OLED_Refresh_Gram();
	/* Other */
	PRINTF("Run\n\r");


	Dev.platform.i2c = FLEXCOMM4_PERIPHERAL;
	Dev.platform.address = 0x29;


	GPIO_PinWrite(BOARD_TOFCAMPINS_TRST_GPIO, BOARD_TOFCAMPINS_TRST_PORT, BOARD_TOFCAMPINS_TRST_PIN, 0);
	delay_ms(20);

	GPIO_PinWrite(BOARD_TOFCAMPINS_TLPn_GPIO, BOARD_TOFCAMPINS_TLPn_PORT, BOARD_TOFCAMPINS_TLPn_PIN, 0);
	delay_ms(20);

	GPIO_PinWrite(BOARD_TOFCAMPINS_TLPn_GPIO, BOARD_TOFCAMPINS_TLPn_PORT, BOARD_TOFCAMPINS_TLPn_PIN, 1);
	delay_ms(20);


	status = vl53l5cx_is_alive(&Dev, &isAlive);
	if(!isAlive && status==0) {

		PRINTF("VL53L5CXV0 not detected at requested address (0x%x)\r\n", Dev.platform.address);
		return 1;
	} else {

		PRINTF("VL53L5CXV0 is Alive at address (0x%x)\r\n", Dev.platform.address);
	}

	PRINTF("Sensor initializing, please wait few seconds...\r\n");
	status = vl53l5cx_init(&Dev);
	status = vl53l5cx_set_resolution(&Dev, VL53L5CX_RESOLUTION_8X8);
	status = vl53l5cx_set_ranging_frequency_hz(&Dev, 60);				         // Set 60 Hz ranging frequency
	PRINTF("Status %d\r\n", status);
	status = vl53l5cx_set_ranging_mode(&Dev, VL53L5CX_RANGING_MODE_CONTINUOUS);  // Set mode continuous

	PRINTF("Ranging starts\r\n");
	status = vl53l5cx_start_ranging(&Dev);
	/* USER CODE END 2 */
	PINT_EnableCallbackByIndex(PINT_PERIPHERAL, kPINT_PinInt0);

	while(1) {
	}
	return 0 ;
}
