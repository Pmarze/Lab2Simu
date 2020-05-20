#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "stdlib.h"
#include "math.h"

const float G=6.693*pow(10,-11);
const float RT=6.478*pow(10,6);
const float MT=5.9736*pow(10,24);
const float R=287.06;
const float L=6.5*pow(10,-3); 
const float g0=9.81;
const float T0=288.15;
const float P0=101325;

double Mf(int t,double _TSFC,double _E0){
    return -(_TSFC)*(_E0)*t;
}

double Mc(double m_0, int t,double TSFC,double E){
    return m_0+Mf(t,TSFC,E);
}

double g(double y){
    return (G*MT)/pow((RT+y),2);
}

double Fa(double ro,double CD,double A, double V){
    return 0.5*ro*CD*A*V*abs(V);
}


double ro(double y){
    double potencia=(g0/(R*L));
    return P0*pow((1-((L*y)/T0)),potencia)/(R*T0);
}

/*
double E(int t){
    if(t==0){
        return 
    }
}
*/











void pruebaf(){
    cout<< "Si lee funciones.h" <<endl;
}

#endif