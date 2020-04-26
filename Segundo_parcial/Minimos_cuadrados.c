/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Minimos_cuadrados.c -o Minimos_cuadrados
Fecha: lun abr 20 22:26:49 CST 2020
librerias: stdio, mat.h, stdio_ext.h stdlib.h
Resumen: El programa genera una gráfica que compara los 
valores tabulados y la recta que mejor aproxima el 
crecimiento de los datos ingresados. 
Estima el peso de cualquier persona en base a su altura
Entrada:  altura de una persona
Salida: El peso de esa persona
*/

#include <stdio.h>
#include <math.h>
#include <stdio_ext.h>
#include <stdlib.h>

float mr,br;            // Definimos como variables globales por practicidad mr es la
			// pendiente y br la constante de la ecuación de min. cuadrados

//{Estatura, Peso} 	// Se trabaja como un array para generalizar, si se desea analizar otro
			// conjunto de datos, es posible agregando un arreglo con la misma forma
float persona[12][2]={{70,155},{63,150},{72,180},{60,135},{66,156},{70,168},{74,178},{65,160},{62,132},{67,145},{65,139},{68,152}};
float m();		// Función m para calcular la pendiente
float b1();		// Función b1 para calcular sumatoria de y_i/12
float b2();		// Función b2 para calcular sumatoria de x_i/12
			// b1 y b2 son necesaria para calcular el término b de la ecuación,
			// si se trata de calcular de forma similar a m, el proceso se vuelve
			// más complicado.

void main(){
    FILE *pf;				// Definimos el puntero de nuestro archivo
    char* nombre= "min_cuadrados";	// Llamamos a nuestro archivo min_cuadrados
    char* modo= "wt";			// Estamos trabajando en modo escritura	

    if((pf=fopen(nombre,modo))==NULL){	// Si hay un error de lectura se detiene el proceso
        puts("Problemas de escritura");
    }
    else{				
        float n;			// Definimos n como la altura a analizar
        printf("Ingrese una altura de una persona: ");
    
        scanf("%f",&n);			// Se lee el número ingresado por el usuario
        __fpurge(stdin); 	        // Se limpia el buffer para evitar ingreso de datos errados 
    
        mr=m(persona);			// Asignamos a mr el valor de la pendiente del arreglo "persona"	
        br=b1(persona)-mr*b2(persona);	// Calculamos la constante según la ecuación de mínimos cuadrados
  
        int i=0;			
        while(i<12){    		// Se escribe en el archivo min_cuadrados cada punto (x,y) de "persona"
            fprintf(pf,"%.2f  %.2f \n",persona[i][0],persona[i][1]);
            i++;			// El ciclo debe repetirse 12 veces, i+1 para que el ciclo avance
        } 

        printf("El peso de la persona es: ");	// Se muestra en pantalla el peso correspondiente a la altura
	printf("%.2f \n",mr*n+br);		// ingresada por el usuario
    }
    fclose(pf);				// Se cierra el archivo min_cuadrados
    	
    FILE *p = popen("gnuplot","w");	// popen() permite trabajar en gnuplot, w para modo write,
    					// *p es nuestro puntero de archivo
  					// El comando fprintf(p,"..."); permite escribir comandos en gnuplot
    fprintf(p,"reset \n");		// Borramos cualquier configuración previa que pudiera tener gnuplot
    fprintf(p,"set title 'Minimos cuadrados' \n");		// Se define el título del gráfico
    fprintf(p,"set xlabel 'Estatura'\n");	// Se define el título del eje x
    fprintf(p,"set ylabel 'Peso' \n");		// Se define el título del eje y
    fprintf(p,"set xrange [55:80] \n");		// Se define el rango del eje x
    fprintf(p,"set yrange [120:200] \n");	// Se define el rango del eje y
    fprintf(p,"plot %f*x+(%f), 'min_cuadrados' \n",mr,br);	// Se plotea simultáneamente la línea que mejor
    								// se aproxima a nuestros puntos y también
								// todos los puntos almacenados en min_cuadrados
    pclose(p);				// Se cierra gnuplot y deja nuestra gráfica en pantalla
}

float m(float a[12][2]){		// Función para calcular m
    float m1=0, m2=0, m3=0, m4=0;	// Definimos m1,m2,m3,m4 para representar cada sumatoria de la ecuación
    for (int i=0;i<12;i++){		
        m1+=a[i][0]*a[i][1];		// m1=sumatoria de xk*yk
        m2+=a[i][0];			// m2=sumatoria de xk
        m3+=a[i][1];			// m3=sumatoria de yk
        m4+=pow(a[i][0],2);		// m4=sumatoria de xk^2
    }
    return (12*m1-(m2*m3))/(12*m4-pow(m2,2)); //ecuación para calcular m
}

float b1(float a[12][2]){		// Función para calcular la primera mitad de b
    float b1=0;			
    for (int i=0;i<12;i++){
        b1+=a[i][1];			// b1=sumatoria de yk
    }
    return b1/12;			// b1/n con n=12
}
float b2(float a[12][2]){		// Función para calcular la segunda mitad de b sin el factor m
    float b1=0;				
    for (int i=0;i<12;i++){	
        b1+=a[i][0];			// b1=sumatoria de xk
    }	
    return b1/12;			// b1/n con n=12
}
