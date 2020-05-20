#ifndef USUARIOS_H
#define USUARIOS_H

using namespace std;

class Cohete{
    private:
    double ejeCohete, TSFC, CD, A, m_0, m_f0;
    public:
    Cohete();
    void SetCaracteristicas(double,double,double,double,double,double);
/*
    void SetejeCohete();
    void SetTSFC();
    void SetCD();
    void SetA();
    void Setm_0();
    void Setm_f0();
*/
    double GetejeCohete();
    double GetTSFC();
    double GetCD();
    double GetA();
    double Getm_0();
    double Getm_f0();
};


Cohete::Cohete(){       //Constructor

}

void Cohete::SetCaracteristicas(double _ejeCohete , double _TSFC,double _CD,double _A,double _m_0,double _m_f0){
    ejeCohete=_ejeCohete;
    TSFC=_TSFC;
    CD=_CD;
    A=_A;
    m_0=_m_0;
    m_f0=_m_f0;
}

double Cohete::GetejeCohete(){
    return ejeCohete;
}
double Cohete::GetTSFC(){
    return TSFC;
}
double Cohete::GetCD(){
    return CD;
}
double Cohete::GetA(){
    return A;
}
double Cohete::Getm_0(){
    return m_0;
}
double Cohete::Getm_f0(){
    return m_f0;
}

void prueba(){
    cout<< "Si lee la libreria" <<endl;
}

#endif