/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_1.c -o Lab4_1
Fecha: jue mar 19 17:12:40 CST 2020
librerias: stdio, 
Resumen: Vector con números pares del 2 al 20, el programa muestra 
los elementos en forma ascendente su se ingresa la letra "a" 
y de forma descendente con la letra "d".
Entrada:  "a","d"
Salida: vector A
*/

#include <stdio.h>
int A[10];
int t=sizeof(A)/sizeof(A[0]);
int condicion=1;
char B;
void imprimir();
void rimirpmi();
void main(){
	for(int x=0;x<10;x+=1){
		A[x]=2+x*2;
	}
	while(condicion==1){
		printf("Escriba a para ver el vector de forma ascendente\n");

		printf("Escriba d para ver el vector de forma descendente\n");
		scanf("%c",&B);
		if(B=='a'){
			condicion=0;
			imprimir(A);	
		}
		else if(B=='d'){
			condicion=0;
			rimirpmi(A);
		}
		else{
			printf("\n");
		}
	}
}

void imprimir(int X[t]){
	for(int x=0;x<t;x+=1){
		int b=X[x];
		printf("%d ",b);
	}
	printf("\n ");
}


void rimirpmi(int X[t]){
	for(int x=t-1;x>=0;x-=1){
		int b=X[x];
		printf("%d ",b);
	}
	printf("\n");
}
