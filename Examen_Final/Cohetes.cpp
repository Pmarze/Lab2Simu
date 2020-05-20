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
#include "Clase.h"

using namespace std;




int main(){
    Cohete C1;
    C1.SetCaracteristicas(1,2,3,4,5,6);
    cout << C1.Getm_0() << "," << C1.GetejeCohete() << endl;
    return 0;
}