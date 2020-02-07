#include <stdio.h>
#include "io.h"

/*=======  main =========*/
int main (void) {
	volatile int * ADC = (int *) 0x4041020;//asignar la memoria del ADC
	int * memoria = (int *) 0x00; // SDRAM address
	//Variable de lectura
	unsigned int ldr_der;
	unsigned int ldr_iz;
	//Canales mediciones
	unsigned int canal_ldr_der;
	unsigned int canal_ldr_iz;


	*(ADC) = 0; //setear valores de los canales en 0

	while (1){

		//Asignar valores a los canales
		canal_ldr_der = 0;
		canal_humedad_suelo = 1;

		//Lectura LDR derecha
		ldr_der = *(ADC+canal_ldr_der); //Obtener el valor del ldr
		ldr_der=(ldr*3.3)*100/(4095*3); //Convertir el valor en porcentaje
		//printf("El valor del LDR derecho en el canal %d es --> %d Porciento \n",canal_ldr_der,ldr_der);

		//Lectura LDR izquierda
		ldr_iz = *(ADC+canal_ldr_iz); //Obtener el valor del ldr
		ldr_iz=(ldr*3.3)*100/(4095*3); //Convertir el valor en porcentaje
		//printf("El valor del LDR izquierdo en el canal %d es --> %d Porciento \n",canal_ldr_iz,ldr_iz);


		
		//Escritura en memoria
		IOWR(memoria,0x000,ldr_der);
		IOWR(memoria,0x001,ldr_iz);
		usleep(100000);
	}
	return 0;
}
