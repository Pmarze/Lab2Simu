#include <math.h>       // Resolver calculos numéricos
#include "DHT.h"        // Librería para usar el sensor DHT11
#define DHTPIN1 3       // El sensor 1 se conectará en el pin digital 3
#define DHTPIN2 4       // El sensor 2 se conectará en el pin digital 4
#define DHTTYPE DHT11   // El sensor a utilizar es DHT11

float vcc = 5.02;       // Voltaje con el que se alimenta el circuito 
                        //(medir a la hora de conectar todos los componente y luego introducir el valor acá)
float tem0 = 298.0;     // Temperatura de referencia (0 °C en Kelvin)
float Pot1 = 4540.0;    // Valor del potenciómetro de ajuste del sensor 1(máx 5k)
float Pot2 = 4100.0;    // Valor del potenciómetro de ajuste del sensor 2(máx 5k)
float bet1 = 3777.0;    // Valor de beta del sensor 1
float bet2 = 4900.0;    // Valor de beta del sensor 2
                        // (El valor de beta varía por el proceso de fabricación, puede ajustarse para valores
                        // según el fabricante)
float r01 = 1000.0;     // Resistencia base del transistor NTC 1
float r02 = 1000.0;     // Resistencia base del transistor NTC 2

float vm1 = 0.0;             // Voltaje de entrada 1
float vm2 = 0.0;             // Voltaje de entrada 2
float ntc1 = 0.0;            // Resistencia calculada del NTC 1
float ntc2 = 0.0;            // Resistencia calculada del NTC 2
float temp1 = 0.0;           // Temperatura inicial 1
float temp2 = 0.0;           // Temperatura inicial 2
int   t = 15;                // Intervalo de tiempo para registrar datos

DHT dht1(DHTPIN1, DHTTYPE);   // Configuración del DHT11 1
DHT dht2(DHTPIN2, DHTTYPE);   // Configuración del DHT11 2

void setup() {
  Serial.begin(9600);         
  dht1.begin();               // Se inicia el sensor DHT11 1
  dht2.begin();               // Se inicia el sensor DHT11 1
}

void loop() {
  TEMPAD();                   // Función para registrar los dos sensores internos
  Serial.print(", ");         // Valores separados por coma (CSV)
  TEMPAF();                   // Función para registrar los dos sensores externos
  Serial.println("");         // Los datos se toman como CSV, salto de línea para el siguiente registro
  delay(t*1000);              // Intervalod e tiempo en el que se registrarán los datos.
}

void TEMPAD(){                        // Función para medir los sensores internos
 float t1 = dht1.readTemperature();   // Se le asigna a t1 el valor del DHT1 
 vm1 = (vcc/1024)*(analogRead(0));    // Calcula el voltaje de entrada en el pin A0
 ntc1 = Pot1/((vcc/vm1)-1);           // Calcula la resistencia del NTC
 temp1 = bet1/(log(ntc1/r01)+(bet1/tem0));  // Calcula la temperatura en Kelvin
 Serial.print(t1);                    // Imprime el valor del sensor DHT11 
 Serial.print(", ");                  // Valores separados por coma (CSV)    
 Serial.print(temp1-273);             // Imprime el valor del sensor NTC
}

void TEMPAF(){                        // Función para medir los sensores externos
  float t2 = dht2.readTemperature();  // Se le asigna a t2 el valor del DHT11
  vm2 = (vcc/1024)*(analogRead(1));   // Calcula el voltaje de entrada en el pin A1
  ntc2 = Pot2/((vcc/vm2)-1);          // Calcula la resistencia del NTC
  temp2 = bet2/(log(ntc2/r02)+(bet2/tem0));  //Calcular la temperatura en Kelvin
  Serial.print(t2);                   // Imprime el valor del sensor DHT11
  Serial.print(", ");                 // Valores separados por coma (CSV)
  Serial.print(temp2-273);            // Imprime el valor del sensor NTC
}
