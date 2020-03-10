/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc primos.c -o primos
Fecha: 10 mar
librerias: stdio, 
Resumen: El programa lee un número entero mayor que 1 y determina si este es un numero primo.
Entrada:  entero de entrada N
Salida: texto indicando "es primo", "no es primo"
*/

#include <stdio.h>
unsigned int N;			//N es el número a analizar, i es un contador y primo es un asignación booleana
				//Ya que no consideramos números negativos, usamos unsigned int para poder analizar más casos
unsigned int i=2;		//Comenzamos en 2 para analizar si N es divisible por cualquier número i>2

int primo=1;			//Iniciamos con un valor afirmativo de primalidad, este se mantendrá igual siempre 
				//y cuando no exista algún número que divida a N, en caso contrario sabemos que
				//N no es primo y el valor de primo deberá cambiar a cero

void main(){
	printf("Ingrese un número entero mayor a 1 \n");
	scanf("%i",&N);	 		//Asigna el número que vamos a analizar a la variable N

	while(i<(N-1)&&primo==1){	//Nos mantenemos en un ciclo si y solo si se cumple que  "i<N-1" y "primo=1"
		if(N%i==0){		//Si N%i=0 sabemos que N es divisible por i, por lo tanto no es primo
			primo=0;	//modificamos el valor de primo a cero para indicar que no es primo
		}
		++i;			//Sumamos uno a i para analizar el caso con i+1 hasta llegar a N-1
			
	}				//Al terminar este ciclo de N-3 repeticiones obtenemos un valor para primo
	if(primo==0){			//Si primo es cero sabemos que N tiene como mínimo un divisor y por lo tanto no es primo
		printf("no es primo\n");
	}
	else{				//En caso contrario sabemos que N no tiene divisores y por lo tanto es primo
		printf("es primo\n");
	}
}
