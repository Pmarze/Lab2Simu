const int ONF = 2;        // Botón de Encendido/Apagado
const int SW1 = 3;        // Botón de color 1
const int SW2 = 4;        // Botón de color 2
const int SW3 = 5;        // Botón de color 3
const int SW4 = 6;        // Botón de color 4
const int SW5 = 7;        // Botón de color 5
const int SW6 = 8;        // Botón de color 6
const int VER = 9;        // Pin verd del LED
const int AZU = 10;       // Pin azul del LED
const int ROJ = 11;       // Pin rojo del LED

int ESO = 1;              // Estado boton de encendido/apagado
int ESW = 0;              // Estado boton del color seleccionado

void setup() {
  pinMode(VER, OUTPUT);   // Salida al LED
  pinMode(AZU, OUTPUT);   // Salida al LED
  pinMode(ROJ, OUTPUT);   // Salida al LED
  pinMode(ONF, INPUT);    // Pin de encendido/apagado
  pinMode(SW1, INPUT);    // Pin del color 1
  pinMode(SW2, INPUT);    // Pin del color 2
  pinMode(SW3, INPUT);    // Pin del color 3
  pinMode(SW4, INPUT);    // Pin del color 4
  pinMode(SW5, INPUT);    // Pin del color 5
  pinMode(SW6, INPUT);    // Pin del color 6
}

void loop() {
  ONFF();                 // Leer si el usuario desea que esté encendido o apagado
  if (ESO==1){            // ESO: 1-Encendido 0-Apagado
    Select();             // Leer que color seleccionó el usuario, solo se puede cambiar
                          // de color mientras se esté encendido en LED
    switch (ESW){         // Se analiza el valor de ESW asignado por Select()
      case 1:       // Color  Berriasian
        analogWrite(ROJ,140);
        analogWrite(VER,205);
        analogWrite(AZU,96);
        break;
      case 2:       // Color Danian
        analogWrite(ROJ,253);
        analogWrite(VER,180);
        analogWrite(AZU,98);
        break;
      case 3:       // Color Aqua
        analogWrite(ROJ,0);
        analogWrite(VER,255);
        analogWrite(AZU,255);
        break;
      case 4:       // Color Oliva
        analogWrite(ROJ,128);
        analogWrite(VER,128);
        analogWrite(AZU,0);
        break;
      case 5:       // Color Teal
        analogWrite(ROJ,0);
        analogWrite(VER,128);
        analogWrite(AZU,128);
        break;
      case 6:       // Color Morado
        analogWrite(ROJ,128);
        analogWrite(VER,0);
        analogWrite(AZU,128);
        break;                                
    }
  } else {
      analogWrite(ROJ,0);
      analogWrite(VER,0);
      analogWrite(AZU,0);    
  }
}

void ONFF() {       // Función para verificar el estado de encendido o apagado
  if (digitalRead(ONF)==HIGH){
    ESO++;
    if (ESO==2){    // Solo se utilizan valores de 0 y 1 para el led, por lo que
      ESO=0;        // se utiliza un conteo modulo 2
    }
  }  
}

void Select(){      // Función para leer el estado de cada switch
  if (digitalRead(SW1)==HIGH){
    ESW=1;
  }
  if (digitalRead(SW2)==HIGH){
    ESW=2;
  }
  if (digitalRead(SW3)==HIGH){
    ESW=3;
  }
  if (digitalRead(SW4)==HIGH){
    ESW=4;
  }    
  if (digitalRead(SW5)==HIGH){
    ESW=5;
  }
  if (digitalRead(SW6)==HIGH){
    ESW=6;
  }
}
