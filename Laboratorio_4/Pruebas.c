/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc EOF.c -o EOF
Fecha: jue mar 26 13:37:58 CST 2020
librerias: stdio, 
Resumen: 
Entrada:  
Salida: 
*/

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
char A[5];

void main(){
	scanf("%s",A);
	long int longitud=strlen(A) ;
	printf("Cadena A:  %s\n ",A);	
	printf("Cadena A:  %c\n ",A[longitud-4]);	
	printf("Tamaño cadena: %ld",longitud);
}