/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Minimos_cuadrados.c -o Minimos_cuadrados
Fecha: lun abr 20 22:26:49 CST 2020
librerias: stdio, mat.h
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
//{Estatura (pulgadas) , Peso (libras)}
float persona[12][2]={{70,155},{63,150},{72,180},{60,135},{66,156},{70,168},{74,178},{65,160},{62,132},{67,145},{65,139},{68,152}};
float m();
float b();


void main(){
    int n;
    float pend,con;
    printf("Ingrese una altura de una persona: ");
    scanf("%d",&n);
    __fpurge(stdin);        // Se limpia el buffer para evitar ingreso de datos errados
    pend=m(persona);
    con=b(persona);
    printf("%f,%f \n",pend,con);

}

float m(float a[12][2]){
    float m1=0, m2=0, m3=0, m4=0;
    for (int i=0;i<12;i++){
        m1+=a[i][0]*a[i][1];
        m2+=a[i][0];
        m3+=a[i][1];
        m4+=pow(a[i][0],2);
    }
    return (12*m1-(m2*m3))/(12*m4-pow(m2,2));
}

float b(float a[12][2]){
    float b1=0, b2=0;
    for (int i=0;i<12;i++){
        b1+=a[i][1];
        b2+=a[i][0];
    }
    return (b1-3.2156*b2)/12;
}
