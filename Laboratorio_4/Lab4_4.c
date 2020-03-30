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
9)reducción de Gauss Jordan mat7)inversa de matA		8)reducción de Gauss de matA
9)reducción de Gauss Jordan matB
Entrada:  18 enteros asignados a dos matrices y una constante
Salida: 9 resultados
*/

#include <stdio.h>
#include <stdio_ext.h>
int cte;
int a,b,c;
int A[3][3];
int B[3][3];
void mimp();
void cons();
void msumres();
void mmult();
void det();
void tran();


void main(){
	printf("Ingrese el valor de cte= ");
	scanf("%d",&cte);
	__fpurge(stdin);
	printf("Ingrese 9 números, Matriz A:\n");
	for(int x=0;x<3;x+=1){
		scanf("%d%d%d",&a,&b,&c);
		A[x][0]=a;
		A[x][1]=b;
		A[x][2]=c;
	}
	__fpurge(stdin);

	printf("Ingrese 9 números, Matriz B:\n");
	for(int x=0;x<3;x+=1){
		scanf("%d%d%d",&a,&b,&c);
		B[x][0]=a;
		B[x][1]=b;
		B[x][2]=c;
	}
	__fpurge(stdin);
	
	printf("Matriz A:\n");
	mimp(A);
	
	printf("Matriz B:\n");
	mimp(B);
	
	printf("resultado cte*matA\n");
	cons(A,cte);	

	printf("Suma de A y B\n");
	msumres(A,B,1);

	printf("Resta de A y B\n");
	msumres(A,B,-1);

	printf("Multiplicación de A y B\n");
	mmult(A,B);

	printf("Determinante de A\n");
	det(A);
	printf("\n");
	printf("\n");
	printf("Transpuesta de B\n");
	tran(B);
}

void cons(int X[3][3],int d){
	int consA[3][3];
	for(int x=0;x<3;x+=1){
		for(int y=0;y<3;y+=1){
			consA[x][y]=d*X[x][y];
		}
	}
	mimp(consA);
}

void msumres(int X[3][3], int Y[3][3],int val){
	int AB[3][3];
	for(int x=0;x<3;x+=1){
		for(int y=0;y<3;y+=1){
			AB[x][y]=X[x][y]+val*Y[x][y];
		}
	}
	mimp(AB);
}

void mmult(int X[3][3], int Y[3][3]){
	int AmB[3][3];
	for(int x=0;x<3;x+=1){
		for(int y=0;y<3;y+=1){
			AmB[x][y]=X[x][0]*Y[0][y]+X[x][1]*Y[1][y]+X[x][2]*Y[2][y];
		}
	}
	mimp(AmB);
}

void det(int X[3][3]){
	int DET=0;
	for(int x=0;x<3;x+=1){
		int a=(1+x)%3;
		int b=(2+x)%3;
		DET=DET+X[0][x]*(X[1][a]*X[2][b]-X[1][b]*X[2][a]);
	}
	printf("%d",DET);
}

void tran(int X[3][3]){
	int T[3][3];
	for(int x=0;x<3;x+=1){
		for(int y=0;y<3;y+=1){
			T[x][y]=X[y][x];
		}
	}
	mimp(T);
}



void mimp(int X[3][3]){
	for(int x=0;x<3;x+=1){
		for(int y=0;y<3;y+=1){
			int coord=X[x][y];
			printf("%d  ",coord);
		}
		printf("\n");
	}
	printf("\n");
}
