
 // C++ code
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>
#define pinSerialRX 2
#define pinSerialTX 1

//HardwareSerial seriaBT(pinSerialRX, pinSerialTX);

String comando;

Servo servo;
int graus;
int estado = LOW;

void setup()
{
  Serial.begin(9600); 
  servo.attach(5);
  Dabble.begin(9600);                            
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}                                                                  

void descer(){
  graus = 90;
  servo.write(graus);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void subir(){
  graus = 0;
  servo.write(graus);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}

void loop()
{
  Dabble.processInput(); 
   delay(1000);
   
   //Serial.print("KeyPressed: ");

   int botao1 = digitalRead(4);
   int botao2 = digitalRead(3);
   Serial.print(botao1);
  
    if((botao1 == LOW)){ 
        subir();
        Serial.print("SUBIU \n"); 
    }
    if((botao2 == HIGH)){ 
        descer();
        Serial.print("DESCEU \n"); 
    }

 if (GamePad.isUpPressed())
  {
    Serial.print("UP");
    descer();
  }

}
