/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_2.c -o Lab4_2
Fecha: vie mar 20 13:09:16 CST 2020
librerias: stdio
Resumen: El programa solicita al usuario 5 números enteros,
estos se almacenan en un vector. Este vector debe ordenar los
elementos de forma ascendente y al terminar debe mostrar el
vector ordenado.
Entrada:  5 enteros
Salida: un vector ordenado
*/

#include <stdio.h>
void imprimir();		// Definimos una función para imprimir los vectores
void insercion();		// Funcion para ordenar, usamos el método de inserción
int A[5];			// Vector donde se almacenan los 5 números dados por el usuario
int a,b,c,d,e;
void main(){
	printf("Ingrese 5 números separados por un espacio y presione enter \n");
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);	// Se lee de terminal un número y se asigna a la variable b
	A[0]=a;				// Se asigna el valor de b a la posición x del vector A
	A[1]=b;				// Se asigna el valor de b a la posición x del vector A
	A[2]=c;				// Se asigna el valor de b a la posición x del vector A
	A[3]=d;				// Se asigna el valor de b a la posición x del vector A
	A[4]=e;				// Se asigna el valor de b a la posición x del vector A

	insercion(A);				// Se ordena el vector A de menor a mayor
	imprimir(A);				// Se imprime el vector A que ya está ordenado
}

void imprimir(int X[5]){			// Función para imprimir el vector
	for(int x=0;x<5;x+=1){			// Repite el proceso 5 veces, este proceso inicia asignando el valor
		int b=X[x];			// de la casilla  x del vector X a la variable b para luego
		printf("%d ",b);		// imprimir el valor de b en la terminal
	}
	printf("\n");				// Para que se pueda leer de mejor manera el resultado, se agrega un salto
}						// de línea al finalizar de mostrar el vector

void insercion(int X[5]){			// Funcion de ordenamiento
	for(int x=1; x<5; x+=1){		// Este método de ordenamiento lo que hace es valuar el n-ésimo término
		int a= X[x];			// y lo compara con el anterior, si el nésimo es menor, entonces cambia el
		int b= x-1;			// valor con el n-1 término, y vuelve a valuar, si es menor que n-2, cambia
		while((X[b]>a)&&(b>=0)){	// el valor y valúa con el n-3 término, así, hasta valuar con un número que sea
			X[b+1]=X[b];		// menor al n-ésimo original o que se llegue a la casilla cero
			b--;			// Si por caso contrario es mayor, entonces salta el ciclo while y analiza
		}				// el caso con n+1
		X[b+1]=a;			
	}
}
