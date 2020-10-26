int PotF=A0;      // Potenciómetro para variar la frecuencia
int PotA=A1;      // Potenciómetro para variar la amplitud
int PotO=A2;      // Potenciómetro para seleccionar que canal se desea ver en el modo osciloscopio
int ModP=0;       // Variable para el modo del osciloscopio
int EstO=1;       // Estado que se muestra en el osciloscopio
int Freq=0;       // Variable para la frecuencia
int Ampl=0;       // Variable para la amplitud
int Onda1=11;     // Pin de salida onda cuadrada de 12V
int Onda2=10;     // Pin de salida onda cuadrada de 5V
int Onda3=9;      // Pin de salida onda triangular de 5V
int Can1=0;       // Variable de salida Canal 1
int Can2=0;       // Variable de salida Canal 2
int Can3=0;       // Variable de salida Canal 3

void setup() {
  Serial.begin(9600);       // Inicializar la comunicación Serial
}

void loop() {

  Ampl= analogRead(PotA);   // Lectura del potenciometro de Amplitud
  ModP= analogRead(PotO);   // Lectura del potenciometro de Osciloscopio
  
  for(int i=0;i<255;i++){   // Las 3 ondas se generan en el mismo ciclo for
    Freq= analogRead(PotF); // La frecuencia se puede variar mientras se esté generando
                            // la señal de salida
    Can1=Ampl/4;            // Ya que la amplitud se lee en 1024 y la salida es 255, se divide
                            // dentrod e 4 para que quede un número permitido en el ciclo
    Can2=Ampl/4;            // para el canal 2 se genera de forma similar
    Can3=i;                 // En el canal 3 se estará generando la onda cuadrada, por lo que 
                            // tenemos un valor creciente de magnitud 1
    analogWrite(Onda1, Can1);   // La onda 1 tiene un valor Definido que coincide con la amplitud
                                // este valor se envía por PWM
    analogWrite(Onda2, Can2);   // La onda 2 tiene un valor definido que coincide con la amplitud
    // Onda triangular
    analogWrite(Onda3, Can3);   // La onda 3 tiene como salida una onda triangular con una amplitud 5V
    delay(Freq/2);              // La frecuencia la definimos por medio del potenciometro, esta puede
                                // esta puede variar a lo largo del ciclo
    Estado();                   // Corroboramos el estado del potenciometro y selecciona 
                                // el valor correspondiente                              
    Oscil();                    // Segun el estado del potenciometro, se estará mostrando la gráfic
                                // correspondiente en el Serial Plotter
  }
  for(int i=0;i<255;i++){       // La parte baja de las 3 ondas se realiza en el mismo ciclo for
    Freq= analogRead(PotF);     // La frecuencia se puede variar mientras se esté generando
                                // la señal de salida
    Can1=0;                     // Ya que es una onda cuadrada, para el canal 1 se manda un 0 cte
    Can2=0;                     // Para el canal 2 se envía una señal similar al canal 1
    Can3=(255-i);               // Como estamos realizando un conteo ascendente, se debe hacer
                                // una correción para el descenso de la onda cuadrada, este valor 
                                // se obtiene como 255 (valor máximo) - i( valor del conteo)
    analogWrite(Onda1, Can1);      // Se envía por PWM la señal de salida
    analogWrite(Onda2, Can2);      // Se envía por PWM la señal de salida
    // Onda triangular
    analogWrite(Onda3, Can3);     // La onda 3 tiene como salida una onda triangular con una amplitud 5V
    delay(Freq/2);                // La frecuencia se define por el ptenciometro
    Estado();                   // Corroboramos el estado del potenciometro y selecciona 
                                // el valor correspondiente                              
    Oscil();                    // Segun el estado del potenciometro, se estará mostrando la gráfic
                                // correspondiente en el Serial Plotter
  } 
}

void Estado(){          // Función para saber en cual de los 3 estados se encuentra el potenciometro
  if(ModP<341){         // El potenciometro tiene una señal de 1024, por lo que al querer 3 secciones
                        // fijamos que cada sección tiene 341 bits asignados
    EstO=1;             // Si se cumple la condición, estamos en el estado 1
  } 
  if(ModP>341&&ModP<682){
    EstO=2;             // Si se cumple la condición, estamos en el estado 2
  }
  if(ModP>682){
    EstO=3;             // Si se cumple la condición, estamos en el estado 3
  }
}

void Oscil(){           // Función para representar como "osciloscopio" uno de los 3 canales
  if(EstO==1){          // Si en la función Estado obtuvimos un valor de 1,
  Serial.println(Can1); // se estará mostrando en el Serial Plotter la señal cuadrada de 5V
  }
  if(EstO==2){          // Si en la función Estado obtuvimos un valor de 2,
  Serial.println(Can3); // se mostrará la señal cuadrada, esto para que la señal triangular
                        // esté ubicada entre las dos señales cuadradas, y podamos saber así
                        // en cual de las dos señales cuadradas nos encontramos
  }  
  if(EstO==3){          // Si en la función Estado obtuvimos un valor de 3,
  Serial.println(Can2); // se estará mostrando la señal que será amplificada por un transistor
  }                     // a 12V
}
