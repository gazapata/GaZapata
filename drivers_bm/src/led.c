/* Copyright 2016, XXXXXXXXX  
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal driver led
 **
 **
 **
 **/
/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal LED Driver
 ** @{ */
/*
 * Initials     Name
 * ---------------------------
 *
 */
/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */
/*==================[inclusions]=============================================*/

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "led.h"

/*==================[macros and definitions]=================================*/



#define LED_RGB_R_MUX_GROUP   2
#define LED_RGB_R_MUX_PIN     0
#define LED_RGB_R_GPIO_PORT   5
#define LED_RGB_R_GPIO_PIN    0

#define LED_RGB_G_MUX_GROUP   2
#define LED_RGB_G_MUX_PIN     1
#define LED_RGB_G_GPIO_PORT   5
#define LED_RGB_G_GPIO_PIN    1

#define LED_RGB_B_MUX_GROUP   2
#define LED_RGB_B_MUX_PIN     2
#define LED_RGB_B_GPIO_PORT   5
#define LED_RGB_B_GPIO_PIN    2


#define LED1_MUX_GROUP     2
#define LED1_MUX_PIN       10
#define LED1_GPIO_PORT     0
#define LED1_GPIO_PIN      14

#define LED2_MUX_GROUP     2
#define LED2_MUX_PIN       11
#define LED2_GPIO_PORT     1
#define LED2_GPIO_PIN      11

#define LED3_MUX_GROUP     2
#define LED3_MUX_PIN       12
#define LED3_GPIO_PORT     1
#define LED3_GPIO_PIN      12

#define OUTPUT_DIRECTION   1
#define INPUT_DIRECTION    0

/*==================[internal data declaration]==============================*/
/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/

uint8_t Init_Leds(void)
{
	/** \details This method calls LPCOpen functions to initialize four leds
	 * in the EDU-CIAA board. This method has to be invoked first.
	 * */

	/** Configuration of the GPIO port*/
	Chip_GPIO_Init(LPC_GPIO_PORT);

	/** Mapping of RGB led pins*/
	Chip_SCU_PinMux(LED_RGB_R_MUX_GROUP,LED_RGB_R_MUX_PIN,MD_PUP,FUNC4);
	Chip_SCU_PinMux(LED_RGB_R_MUX_GROUP,LED_RGB_G_MUX_PIN,MD_PUP,FUNC4);
	Chip_SCU_PinMux(LED_RGB_R_MUX_GROUP,LED_RGB_B_MUX_PIN,MD_PUP,FUNC4);

	/** Mapping of Leds 1,2,3 pins*/
	Chip_SCU_PinMux(LED1_MUX_GROUP,LED1_MUX_PIN,MD_PUP,FUNC0);
	Chip_SCU_PinMux(LED2_MUX_GROUP,LED2_MUX_PIN,MD_PUP,FUNC0);
	Chip_SCU_PinMux(LED3_MUX_GROUP,LED3_MUX_PIN,MD_PUP,FUNC0);


	/** Set RGB port as output*/
	/*Chip_GPIO_SetDir(LPC_GPIO_PORT, LED_RGB_R_GPIO_PORT,(1<<LED_RGB_R_GPIO_PIN)|(1<<LED_RGB_G_GPIO_PIN)|(1<<LED_RGB_B_GPIO_PIN),1);*/

	/** Set LED1 port as output*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LED1_GPIO_PORT,1<<LED1_GPIO_PIN,OUTPUT_DIRECTION);

	/** Set LED2 and LED3 ports as output*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LED2_GPIO_PORT,1<<LED2_GPIO_PIN,OUTPUT_DIRECTION);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LED3_GPIO_PORT,1<<LED3_GPIO_PIN,OUTPUT_DIRECTION);

	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LED_RGB_R_GPIO_PORT,(1<<LED_RGB_R_GPIO_PIN)|(1<<LED_RGB_G_GPIO_PIN)|(1<<LED_RGB_B_GPIO_PIN));
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LED1_GPIO_PORT,1<<LED1_GPIO_PIN);
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LED2_GPIO_PORT,1<<LED2_GPIO_PIN);
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LED3_GPIO_PORT,1<<LED3_GPIO_PIN);

	return TRUE;
}


/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */
 uint8_t Led_On(uint8_t led)
 {
 	/** \details Function to turn on a specific led at the EDU-CIAA board.
 	 * 	\params uint8_t led: this word represent a specific led based on the LED_COLOR enumeration.
 	 * */
 	uint8_t result = FALSE;

 	if (led == RED_LED)
 	{
 		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,LED1_GPIO_PORT,LED1_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == YELLOW_LED)
 	{
 		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,LED2_GPIO_PORT,LED2_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == GREEN_LED)
 	{
 		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,LED3_GPIO_PORT,LED3_GPIO_PIN);
 		result = TRUE;
 	}
     if (led == RGB_R_LED)
 	{
 		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,LED_RGB_R_GPIO_PORT,LED_RGB_R_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == RGB_G_LED)
 	{
 		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,LED_RGB_G_GPIO_PORT,LED_RGB_G_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == RGB_B_LED)
 	{
 		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,LED_RGB_B_GPIO_PORT,LED_RGB_B_GPIO_PIN);
 		result = TRUE;
 	}
 	return result;
 }

 uint8_t Led_Off(uint8_t led)
 {
 	/** \details Function to turn off a specific led at the EDU-CIAA board.
 		 * 	\params uint8_t led: this word represent a specific led based on the LED_COLOR enumeration.
 		 * */
 	uint8_t result = FALSE;

 	if (led == RED_LED)
 	{
 		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,LED1_GPIO_PORT,LED1_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == YELLOW_LED)
 	{
 		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,LED2_GPIO_PORT,LED2_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == GREEN_LED)
 	{
 		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,LED3_GPIO_PORT,LED3_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == RGB_R_LED)
 	{
 		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,LED_RGB_R_GPIO_PORT,LED_RGB_R_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == RGB_G_LED)
 	{
 		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,LED_RGB_G_GPIO_PORT,LED_RGB_G_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led == RGB_B_LED)
 	{
 		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,LED_RGB_B_GPIO_PORT,LED_RGB_B_GPIO_PIN);
 		result = TRUE;
 	}
 	return result;
 }

 /** \brief Function to turn off a specific led */
 uint8_t Led_Toggle(uint8_t led)
 {
 	/** \details Function to toogle a specific led at the EDU-CIAA board.
 	 * 	\params uint8_t led: this word represent a specific led based on the LED_COLOR enumeration.
 	 * */
 uint8_t result = FALSE;

 	if (led == RED_LED)
 	{
 		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,LED1_GPIO_PORT,LED1_GPIO_PIN);
 		result = TRUE;
 	}
 	else
 	{
 		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,LED2_GPIO_PORT,LED2_GPIO_PIN);
 		result = TRUE;

 	}
 	/* 	if (led & YELLOW_LED)
 	{
 		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,LED2_GPIO_PORT,LED2_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led & GREEN_LED)
 	{
 		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,LED3_GPIO_PORT,LED3_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led & RGB_R_LED)
 	{
 		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,LED_RGB_R_GPIO_PORT,LED_RGB_R_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led & RGB_G_LED)
 	{
 		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,LED_RGB_G_GPIO_PORT,LED_RGB_G_GPIO_PIN);
 		result = TRUE;
 	}
 	if (led & RGB_B_LED)
 	{
 		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,LED_RGB_B_GPIO_PORT,LED_RGB_B_GPIO_PIN);
 		result = TRUE;
 	}*/
 	return result;

 }

/*==================[end of file]============================================*/

