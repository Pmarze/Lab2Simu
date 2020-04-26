/*
Autor: pmarze
Compilador: 9.2.1
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
#define EPS 0.000001	

float a=0.5;
float b=3.0;
float fun(float);
float biseccion(float,float);

void main(){
    printf("raiz del polinomio= %f \n", biseccion(a,b));
}


float fun(float x){
    float res;
    res= 
//    res = pow(x,3)-2*pow(x,2)-3*x+10;
    return res;
}

float biseccion(float a, float b){
    float p=(a+b)/2;
    int n=0;
    if (fabs(fun(p))-0<EPS || n<300){
        printf("Raiz encontrada");
        return p;
    }
    else if (fun(a)*fun(p)>0){
        printf("%f p por a\n",fun(p));
        n++;
        biseccion(p,b);
    }
    else{
        printf("%f p por b\n",fun(p));
        n++;
        biseccion(a,p);
    }
}