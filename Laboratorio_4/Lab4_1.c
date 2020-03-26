/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_1.c -o Lab4_1
Fecha: jue mar 19 17:12:40 CST 2020
librerias: stdio, string
Resumen: Vector con números pares del 2 al 20, el programa muestra 
los elementos en forma ascendente su se ingresa la letra "a" 
y de forma descendente con la letra "d".
Entrada:  "a","d"
Salida: vector A
*/

#include <stdio.h>
#include <string.h>

int A[10];				// El tamaño del vector es 10 porque hay 10 pares en el rango [2,20]
int t=sizeof(A)/sizeof(A[0]);		// Calculamos el tamaño del vector A
int condicion=1;			// Si se ingresa un caracter inválido condicion es 1 para que solicite uno nuevo
char B[10];				// En esta variable se guardan los caracteres que ingresa el usuario
					// en la practica descubrimos que el tamaño 10 no limita el string que se ingresa
void imprimir();			// Funcion para imprimir en orden ascendente
void rimirpmi();			// Funcion para imprimir en orden descendente

void main(){
	for(int x=0;x<10;x+=1){		// Utilizamos un ciclo for para generar nuestra lista de numeros pares	
		A[x]=2+x*2;		// Un número par se escribe de la forma 2n, escribimos 2+2*n para empezar 
	}				// nuestra lista en 2, y poder utilizar al mismo tiempo x para asignar 
					// valores al vector y ahorrarnos así una variable

	while(condicion==1){		
		printf("Escriba a para ver el vector de forma ascendente\n");
		printf("Escriba d para ver el vector de forma descendente\n");
		scanf("%s",B);			// Asignamos a B el la cadena que ingrese el usuario
		
		long int longitud=strlen(B);	// Con strlen sabemos que tamaño tiene la cadena ingresada por el usuario

		if(longitud==1){		// Solo se acepta la cadena "a*" o "b*", donde el signo asterisco
		       				// lo utilizamos para indicar que a o b pueden ser precedidas por cualquier
						// cantidad de espacios, aún así, esta cadena será aceptada por el programa
	
			if(B[0]=='a'){		// Si el caracter ingresado es a, este es aceptado y asignamos a condicion 
			condicion=0; 		// el valor 0 para que ya no se solicite otro caracter,
			imprimir(A);		// imprime de forma ascendente el vector A
			}
			else if(B[0]=='d'){	// Si el caracter ingresado es b, este es aceptado y asignamos a condicion
				condicion=0;	// el valor 0 para que ya no solicite otro caracter
				rimirpmi(A);	// imprime de forma descendente el vector A
			}
			else{			// Si no se cumple ninguna de las anteriores, notifica al usuario y 
						// se mantiene en el ciclo while hasta que se ingrese un caracter aceptado
				printf("Caracter incorrecto \n");
				printf("\n");
			}
		}
		else{			 	// Si ingresamos una cadena con 2 o más caracteres imprime que es incorrecto
						// y solicitará un nuevo dato
			printf("Caracter incorrecto \n");
			printf("\n");
		}
	}
}

void imprimir(int X[t]){		// Funcion para imprimir el vector ascendentemente
	for(int x=0;x<t;x+=1){		// Se realiza un conteo de 0 a t-1 que son las casillas del vector
		int b=X[x];		// Se asigna el valor individual de cada casilla al entero b
		printf("%d ",b);	// Se imprime el valor de b y se repite el proceso
	}
	printf("\n ");			// Para mayor orden, al terminar de imprimir el vector se inicia una nueva línea
}


void rimirpmi(int X[t]){		// Funcion para imprimir el vector descendentemente
	for(int x=t-1;x>=0;x-=1){	// Se realiza un conteo de t-1 a 0
		int b=X[x];		// Se asigna el valor individual de cada casilla al entero b
		printf("%d ",b);	// Se imprime el valor de b y se repite el proceso
	}
	printf("\n");			// Para mayor orden, al terminar de imprimir el vector se inicia una nueva linea
}
