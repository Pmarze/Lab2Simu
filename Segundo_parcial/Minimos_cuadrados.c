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
#include <stdlib.h>

float mr,br;

//{Estatura (pulgadas) , Peso (libras)}
float persona[12][2]={{70,155},{63,150},{72,180},{60,135},{66,156},{70,168},{74,178},{65,160},{62,132},{67,145},{65,139},{68,152}};
float m();
float b1();
float b2();


void main(){
    FILE *pf;
    char* nombre= "min_cuadrados";
    char* modo= "wt";

    if((pf=fopen(nombre,modo))==NULL){
        puts("Problemas de escritura");
    }
    else{
        int n;
        printf("Ingrese una altura de una persona: ");
    
        scanf("%d",&n);
        __fpurge(stdin);        // Se limpia el buffer para evitar ingreso de datos errados 
    
        mr=m(persona);
        br=b1(persona)-mr*b2(persona);
  
        int i=0;
        while(i<12){    
            fprintf(pf,"%.2f  %.2f \n",persona[i][0],persona[i][1]);
            i++;
        } 

        printf("El peso de la persona es: %.2f \n", mr*n+br);
    }
    fclose(pf);
    
    FILE *p = popen("gnuplot","w");
    fprintf(p,"reset \n");
    fprintf(p,"set title 'Minimos cuadrados' \n");
    fprintf(p,"set xlabel 'Estatura'\n");
    fprintf(p,"set ylabel 'Peso' \n");
    fprintf(p,"set xrange [55:80] \n");
    fprintf(p,"set yrange [120:200] \n");
    fprintf(p,"plot %f*x+(%f), 'min_cuadrados' \n",mr,br);
    pclose(p);
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

float b1(float a[12][2]){
    float b1=0;
    for (int i=0;i<12;i++){
        b1+=a[i][1];
    }
    return b1/12;
}
float b2(float a[12][2]){
    float b1=0;
    for (int i=0;i<12;i++){
        b1+=a[i][0];
    }
    return b1/12;
}