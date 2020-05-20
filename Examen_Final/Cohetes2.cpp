#include <iostream>
#include "stdlib.h"
#include "math.h"
#include "Clase.h"

const float G=6.693*pow(10,-11);
const float RT=6.478*pow(10,6);
const float MT=5.9736*pow(10,24);
const float R=287.06;
const float L=6.5*pow(10,-3); 
const float g0=9.81;
const float T0=288.15;
const float P0=101325;

using namespace std;

float h=0.01;
float Tfinal=30*60;
int t=0;
long double v=0;
long double y=0;
float mf=0;

long double K(float,long double);
long double g(long double);
long double Mf(int,long double,long double);
long double ro(long double);
long double Fa(long double,long double,long double,long double);


int main(){
        Cohete C1,C2;
        C1.SetCaracteristicas(3*pow(10,7),3.248*pow(10,-4),61.27,201.06,1.1*pow(10,5),1.5*pow(10,6));
        long double MK1=C1.Getm_0();
        long double MK2=C1.Getm_0();
    while(t<50){




        long double Mft=Mf(t,C1.GetTSFC(),C1.GetE0());
        long double Mct=MK1+Mft;
        MK1=MK1+Mft;
        long double gt=g(y);
        long double roy=ro(y);
        long double Fay=Fa(roy,C1.GetCD(),C1.GetA(),v);

        long double funcion1=(C1.GetE0()-Fay-Mct*gt)/Mct;
        long double K1=K(h,funcion1);   
        
        Mft=Mf(t+0.5*h,C1.GetTSFC(),C1.GetE0());
        Mct=MK2+Mft;
        MK2=MK2+Mft;
        gt=g(y+0.5*K1);
        roy=ro(y+0.5*K1);
        Fay=Fa(roy,C1.GetCD(),C1.GetA(),v);        
        
        long double funcion2=(C1.GetE0()-Fay-Mct*gt)/Mct;
        long double K2=K(t+0.5*h,funcion2);
        v=K1;
 
        y=y+K2; 

        

        cout << "\n" <<endl;
 
    t=t+20;
    }
}


long double K(float h, long double funcion){
    return h*funcion;
}

long double Mf(int t,long double _TSFC,long double _E0){ 
    return -(_TSFC)*(_E0);
}

long double g(long double y){
    return (G*MT)/pow((RT+y),2);
}

long double ro(long double y){
    double potencia=(g0/(R*L));
    return (P0/(R*T0))*pow((1-((L*y)/T0)),potencia);
}

long double Fa(long double ro,long double CD,long double A,long double V){
    return 0.5*ro*CD*A*V*abs(V);
}