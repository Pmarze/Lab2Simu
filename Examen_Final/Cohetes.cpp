/*
Autor: pmarze
Compilador: 9.2.1
Compilado: gcc Cohetes.cpp -o Cohetes
Fecha: mié may 20 09:43:23 CST 2020
librerias: iostream, 
Resumen: Se realiza el análisis del comportamiento de la trayectoria vertical del cohete espacial.
Entrada:  Ninguna
Salida: Altura máxima alcanzada, Instante en el que se agota el combustible, Instante de tiempo en el que se produce el impacto en el suelo.
*/

#include <iostream>
#include "stdlib.h"
#include "math.h"
#include "Clase.h"
#include "funciones.h"

using namespace std;

float h=0.01;
float Tfinal=30*60;
float t=0;
double v1=0;
double v2=0;
double v3=0;
double z1=0;
double z2=0;
double z3=0;
float mf=0;
float v=0;

double K(float,double);

int main(){
    
    Cohete C1,C2,C3;
    
    C1.SetCaracteristicas(3*pow(10,7),3.248*pow(10,-4),61.27,201.06,1.1*pow(10,5),1.5*pow(10,6));
    
    C2.SetCaracteristicas(2.7*pow(10,7),2.248*pow(10,-4),61.27,201.06,1.1*pow(10,5),1.5*pow(10,6));
    
    C3.SetCaracteristicas(2.5*pow(10,7),2.248*pow(10,-4),70.25,215.00,1.8*pow(10,5),2.1*pow(10,6));

        double E1,E2,E3;
        int B1=1;
        int B2=1;
        int B3=1;

    while(t<3){
        

        E1=C1.GetE0()*B1;
        E2=C2.GetE0()*B2;
        E3=C3.GetE0()*B3;

        double M1,M2,M3;
        M1=Mc(C1.Getm_0(),t,C1.GetTSFC(),E1);
        M2=Mc(C2.Getm_0(),t,C2.GetTSFC(),E2);
        M3=Mc(C3.Getm_0(),t,C3.GetTSFC(),E3);
        if (M1<=0){
            B1=0;
        }
        if (M2<=0){
            B2=0;
        }
        if (M3<=0){
            B3=0;
        }
        
        cout << ro(z1)<< endl;
        cout << Fa(ro(z1),C1.GetCD(),C1.GetA(),v1) << endl;
        cout << "\n" << endl;

        double funcion1=E1-Fa(ro(z1),C1.GetCD(),C1.GetA(),v1)-Mc(C1.Getm_0(),t,C1.GetTSFC(),E1)*g(z1);
        double funcion2=E2-Fa(ro(z2),C2.GetCD(),C2.GetA(),v2)-Mc(C2.Getm_0(),t,C2.GetTSFC(),E2)*g(z2);
        double funcion3=E3-Fa(ro(z3),C3.GetCD(),C3.GetA(),v3)-Mc(C3.Getm_0(),t,C3.GetTSFC(),E3)*g(z3);

        double K11=K(h,funcion1);
        double K12=K(h,funcion2);
        double K13=K(h,funcion3);


        double funcion11=E1-Fa(ro(z1+(K11/2)),C1.GetCD(),C1.GetA(),v1)-Mc(C1.Getm_0(),t+0.5*h,C1.GetTSFC(),E1)*g(z1+(K11/2));
        double funcion12=E2-Fa(ro(z2+(K12/2)),C2.GetCD(),C2.GetA(),v2)-Mc(C2.Getm_0(),t+0.5*h,C2.GetTSFC(),E2)*g(z2+(K12/2));
        double funcion13=E3-Fa(ro(z3+(K13/2)),C3.GetCD(),C3.GetA(),v3)-Mc(C3.Getm_0(),t+0.5*h,C3.GetTSFC(),E3)*g(z3+(K13/2));

        double K21=K(h,funcion11);
        double K22=K(h,funcion12);
        double K23=K(h,funcion13);

        v1=v1+(1/6)*K11;
        v2=v2+(1/6)*K11;
        v3=v3+(1/6)*K11;
        
        
        z1=z1+(1/6)*(K11+2*K21);
        z2=z2+(1/6)*(K12+2*K22);
        z3=z3+(1/6)*(K13+2*K23);

        
        cout << z1<<endl;
        cout << v1<<endl;
        t=t+1;
    }
    
    return 0;
}


double K(float h, double funcion){
    return h*funcion;
}



