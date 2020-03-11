/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc rango_primos.c -o rango_primos
Fecha: mar mar 10 12:59:17 CST 2020
librerias: stdio, 
Resumen: El programa lee dos números enteros para determinar un rango,
luego procede a mostrar todos los números primos que estén en ese rango.
Entrada:  Dos enteros N1,N2
Salida: Imprime el valor de "i" si este es primo
*/

#include <stdio.h>
int N1, N2,i;				//Definimos variables N1,N2 para definir el rango a analizar
int j=2;				//Valor de j=2 para analizar divisibilidad entre 2 hasta i
int Es_primo();				//Definimos que el valor que regresa nuestra función es un entero

void main(){
	printf("Ingrese el valor más pequeño del rango ");
	scanf("%i",&N1);		//N1 es el valor más pequeño de nuestro rango

	printf("Ingrese el valor más grande del rango ");
	scanf("%i",&N2);		//N2 es el valor más grande de nuestro rango

	i=N1;				//asignamos a i el valor de N1 para analizar i en los siguientes pasos
	while(i<=N2){			//si i<=N2 sabemos que aun podriamos dividir i dentro de algún posible número
					//y por eso debemos seguir aplicando Es_primo, si no se cumple esta condicion
					// el proceso termina
		if(Es_primo(i)==1){	//Si Es_primo(i)=1 eso quiere decir que i es un número primo
			printf("%i\n",i);//Al ser un número primo procedemos a imprimilo ne la terminal
		}
		++i;			//i puede ser primo o puede no serlo, en ambos casos sumamos uno a i para
					//ver si i+1 es un número primo dentro del rango
	}
}

int Es_primo(int a ){			//Definimos nuestra función para que al finalizar devuelva un entero
	int primo=1;			//definimos el estado inicial de primo=1, este cambiará si un número divide a "a"
	while(j<a && primo==1){		//estaremos haciendo iteraciones si y solo si j<a y primo=1
		if(a%j==0){		//Si a es divisible por j el modulo a%j será cero y por lo tanto no es primo, 
			primo=0;	//al no ser primo, asignamos el valor cero a la variable primo
		}
		++j;			//independientemente de que sea primo o no sumamos 1 a j para analizar el caso de j+1
	}
	j=2;				//Al terminar de analizar si a es primo, debemos regresar j a su valor 2, sin esto
					//el programa no funciona ya que se queda con el último valor de j antes de salir
					//del ciclo while
	return primo;			//Al finalizar la función nos devuelve el valor de primo, si es 1 sabemos que "a" es primo
					//Si devuelve 0 sabemos que "a" no es primo
}
