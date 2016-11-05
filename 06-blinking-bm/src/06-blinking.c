
/*==================[inclusions]=============================================*/
#include "06-blinking.h"       /* <= own header */
#include "pwm.h"

#define PERIODO_PWM 40		/*Periodo equivalete a 100Hz definido por el usuario*/

uint8_t valor_aplicacion=15;

int main(void)
{

	Inicializar_PWM(PUERTO1,PERIODO_PWM);

/* el valor de "valor_aplicacion" debe ser un valor hasta 255*/
	Valor_PWM(valor_aplicacion);




    while(1){

    /*	FuncInter();*/
     /*Escribir_PWM(PUERTO1);*/

     /*Borrar_PWM(PUERTO1);*/
    };
    


}


