#ifndef PWM_H
#define PWM_H

#include "stdint.h"


#define lpc4337            1
#define mk60fx512vlq15     2
#define TRUE 1
#define FALSE 0

enum PUERTOS {PUERTO1,PUERTO2,PUERTO3,PUERTO4,PUERTO5,PUERTO6};

uint8_t Escribir_PWM(uint8_t pata);

uint8_t Borrar_PWM(uint8_t pata);

uint8_t Valor_PWM(uint8_t c);
void FuncInter(void);

#endif
