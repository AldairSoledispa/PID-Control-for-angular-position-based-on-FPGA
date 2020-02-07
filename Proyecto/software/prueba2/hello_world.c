#include <stdio.h>
#include "io.h"
#include <stdlib.h>

int main()
{
	volatile int * memoria = (int *) 0x00; // SDRAM address
	//Variable de lectura
	unsigned int ldr_der;
	unsigned int ldr_iz;
	unsigned int absoluto;
	unsigned int comparador;

	while (1){
		//Lectura de datos
		ldr_der = IORD(memoria,0x000);
		ldr_iz= IORD(memoria,0x001);
		//nformación de memoria
		printf("El valor del LDR derecho es --> %d Porciento \n",ldr_der);
		printf("El valor del LDR izquierdo es --> %d Porciento \n",ldr_iz);
		absoluto = abs(ldr_der - ldr_iz)
		printf("El valor absoluto entre las LDR es --> %d Porciento \n",absoluto);
		if(ldr_der => ldr_iz){
			if (ldr_der > ldr_iz){
				comparador=0;
				printf("El valor del LDR derecho es mayor --> %d Porciento \n",comparador);
			}
			else{
				comparador=1;
				printf("El valor de las LDR son iguales --> %d Porciento \n",comparador);
			}
		}
		else{
			comparador=2;
				printf("El valor del LDR izquierdo es mayor --> %d Porciento \n",comparador);
		}
		usleep(100000);
	}
	return 0;
}


