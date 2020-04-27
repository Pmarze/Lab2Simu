/*
Compilador: 9.2.1
Autor: pmarze
Compilado: gcc Biseccion.c -o Biseccion
Fecha: lun abr 20 22:29:32 CST 2020
librerias: stdio, math.h
Resumen: Se encuentra la raíz de la función 
x^3-2x^2-3x+10 por medio del método de bisección.
Entrada:  Ninguna
Salida: Gráfica de la ecuación
*/

#include <stdio.h>
#include <math.h>
#include <stdio_ext.h>
#define EPS 0.0000001	// Definimos EPS como la precisión deseada

float a=-2.5;		// Límite inferior de nuestro rango a analizar
float b=-1.0;		// Límite superior de nuestro rango a analizar
double fun(double);	// Función que define el polinomio a analizar
double biseccion(double,double,int,int);	// Función que realiza el método de bisección
			//(límite inferior, Límite superior, Iteración actual, Máximo de Iteraciones)
void gplot();		// Función para crear una gráfica en Gnuplot

void main(){
    gplot();		// Se obtiene una gráfica de Gnuplot con el polinomio correspondiente
    printf("raiz del polinomio= %lf \n", biseccion(a,b,0,100));	// Límites a y b, iteración inicial=0, iteración máxima=100
}

double fun(double x){			// Función para definir un polinomio cualquiera
    double res; 	
    res = pow(x,3)-2*pow(x,2)-3*x+10; 	// Polinomio x^3-2x^2-3x+10
    return res;				// Regresa el valor del polinomio ya valuado
}	

double biseccion(double a, double b, int c, int d){	// Función para implementar el método de Bisección
    double p=(a+b)/2;			// Se calcula el punto medio p del intervalo
    int n=c;				// Valor actual de la iteración
    if (n==d){				// Si la iteración actual es igual a la iteración que se definió como
	    				// máxima, se muestra el valor actual de p, sea o no raíz del polinomio
        printf("Máximo de iteraciones, no se obtuvo una respuesta con la precisión deseada,\n");
        printf("el resultado presentado a continuación puede no ser raíz del polinomio.\n");
        printf("\n");
        return p;
    }
    
    if (fabs(fun(p))-0<EPS){		// Si al restar 0 del valor absoluto del polinomio valuado en p
	    				// se obtiene que es menor que nuestra precisión, entonces este se 
					// mostrará como cero que es justamente el resultado deseado
        printf("Iteraciones realizadas= %d \n",n);	// Nos muestra cuantas iteraciones se necesitaron
        return p;					// para encontrar el valor deseado.
    }
					// En caso de que el valor no sea la raiz, tenemos dos posibles casos
    else if (fun(a)*fun(p)>0){		// si el valor en el punto a * el valor en el punto medio es mayor a 0
        n++;				// se debe valuar bisección en el intervalo [p,b], el número de iteracion crece 1
        biseccion(p,b,n,d);
    }
    else{				// Para cualquier otro caso el intervalo a analizar es [a,p]
        n++;
        biseccion(a,p,n,d);
    }
}

void gplot(){
    FILE *p = popen("gnuplot","w");	// popen() permite trabajar en gnuplot, w para modo write,
    					// *p es nuestro puntero de archivo
  					// El comando fprintf(p,"..."); permite escribir comandos en gnuplot
    fprintf(p,"reset \n");		// Borramos cualquier configuración previa que pudiera tener gnuplot
    fprintf(p,"set title 'Método de Bisección' \n");		// Se define el título del gráfico
    fprintf(p,"set xlabel 'x' \n");	// Se define el título del eje x
    fprintf(p,"set ylabel 'f(x)=x^3-2x^2-3x+10' \n");	// Se define el título del eje y
    fprintf(p,"set yrange [-5:15] \n");		// Rango en x para la gráfica a generar
    fprintf(p,"set xrange [-5:5] \n");		// Rango en y para la gráfica a generar
    fprintf(p,"set grid\n");			// Cuadrícula para observar mejor los datos
    fprintf(p,"set term png \n");		// Defnimos la terminal como png, para crear un gráfico de los datos
    fprintf(p,"set key bottom right \n");	// Cambiamos la posición de key
    fprintf(p,"set output 'biseccion.png' \n"); // La imagen obtenida se guarda con el nombre minimos.png
    fprintf(p,"plot x**3-2*x**2-3*x+10 \n");	// Se plotea simultáneamente la línea que mejor
						// se aproxima a nuestros puntos y también
						// todos los puntos almacenados en min_cuadrados   
    pclose(p);				// Se cierra gnuplot
}
