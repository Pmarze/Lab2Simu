/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_2.c -o Lab4_2
Fecha: vie mar 20 13:09:16 CST 2020
librerias: stdio
Resumen: El programa solicita al usuario 5 números enteros, estos se almacenan en un vector. Este vector debe ordenar los elementos de forma ascendente y al terminar debe mostrar el vector ordenado.
Entrada:  5 enteros
Salida: un vector ordenado
*/

#include <stdio.h>
void imprimir();
int A[5],b;

void main(){
	printf("Ingrese su valor y luego presione enter  \n");
	for(int x=0;x<5;x+=1){
		scanf("%i",&b);
		A[x]=b;
	}
	imprimir(A);
}

void imprimir(int X[5]){
	for(int x=0;x<5;x+=1){
		int b=X[x];
		printf("%d ",b);
	}
	printf("\n");
}

