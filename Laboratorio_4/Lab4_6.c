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
long long int n;	// Definimos una variablo long long int para que se puedan obtener resultados más grandes
long long int S1();	// La función S1 trabaja solo con enteros, para mayores calculos, usamos long long int
long double S2();	// La función S2 trabaja con tipo float, para obtener un resultado mayor utilizamos long double
long double S3();	// La función S3 trabaja con tipo float, para obtener un resultado mayor utilizamos long double
long long int S4();	// En la sucesión aparece un termino 0.1, ya que este es cte a toda la sumatoria podemos
			// escribirla como 0.1*sucesión, con esta separación obtenemos una función que trabaja solo
			// con enteros, por ello podemos utilizar la función de tipo long long int

void main(){
	printf("Ingrese un número n: ");
	scanf("%lli",&n);	// El usuario ingresa un número n
	__fpurge(stdin);	// Limpiamos el buffer para evitar el ingreso de datos erróneos
	
	long double a=(long double)n;	// Hacemos una conversión de long long int a long double, esto nos
					// servirá más adelante como parámetro de algunas funciones

	if (n<=102570 && n>1){		// Se encontró que el S1() tiene un rango de operación, por ello
					// restringimos el rango de n, si n no pertenece, entonces no se realiza
					// el cálculo
		printf("Resultado primer sumatoria\n");		// Maximo calculado correctamente n=102,570 
		printf("%lli \n",S1(n));			// El dato a mostrar es un Long Long int
		printf("\n");		
	}
	else{				// Si n no pertenece al rango se muestra que no es posible realizar el cálculo
		printf("No es posible calcular la sucesión,\n");
		printf("está fuera del rango [1,102570]\n");
		printf("\n");
	}
	
	if (n<=130899 && n>2){ 		// Se encontró que el S2() tiene un rango de operación, por ello
                                        // restringimos el rango de n, si n no pertenece, entonces no se realiza
                                        // el cálculo

		printf("Resultado segunda sumatoria\n");	//Maximo calculado correctamente n=130,899
		printf("%Lf \n",S2(a,n));			// El dato a mostrar es un Long Double
		printf("\n");
	}
	else{				// Si n no pertenece al rango se muestra que no es posible realizar el cálculo
		printf("No es posible calcular la sucesión,\n");
		printf("Esta fuera del rango [2,130899]\n");
		printf("\n");
	}

	printf("Resultado de la sucesión\n");	// Esta sucesión es divergente, C automáticamente advierte de esto
	printf("%Lf \n",S3(a,n));		// por lo que no tenemos restricción alguna con S3
	printf("\n");
	
	if (n<=62 && n>1){		// Se encontró que el S2() tiene un rango de operación, por ello
                                       	// restringimos el rango de n, si n no pertenece, entonces no se realiza
                                       	// el cálculo
		printf("Resultado sucesión de Bode\n");	//Máximo calculado correctamente n=62
		long double Bode=0.1*S4(n); 	// Multiplicamos S4()*0.1 ya que es el término que sacamos de la sucesión
		printf("%Lf \n",Bode);		// El multiplicar un long long int por 0.1 lo vuelve de punto flotante	
		printf("\n");			// es por ello que la variable donde almacenamos este dato es de tipo long double
	}
	else{				// Si n no pertenece al rango se muestra que no es posible realizar el cálculo
		printf("No es posible calcular la sucesión de Bode,\n");
		printf("Esta fuera del rango [2,60]\n");
		printf("\n");
	}
}


long long int S1(long long int x){	// Esta función tiene como parámetro un long long int
	if (x==1){			// El valor mínimo x de la sucesión es 1, con un valor de -2
		return -2;		// Se retorna el valor del último termino de la sucesión
	}
	else{				// Si la función no se encuentra en el último término de la sucesión
		return 	pow(x,2)*(x-3)+S1(x-1);	// Suma el valor del término actual más el valor de S1(x-1)
	}
}

long double S2(long double x, long long int n){	// Esta función tiene como parámetro dos números de distinto tipo
					// el comportamiento de x y n es el mismo, ya que de igual manera tenemos
					// que definir ambas variables, aprovechamos esto y no ahorramos el 
					// proceso extra de condicionales de punto flotante, el único uso de el
					// entero n poder hacer una comparación con if
	if (n==2){			// El valor mínimo x de la suceción es 2, con un valor de 3,
		return 3;		// Se retorna el valor del último término de la sucesión
	}
	else{				// Si la función no se encuentra en el último término de la sucesión
		return (3/(x-1))+S2(x-1,n-1);	// Suma el valor del término actual más el valor de S2(x-1,n-1)
	}
}

long double S3(long double x, long long int n){ // Esta función tiene como parámetro dos numeros de distinto tipo
	if (n==1){				// La estructura es similar a S2()
		return 1;			// El valor mínimo x de la sucesión es 1, con un valor de 1
	}
	else{
		long double a=(1/sqrt(5))*(pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n));
		return a+S3(x-1,n-1);
	}
}
long long int S4(long long int x){		// Esta función tiene como parámetro un long long int
	if (x==2){				// La estructura es similar a S1()
		return 7;			// El valor mínimo x de la suceción es 2, con un valor de 7
	}
	else{
		return 	(3*pow(2,x-2)+4)+S4(x-1);
	}
}
