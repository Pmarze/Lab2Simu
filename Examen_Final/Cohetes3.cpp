#include <iostream>
#include "stdlib.h"
#include "math.h"
#include "Clase.h"

using namespace std;

const float G=6.693e-11;
const float RT=6.378e6;
const float MT=5.9736e24;
const float R=287.06;
const float L=6.5*10e-3;
const float g0=9.81;
const float T0=288.15;
const float P0=101325;

float h=0.5;
float Tfinal=30*60;
double t=0;
double y=0;
double v=0;

double kuta(double,double);


int main(){
    Cohete C1;
    C1.SetCaracteristicas(3e7,3.284e-4,61.27,201.6,1.1e5,1.5e6);
    
    double M=C1.Getm_0();
    double TSFC=C1.GetTSFC();
    double E0=C1.GetE0();
    double CD=C1.GetCD();
    double A=C1.GetA();
    
    double w=0;           //Para runge-kutta
    while(t<3){
///////////////////////////////////////////////////////////////////////////////////
        //Runge-kutta parte 1
        double masa=M-TSFC*E0;
        M=masa;
        double gravedad=(G*MT)/pow(RT+w,2);
        double densidad=(P0/(R*T0))*pow(1-(L*w)/T0,(g0)/(R*L));
        double friccion=(densidad/2)*CD*A*v*abs(v);
        double funcion=(E0-friccion-masa*gravedad)/masa;

///////////////////////////////////////////////////////////////////////////////////
        //Constante K1
        double K1=h*funcion;
        cout<< funcion<<endl;
        t+=(h/2);                                               //Todos los valores de cout coinciden
 
        w=w+(K1/2);
///////////////////////////////////////////////////////////////////////////////////
        //Runge-kutta parte 2
        gravedad=(G*MT)/pow(RT+w,2);                            // Bien
        densidad=(P0/(R*T0))*pow(1-((L*w)/T0),(g0)/(R*L));
        friccion=(densidad/2)*CD*A*v*abs(v);
        funcion=(E0-friccion-masa*gravedad)/masa;
         double K2=h*funcion;
///////////////////////////////////////////////////////////////////////////////////
        //Salida
        y=w+K2;
        cout <<"valor y:"<< y<<endl;
        v=K1;
        cout<<"Valot K1:"<< K1<<endl;
        w=y;
        cout<<"\n"<<endl;

    }

}



