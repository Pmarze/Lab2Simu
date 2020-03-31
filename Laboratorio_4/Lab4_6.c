/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_6.c -o Lab4_6 -lm
Fecha: mar mar 31 01:04:30 CST 2020
librerias: stdio, math, stdio_ext
Resumen: El usuario ingresa un número n, el programa calcula las cuatro sumatorias dadas y muestra el resultado en pantalla
Entrada:  un entero
Salida: 4 resultados
*/

#include <stdio.h>
#include <math.h>
#include <stdio_ext.h>
long long int n;
long long int S1();
long double S2();
long long int S3();
long long int S4();

void main(){
	printf("Ingrese un número n: ");
	scanf("%lli",&n);
	__fpurge(stdin);
	
	long double a=(long double)n;

	if (n<=102570 && n>1){
		printf("Resultado primer sumatoria\n");		//Maximo calculado correctamente n=102,570
		printf("%lli \n",S1(n));
		printf("\n");
	}
	else{
		printf("No es posible calcular la sucesión,\n");
		printf("está fuera del rango [1,102570]\n");
		printf("\n");
	}
	
	if (n<=130899 && n>2){
		printf("Resultado segunda sumatoria\n");		//Maximo calculado correctamente n=130,899
		printf("%Lf \n",S2(a,n));
		printf("\n");
	}
	else{
		printf("No es posible calcular la sucesión,\n");
		printf("Esta fuera del rango [2,130899]\n");
		printf("\n");
	}

	if (n<=62 && n>1){
		printf("Resultado sucesión de Bode\n");	//Máximo calculado correctamente n=62
		long double Bode=0.1*S4(n);
		printf("%Lf \n",Bode);
		printf("\n");
	}
	else{
		printf("No es posible calcular la sucesión de Bode,\n");
		printf("Esta fuera del rango [2,60]\n");
		printf("\n");
	}
}

long long int S1(long long int x){
	if (x==1){
		return -2;
	}
	else{
		return 	pow(x,2)*(x-3)+S1(x-1);
	}
}

long double S2(long double x, long long int n){
	if (n==2){
		return 3;
	}
	else{
		return (3/(x-1))+S2(x-1,n-1);
	}
}

long long int S4(long long int x){
	if (x==2){
		return 7;
	}
	else{
		return 	(3*pow(2,x-2)+4)+S4(x-1);
	}
}
