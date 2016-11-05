#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "pwm.h"



#define GPIO0_MUX_GROUP     6
#define GPIO0_MUX_PIN       1
#define GPIO0_GPIO_PORT     3
#define GPIO0_GPIO_PIN      0

#define GPIO1_MUX_GROUP     6
#define GPIO1_MUX_PIN       4
#define GPIO1_GPIO_PORT     3
#define GPIO1_GPIO_PIN      3

#define GPIO2_MUX_GROUP     6
#define GPIO2_MUX_PIN       5
#define GPIO2_GPIO_PORT     3
#define GPIO2_GPIO_PIN      4

#define GPIO5_MUX_GROUP     6
#define GPIO5_MUX_PIN       9
#define GPIO5_GPIO_PORT     3
#define GPIO5_GPIO_PIN      5

#define GPIO6_MUX_GROUP     6
#define GPIO6_MUX_PIN       10
#define GPIO6_GPIO_PORT     3
#define GPIO6_GPIO_PIN      6

#define GPIO7_MUX_GROUP     6
#define GPIO7_MUX_PIN       11
#define GPIO7_GPIO_PORT     3
#define GPIO7_GPIO_PIN      7

#define GPIO8_MUX_GROUP     6
#define GPIO8_MUX_PIN       12
#define GPIO8_GPIO_PORT     2
#define GPIO8_GPIO_PIN      8

#define OUTPUT_DIRECTION   1
#define INPUT_DIRECTION    0

#define VALOR_MAXIMO 255
uint8_t valor;
/* funcion que realiza la escritura de 1 y 0 en el puerto*/
void FuncInter(void)
	{
	static uint8_t valor_actual=0;
	valor_actual++;
	if(valor_actual <=valor)
		{
			Escribir_PWM(PUERTO1);
		}
		else
		{
			Borrar_PWM(PUERTO1);
		}
	if(valor_actual >= VALOR_MAXIMO)
		{
			valor_actual=0;
		}


	}


/* esta funcion inicializa y configura el puerto seleccionado*/
uint8_t Inicializar_PWM(uint8_t pata,uint8_t frecuencia)
{
	/*frecuencia fija el periodo total del PWM una sola vez a 40us aprox 100Hz*/
	timer0Init(frecuencia,&FuncInter);


	Chip_GPIO_Init(LPC_GPIO_PORT);

	uint8_t resultado=FALSE;

	if(pata==PUERTO1)
	{
		Chip_SCU_PinMux(GPIO0_MUX_GROUP,GPIO0_MUX_PIN,MD_PUP,FUNC0);
		Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO0_GPIO_PORT,1<<GPIO0_GPIO_PIN,OUTPUT_DIRECTION);
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO0_GPIO_PORT,GPIO0_GPIO_PIN);
		resultado = TRUE;
	}
	if(pata==PUERTO2)
	{
		Chip_SCU_PinMux(GPIO1_MUX_GROUP,GPIO1_MUX_PIN,MD_PUP,FUNC0);
		Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO1_GPIO_PORT,1<<GPIO1_GPIO_PIN,OUTPUT_DIRECTION);
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO1_GPIO_PORT,GPIO1_GPIO_PIN);
		resultado = TRUE;
	}
	if(pata==PUERTO3)
	{
		Chip_SCU_PinMux(GPIO2_MUX_GROUP,GPIO2_MUX_PIN,MD_PUP,FUNC0);
		Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO2_GPIO_PORT,1<<GPIO2_GPIO_PIN,OUTPUT_DIRECTION);
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO2_GPIO_PORT,GPIO2_GPIO_PIN);
		resultado = TRUE;
	}
	if(pata==PUERTO4)
	{
		Chip_SCU_PinMux(GPIO5_MUX_GROUP,GPIO5_MUX_PIN,MD_PUP,FUNC0);
		Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO5_GPIO_PORT,1<<GPIO5_GPIO_PIN,OUTPUT_DIRECTION);
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO5_GPIO_PORT,GPIO5_GPIO_PIN);
		resultado = TRUE;
	}
	if(pata==PUERTO5)
	{
		Chip_SCU_PinMux(GPIO6_MUX_GROUP,GPIO6_MUX_PIN,MD_PUP,FUNC0);
		Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO6_GPIO_PORT,1<<GPIO6_GPIO_PIN,OUTPUT_DIRECTION);
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO6_GPIO_PORT,GPIO6_GPIO_PIN);
		resultado = TRUE;
	}
	if(pata==PUERTO6)
	{
		Chip_SCU_PinMux(GPIO7_MUX_GROUP,GPIO7_MUX_PIN,MD_PUP,FUNC0);
		Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO7_GPIO_PORT,1<<GPIO7_GPIO_PIN,OUTPUT_DIRECTION);
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO7_GPIO_PORT,GPIO7_GPIO_PIN);
		resultado = TRUE;
	}

	return resultado;
}

/* funcion que escribe un 1 en el puerto*/
uint8_t Escribir_PWM(uint8_t pata)
{
	switch(pata)
	{
		case PUERTO1 : Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, GPIO0_GPIO_PORT,GPIO0_GPIO_PIN); break;
		case PUERTO2 : Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, GPIO1_GPIO_PORT,GPIO1_GPIO_PIN); break;
		case PUERTO3 : Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, GPIO2_GPIO_PORT,GPIO2_GPIO_PIN); break;
		case PUERTO4 : Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, GPIO5_GPIO_PORT,GPIO5_GPIO_PIN); break;
		case PUERTO5 : Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, GPIO6_GPIO_PORT,GPIO6_GPIO_PIN); break;
		case PUERTO6 : Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, GPIO7_GPIO_PORT,GPIO7_GPIO_PIN); break;
		default : Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, GPIO0_GPIO_PORT,GPIO0_GPIO_PIN);
	}

}
/* funcion que escribe un 0 en el puerto*/
uint8_t Borrar_PWM(uint8_t pata)
{
	switch(pata)
	{
		case PUERTO1 : Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO0_GPIO_PORT,GPIO0_GPIO_PIN); break;
		case PUERTO2 : Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO1_GPIO_PORT,GPIO1_GPIO_PIN); break;
		case PUERTO3 : Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO2_GPIO_PORT,GPIO2_GPIO_PIN); break;
		case PUERTO4 : Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO5_GPIO_PORT,GPIO5_GPIO_PIN); break;
		case PUERTO5 : Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO6_GPIO_PORT,GPIO6_GPIO_PIN); break;
		case PUERTO6 : Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO7_GPIO_PORT,GPIO7_GPIO_PIN); break;
		default : Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO0_GPIO_PORT,GPIO0_GPIO_PIN);
	}

}

/* esta funcion cuenta el valor c que es introducido por el usuario y en funcion de cuanto quiere variar el periodo
 * poe esto se usa un contador que cuente hasta c y luego el resto del periodo definido por frecuencia lo pasa a
 * nivel bajo
 */
uint8_t Valor_PWM(uint8_t c)
{
	valor=c;
}



