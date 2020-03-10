/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc rango_primos.c -o rango_primos
Fecha: mar mar 10 12:59:17 CST 2020
librerias: stdio, 
Resumen: El programa lee dos números enteros para determinar un rango, luego procede a mostrar todos los números primos que estén en ese rango.
Entrada:  Dos enteros N1,N2
Salida: Imprime el valor de "i" si este es primo
*/

#include <stdio.h>
int N1, N2,i;
int j=2;
int Es_primo();

void main(){
	printf("Ingrese el valor más pequeño del rango ");
	scanf("%i",&N1);
	printf("Ingrese el valor más grande del rango ");
	scanf("%i",&N2);
	i=N1;
	while(i<=N2){
		printf("%i\n",i);
		++i;
	}

}

int Es_primo(int a ){
	int primo=1;
	while(j<a && primo==1){
		if(a%j==0){
			primo=0;
		}
		++j;
	}
	j=2;
	return primo;
}
