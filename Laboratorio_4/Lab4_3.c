/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_3.c -o Lab4_3
Fecha: mar mar 24 17:43:19 CST 2020
librerias: stdio, math
Resumen: Se solicita al usuario dos posiciones de coordenas,
estos dos vectores se almacenan y con ellos se procede a realizar el 
calculo de: Magnitud de cada vector, Producto escalar, Suma de vectores 
y producto vectorial.
Entrada:  6 enteros
Salida: Se imprime en terminal el resultado de los calculos solicitados
*/

#include <stdio.h>
#include <math.h>
int A[3],ind;
int B[3];
int a_a,a_b;
int b[3];
int c;
int d[3];
void imprimir();
void magn();
void suma();
void pesca();
void pcruz();

void main(){
	for(int x=0;x<3;x+=1){
		scanf("%i",&ind);
		A[x]=ind;
	}
	printf("Vector A: ");
	imprimir(A);

	for(int x=0;x<3;x+=1){
		scanf("%i",&ind);
		B[x]=ind;
	}
	printf("Vector B: ");
	imprimir(B);
	printf("Magnitud de A: ");
	magn(A);
	printf("Magnitud de B: ");
	magn(B);
	suma(A,B);
	pesca(A,B);




}
void magn(int X[3]){
	float rst=0;
	for(int x=0;x<3;x+=1){
		rst=rst+pow(X[x],2);
	}
	
	printf("%.2f",sqrt(rst));
	printf("\n");
}

void suma(int X[3],int Y[3]){
	int sum[3];
	for(int x=0;x<3;x+=1){
		sum[x]=X[x]+Y[x];
	}
	printf("Suma: ");
	imprimir(sum);
}

void pesca(int X[3],int Y[3]){
	int prod[3];
	for(int x=0;x<3;x+=1){
		prod[x]=X[x]*Y[x];
	}
	printf("Producto Escalar: ");
	imprimir(prod);
}


void imprimir(int X[3]){
	for(int x=0;x<3;x+=1){
		int r=X[x];
		printf("%d ",r);
	}
	printf("\n");
}
