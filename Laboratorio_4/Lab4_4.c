/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_4.c -o Lab4_4
Fecha: dom mar 29 19:10:39 CST 2020
librerias: stdio, 
Resumen: El programa recibe dos matrices de 3x3
y también una constante, el programa realiza 
las siguientes operaciones y muestra el resultado. 
Las operaciones a realizar son:
1)matA*constante		2)suma de matrices
3)resta de dos matrices		4)multiplicacion de matrices
5)determinante de matA		6)transpuesta de matB
7)inversa de matA		8)reducción de Gauss de matA
9)reducción de Gauss Jordan matB
Entrada:  18 enteros asignados a dos matrices y una constante
Salida: 9 resultados
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>
int cte;			// Constante por la cual se multiplicará la matriz A
float a,b,c;			// Definimos tres constantes para asignar valores a las coordenadas
				// de las matrices
float A[3][3];			// Matriz A de 3x3
float B[3][3];			// Matriz B de 3x3
void mimp();			// Función que permite mostrar matrices de 3x3 en pantalla
void cons();			// Función que multiplica una constante por una matriz
void msr();			// Función para sumar y restar
void mmult();			// Función para multiplicar matrices
float det();			// Función para calcular el determinante de una matriz
void tran();			// Función para obtener la transpuesta de una matriz
#define EPS 0.000001		// Definimos un epsilon para poder comparar datos float
void redg();			// Función que hace una reducción de Gauss
void rgajo();			// Función que hace una reducción de Gauss-Jordan

void main(){
	printf("Ingrese el valor de cte= ");
	scanf("%d",&cte);			// Ingresa el valor de una constante
	__fpurge(stdin);			// Limpia el buffer para evitar el ingreso de datos erróneos
	printf("Ingrese 9 números, Matriz A:\n");
	for(int x=0;x<3;x+=1){			// Repite el ciclo 3 veces, una vez por cada fila
		scanf("%f%f%f",&a,&b,&c);	// Ingresa las 3 coordenadas de la columna x
		A[x][0]=a;
		A[x][1]=b;
		A[x][2]=c;
	}
	__fpurge(stdin);			// Espera que se ingresen los 9 números de la matriz para limpiar
						// el buffer de entrada, si se hace antes solo ingresa 3 datos

	printf("Ingrese 9 números, Matriz B:\n");
	for(int x=0;x<3;x+=1){			// Misma lógica que la matriz anterior
		scanf("%f%f%f",&a,&b,&c);
		B[x][0]=a;
		B[x][1]=b;
		B[x][2]=c;
	}
	__fpurge(stdin);
	
	printf("Matriz A:\n");			// Mostramos en pantalla la matriz A que ingresó el usuario
	mimp(A);
	
	printf("Matriz B:\n");			// Mostramos en pantalla la matriz B que ingresó el usuario
	mimp(B);
	
	printf("resultado cte*matA\n");		// Utilizamos la función cons() para multiplicar la matriz A
	cons(A,cte);				// por una constante

	printf("Suma de A y B\n");		// Utilizamos la función msr con el parámetro 1 para sumar
	msr(A,B,1);				// la matriz A y la matriz B

	printf("Resta de A y B\n");		// Utilizamos la función msr con el parámetro -1 para restar
	msr(A,B,-1);				// la matriz A y la matriz B

	printf("Multiplicación de A y B\n");	// Utilizamos la función mmult() para multiplicar la matriz A
	mmult(A,B);				// con la matriz B

	printf("Determinante de A\n");		// La función det() nos devuelve un float, lo almacenamos en 
	float DET=det(A);			// una variable ya que más adelante nos servirá para saber si
	printf("%f",DET);			// esta matriz tiene inversa, el valor de la variable DET
	printf("\n");				// se imprime en pantalla
	printf("\n");

	printf("Transpuesta de B\n");		// Utilizamos la función tran() para calcular la transpuesta
	tran(B);				// de la matriz B

	printf("Inversa de A\n");		// Analizamos los casos posibles de una matriz inversa, si 
	if(fabs(DET)-0<EPS){			// el DET=0 la matriz no tiene inversa, para comparar float
		printf("No tiene matriz inversa\n");	// utilizamos la condición de que el valor absoluto de
	}						// DET, menos 0 sea menor que EPS, esto porque EPS representa
	else{						// la cifra significativa más pequeña que vamos a trabajar
		printf("Calculo de la matriz inversa\n"); // Si el determinante es distinto de cero, procedemos a
	}						// calcular la matriz inversa
	printf("\n");

	printf("Reducción de Gauss de A\n");	// Utilizamos la función redg() para realizar la reducción de Gauss
	redg(A);				// de la matriz A
	
	printf("Reducción de Gauss-Jordan de B\n");	// Utilizamos la dunción rgajo() para realizar la reducción
	rgajo(B);					// de Gauss-Jordan de la matriz B
}

