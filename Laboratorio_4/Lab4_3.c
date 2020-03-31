/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_3.c -o Lab4_3 -lm	//-lm hace un link con la libreria libm, sin este paso, el programa no compila
Fecha: mar mar 24 17:43:19 CST 2020
librerias: stdio, math, stdio_ext
Resumen: Se solicita al usuario dos posiciones de coordenas,
estos dos vectores se almacenan y con ellos se procede a realizar el 
calculo de: Magnitud de cada vector, Producto escalar, Suma de vectores 
y producto vectorial.
Entrada:  6 enteros
Salida: Se imprime en terminal el resultado de los calculos solicitados
*/

#include <stdio.h>
#include <math.h>
#include <stdio_ext.h>
int A[3];			// Creamos el vector A 
int B[3];			// Creamos el vector B
void imprimir();		// Definimos la función para imprimir vectores en pantalla
void magn();			// Función aplicada sobre un vector que calcula la magnitud del vector ingresado
void suma();			// Función aplicada sobre dos vectores que calcula la suma de los mismos
void pesca();			// Función aplicada sobre dos vectores que calcula el producto escalar entre ambos
void pcruz();			// FUnción aplicada sobre dos vectores que calcula el producto vectorial entre ambos
int a,b,c;			// Utilizamos cada variable para asignar el valor de cada componente de los vectores
void main(){
	printf("Ingrese 3 números, separados por espacio o \nsalto de línea para el vector A:  ");
	scanf("%d%d%d",&a,&b,&c);	// Se asigna el valor ingresado a la variable que usamos como indice
	__fpurge(stdin);		// Se limpia el buffer para evitar ingreso de datos errados
	A[0]=a;
	A[1]=b;
	A[2]=c;
	printf("Vector A: ");		// Mostramos el vector ingresado, para que el usuario conozca los valores ingresados
	imprimir(A);		

	printf("Ingrese 3 números, separados por espacio o \nsalto de línea para el vector B:  ");
	scanf("%d%d%d",&a,&b,&c);	// Se asigna el valor ingresado a la variable que usamos como indice
	__fpurge(stdin);		// Se limpia el buffer para evitar ingreso de datos errados
	B[0]=a;
	B[1]=b;
	B[2]=c;
	printf("Vector B: ");		// Mostramos el vector ingresado, para que el usuario conozca los valores ingresados
	imprimir(B);
			

	printf("Magnitud de A: ");	
	magn(A);			// Utilizamos la función magnitud
	printf("Magnitud de B: ");
	magn(B);			// Utilizamos la función magnitud
	suma(A,B);			// Utilizamos la función suma
	pesca(A,B);			// Utilizamos la función Producto escalar
	pcruz(A,B);			// Utilizamos la función Producto vectorial



}
void magn(int X[3]){			// Función para calcular la magnitud de un vector
	float rst=0;			// Utilizamos una variable flotante porque la magnitud no siempre es un entero
	for(int x=0;x<3;x+=1){		// Se repite el ciclo por cada coordenada del vector en este caso repite 3 veces
		rst=rst+pow(X[x],2);	// Hacemos una suma recursiva para sumar la nueva coordenada al cuadrado a
	}				// la suma de las coordenadas anteriores ya sumadas
	printf("%.2f",sqrt(rst));	// Luego de iterar 3 veces imprimimos la raiz cuadrada del valor obtenido
	printf("\n");			
}

void suma(int X[3],int Y[3]){		// Función para calcular la suma de dos vectores
	int sum[3];			// Creamos el vector suma, este vector seá el resultado de sumar A y B
	for(int x=0;x<3;x+=1){		
		sum[x]=X[x]+Y[x];	// Sumamos cada coordenada de los vectores A y B
	}
	printf("Suma: ");
	imprimir(sum);			// El resultado de esta operación es un vector, utilizamos la  
}					// función imprimir para poder observar el vector en la terminal

void pesca(int X[3],int Y[3]){		// Función para calcular el producto escalar entre dos vectores
	int prod[3];			// Definimos el vector prod que será el vector resultante de la operación
	for(int x=0;x<3;x+=1){		
		prod[x]=X[x]*Y[x];	// Al índice x del vector prod se le asigna el valor de multiplicar
	}				// El valor del índice x de X y el índice x de Y.
	printf("Producto Escalar: ");
	imprimir(prod);			// El resultado de esta operación es un vector, entonces utilizamos la 
}					// función imprimir para observar el resultado en la terminal

void pcruz(int X[3],int Y[3]){		// Función para calcular el producto vectorial entre dos vectores
	int cruz[3];			// Definimos el vector cruz que será el vector resultante de la operación
	for(int x=0;x<3;x+=1){		
		int a=(1+x)%3;		// El proceso con el cual se infirió este algoritmo esta detallado en 
		int b=(2+x)%3;		// la documentación del programa
		cruz[x]=(X[a]*Y[b]-X[b]*Y[a]);
	}
	printf("Producto cruz: ");
	imprimir(cruz);			// El resultado de esta operación es un vector, entonces utilizamos la
}					// función imprimir para observar el resutlado en la terminal

void imprimir(int X[3]){		// Función que imprimir un vector en la terminal
	for(int x=0;x<3;x+=1){
		int r=X[x];
		printf("%d ",r);
	}
	printf("\n");
}
