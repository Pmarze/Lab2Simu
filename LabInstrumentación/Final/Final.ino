#include <Servo.h>
#include <math.h>
Servo Mov;

const int Trigger = 3;   
const int Echo = 4;   
const int BSET = 13; 
const int BENC = 12;  
const int BPID = 11;
const int BSEL = 10;
const int t=500;
int EstadoArd=1;
int EstMensaje=1;
int EstSelect =0;
int Seleccion=0;
int ValINT=0;
int ValDEC=0;
int Setp=0;
float Kp=6;
float Kd=6.32;
float Ki=1.44;

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT); 
  pinMode(BPID,INPUT);
  pinMode(BSEL,INPUT);
  pinMode(BENC,INPUT);
  pinMode(BSET,INPUT);
  digitalWrite(Trigger, LOW);
  Mov.attach(5);
  Serial.println("Inicio");
}

void loop(){
  BotonENCENDIDO();
  if(EstadoArd==1){
    if(EstMensaje==0){
      EstMensaje=1;
      Serial.println("Encendido");  
    }
    
    BotonSETPOINT();
    BotonKPID(); 
    Botonconfig();
    
  }else{
    if(EstMensaje==1){
      EstMensaje=0;
      Serial.println("Apagado");  
    } 
  }
}


void BotonSETPOINT(){
  if(digitalRead(BSET) == HIGH){
    Seleccion=1;
    Serial.print("Seleccionar punto fijo: ");
    while(Seleccion==1){
        ValDEC = analogRead(A0);
        ValDEC = map(ValDEC, 0, 1023, 0, 10);
        Setp=ValDEC;
        Serial.println(ValDEC);
        delay(t);
        if(digitalRead(BSET)==HIGH){
          Seleccion=0;
          Serial.print("Punto fijo: ");
          Serial.print(Setp);
          Serial.println(" cm");
        }
    }
  }
}

void BotonKPID(){
  if(digitalRead(BPID) == HIGH){
    Seleccion=1;
    Serial.println("Seleccionar Configuración PID: ");
    while(Seleccion==1){
      BotonKPKIKD();
      switch (EstSelect){
        case 0:
          Serial.print("Kp= ");
          Valores(1);
          Serial.println(Kp);
        break;
        case 1:
          Serial.print("Ki= ");
          Valores(2);
          Serial.println(Ki);
        break;
        case 2:
          Serial.print("Kd= ");
          Valores(3);
          Serial.println(Kd);
        break;
        case 3:
            Serial.println("Valores fijados: ");
            Serial.print("Kp: ");
            Serial.println(Kp);
            Serial.print("Ki: ");
            Serial.println(Ki);
            Serial.print("Kd: ");
            Serial.println(Kd);
            EstSelect=0;
            Seleccion=0;
        break;        
      }  
    }
  }
}

void BotonKPKIKD(){
  if(digitalRead(BSEL)==HIGH){
    EstSelect++;
    if(EstSelect==4){
      EstSelect=0;
    }
  }
  delay(t);
}

void BotonENCENDIDO(){
  if(digitalRead(BENC)==HIGH){
    EstadoArd++;
    if(EstadoArd==2){
      EstadoArd=0;
    }
  }
  delay(t);
}

void Valores(int b){
        ValINT = analogRead(A1);
        ValINT = map(ValINT, 0, 1023, 0, 20);
        ValDEC = analogRead(A0);
        ValDEC = map(ValDEC, 0, 1023, 0, 99);
        float a=ValINT+(float(ValDEC))/100;
        switch(b){
          case 1:
            Kp=a;
          break;
          case 2:
            Ki=a;
          break;
          case 3:
            Kd=a;
          break;                    
        }
        delay(t);     
}

void Botonconfig(){
  if(digitalRead(BSEL)==HIGH){
    Serial.println("Configuración actual:");
    Serial.print("Punto fijo: ");
    Serial.print(Setp);
    Serial.println(" cm");
    Serial.print("kp= ");
    Serial.print(Kp);
    Serial.print(", ");
    Serial.print("ki= ");
    Serial.print(Ki);
    Serial.print(", ");
    Serial.print("kd= ");
    Serial.println(Kd);
  }
  delay(t);
}