void cons(float X[3][3],int d){			// Esta función recibe como parámetro una matriz y una constante
	float consA[3][3];			// Definimos una matriz para trabajar en este entorno sin afectar
						// la matriz original
	for(int x=0;x<3;x+=1){			// Se recorre cada fila de la matriz
		for(int y=0;y<3;y+=1){		// Se recorre cada coordenada de la fila
			consA[x][y]=d*X[x][y];	// Se multiplica cada coordenada por la constante dada
		}
	}
	mimp(consA);				// Utilizamos la función mimp() para mostrar el resultado del
}						// proceso en la terminal

void msr(float X[3][3], float Y[3][3],int val){ // Esta función recibe como parámetro dos matrices y una constante
	float AB[3][3];				// Definimos una matriz para trabajar en este entorno sin afectar
						// alguna de las dos matrices originales
	for(int x=0;x<3;x+=1){			// Se recorre cada casilla de ambas matrices y el resultado de la 
		for(int y=0;y<3;y+=1){		// suma o resta se asigna al mismo indice de casilla de la matriz AB
			AB[x][y]=X[x][y]+val*Y[x][y];	// Conocemos que la resta es una suma con el negativo del segundo
		}				// término, entonces para sumar matrices multiplicamos Y por 1, para
	}					// hacer una resta multiplicamos por -1
	mimp(AB);				// utilizamos la función mimp() para mostrar el resultado del proceso 
}						// en pantalla

void mmult(float X[3][3], float Y[3][3]){	// Esta función recibe como parámetro dos matrices
	float AmB[3][3];			// Definimos una matriz de trabajo dentro del entorno
	for(int x=0;x<3;x+=1){
		for(int y=0;y<3;y+=1){		// La deducción de este calculo se explica en la documentación del programa
			AmB[x][y]=X[x][0]*Y[0][y]+X[x][1]*Y[1][y]+X[x][2]*Y[2][y];
		}
	}
	mimp(AmB);				// Mostramos en pantalla el resultado	
}

float det(float X[3][3]){			// Esta función recibe como parámetro dos matrices
	float DET=0;				// Definimos una constante la cual devolverá la función
	for(int x=0;x<3;x+=1){	
		int a=(1+x)%3;			// Al calcular el determinante, por medio del método de Lagrange
		int b=(2+x)%3;			// deducimos que podemos reducir el cálculo a una ecuación de conteo
						// donde el índice a avanza de la forma (1+x) mod3, y el índice
						// b de la forma (2+x) mod3
		DET=DET+X[0][x]*(X[1][a]*X[2][b]-X[1][b]*X[2][a]);
	}
	return DET;				// retornamos el valor de DET
}

void tran(float X[3][3]){			// Esta función recibe como parámetro una matriz
	float T[3][3];				// Definimos una matriz de trabajo dentro del entorno
	for(int x=0;x<3;x+=1){			
		for(int y=0;y<3;y+=1){		// La transpuesta invierte los valores de índice 
			T[x][y]=X[y][x];
		}
	}
	mimp(T);				// Mostramos en pantalla el resultado
}

void redg( float X[3][3]){			// Esta función tiene como parámetro una matriz
	float G[3][3];				// Definimos una matriz de trabajo dentro del entorno
	for(int x=0;x<3;x+=1){
		G[0][x]=X[0][x];		// La primer fila no sufre modificaciones
	}			
	for(int y=0;y<3;y+=1){			
		G[1][y]=X[1][y]-X[1][0];	// Deducimos que La fila dos puede reducirse con su primer
	}					// término en cero con la ecuación Fila1=Fila1-X[1][0]
	G[2][0]=0;				// La casilla X[2][0]=X[2][1]=0
	G[2][1]=0;
	G[2][2]=G[1][1]*(X[2][2]-X[2][1]);	// La casilla 3 se rige por la ecuación Fila2=Fila2*Fila3-Fila2*X[2][1]
	mimp(G);
}

void rgajo(float X[3][3]){			// Esta función tiene como parámetro una matriz
	float GJ[3][3]={{0,0,0},{0,0,0},{0,0,0}};	// Definimos una matriz de trabajo dentro del entorno
	GJ[0][0]=(X[0][0]-X[0][1])*(X[0][0]-X[0][2]);	// La deducción de estas ecuaciones se explica
	GJ[1][1]=(X[1][1]-X[1][0])*(X[0][1]-X[0][2]);		// en la documentación del problema
	GJ[2][2]=(X[1][1]-X[1][0])*(X[2][2]-X[2][1]);
	mimp(GJ);				// Mostramos el resultado en pantalla
}



void mimp(float X[3][3]){			// Esta función tiene como parámetro una matriz
	for(int x=0;x<3;x+=1){			// Recorremos cada índice de la matriz
		for(int y=0;y<3;y+=1){		// y se imprime en pantalla
			float coord=X[x][y];
			printf("%f  ",coord);
		}
		printf("\n");
	}
	printf("\n");
}
