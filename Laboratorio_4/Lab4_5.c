/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Lab4_5.c -o Lab4_5
Fecha: mié mar 25 20:58:35 CST 2020
librerias: stdio, 
Resumen: Se ingresa un entero y el programa devuelve el factorial de ese número
Entrada:  un entero
Salida: un entero
*/

#include <stdio.h>
#include <stdio_ext.h>
long unsigned int n;		// Entero n al que se le calculará el factorial
long unsigned int fact();	// Función de tipo entero para poder multiplicarla
				// reiteradas veces, es de tipo long unsigned para poder 
				// calcular un n factorial más grande

void main(){			
	printf("Ingrese un entero (n max=20) n= ");
	scanf("%lu",&n);		// El número ingresado es almacenado en la variable n
					// Utilizamos %lu por ser un long unsigned
	__fpurge(stdin);		// Limpiamos el buffer para evitar ingreso de datos erróneos
	if(n>20){			// Si el número es mayor a 20 por limitaciones de memoria el 
					// resultado es erróneo, por lo que no permitimos estos números
		printf("Este número sobrepasa el límite establecido \n");
	}
	else{
		printf("n!= ");				
		printf("%lu \n",fact(n));	// Se imprime el resultado de la función factorial
	}
}

long unsigned int fact(long unsigned int x){	// Función fact sobre un entero 
	if(x==0){				// Si x=0 tenemos dos casos posibles, el valor n que ingresaron
						// era 0 o por recursividad llegamos hasta el número cero
		return 1;			// para ambos casos la función regresa un número 1, esto para cumplir
	}					// la condición de que 0! es 1
	else{					// Para cualquier otro valor de x 	
		return x*fact(x-1);		// la función regresa x multiplicado por el resultado de la fact(x-1)
	}
}
