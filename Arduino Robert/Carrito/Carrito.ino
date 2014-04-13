#include <SPI.h>
#include <boards.h>
#include <ble_shield.h>
#include <services.h>
#include <Servo.h> 

//***********************************sensor ultrasonico******************************

#define echoAde 38
#define trigAde 39
/*
#define echoDer 40
#define trigDer 41
#define echoAtr 42
#define trigAtr 43
#define echoIzq 44
#define trigIzq 45*/
//#define LEDPin 13
long duration, cm;    //variables tipo long

//***********************************control de motores******************************
int motIzqAde = 33;  //cafe
int motIzqAtr = 23;  //azul
int motDerAde = 25;  //verde
int motDerAtr = 27;  //amarillo
int potMotIzq = 29;  //naranja
int potMotDer = 31;  //rojo
int angulo    = 0;

Servo servoX;
Servo servoY;

void setup(){
  
  ble_begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(LSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.begin();
  
  //Configuracion de sensor ultrasonico
  pinMode(trigAde, OUTPUT);  //Configura los pines 6,7,13 como entrada o salida.
  pinMode(echoAde, INPUT);
  //pinMode(LEDPin, OUTPUT);
  
  pinMode(motIzqAde,OUTPUT);
  pinMode(motIzqAtr,OUTPUT);
  pinMode(motDerAde,OUTPUT);
  pinMode(motDerAtr,OUTPUT);
  pinMode(potMotIzq,OUTPUT);
  pinMode(potMotDer,OUTPUT);
 
  analogWrite(potMotIzq,0);
  analogWrite(potMotDer,0);
  
  servoX.attach(35,500,2000);
  
  for(angulo=0;angulo<180;angulo+=10){
  servoX.write(angulo);
  analogWrite(13,4);
  delay(25);
  analogWrite(13,255);
  delay(25);
}
for(angulo=180;angulo>0;angulo-=10){
  servoX.write(angulo);
  delay(50);
    analogWrite(13,4);
  delay(25);
  analogWrite(13,255);
  delay(25);

}
  analogWrite(13,255);
  servoX.write(90);
  servoY.attach(37,500,2000);
  servoY.write(90);
  
  //attachInterrupt(0,funcionSensor,FALLING);
  
  Serial.begin(9600);
}

void loop(){
  
  while(ble_available())
  {
      byte control = 1;
    
      byte motorIzqAde;
      byte motorIzqAtr;
      byte potMotorIzq;
   
      byte motorDerAde;
      byte motorDerAtr;
      byte potMotorDer;
      
      byte anguloX;
      byte anguloY;
      //control = ble_read();
      
    
      //if(control == 1)
      //{
          /*
          digitalWrite(trigAde,HIGH);
          delayMicroseconds(5);
          digitalWrite(trigAde,LOW);
          duration = pulseIn(echoAde,HIGH);
          cm = microsecondsToCentimeters(duration);
          Serial.println(cm);
          delay(100);*/
          /*
          if(cm <= 10){
            digitalWrite(motIzqAtr,HIGH);
            digitalWrite(motDerAde,HIGH);
            analogWrite(potMotDer,255);
            analogWrite(potMotIzq,255);
            delay(500);
            digitalWrite(motIzqAtr,LOW);
            digitalWrite(motDerAde,LOW);
            analogWrite(potMotDer,0);
            analogWrite(potMotIzq,0);
            delay(500);
          }else{*/
            control = ble_read();
            motorIzqAde = ble_read();
            motorIzqAtr = ble_read();
            motorDerAde = ble_read();
            motorDerAtr = ble_read();
            potMotorIzq = ble_read();
            potMotorDer = ble_read();
            anguloX = ble_read();
            anguloY = ble_read();
    
            digitalWrite(motIzqAde,motorIzqAde);
            digitalWrite(motIzqAtr,motorIzqAtr);
            analogWrite(potMotIzq,potMotorIzq);
    
            digitalWrite(motDerAde,motorDerAde);
            digitalWrite(motDerAtr,motorDerAtr);
            analogWrite(potMotDer,potMotorDer);
          
            servoX.write(anguloX);
            if(anguloY==90)
                            servoY.write(100);
            else 
                            servoY.write(10);
            
//            servoY.write(anguloY);
          
          /*  
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());*/
          //}
      //}
      /*
      else if(control==0){
          control = ble_read();
          aux = ble_read();
          aux = ble_read();
          aux = ble_read();
          aux = ble_read();
          aux = ble_read();
          aux = ble_read();
          
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          Serial.println(ble_read());
          
          digitalWrite(motorDerAde,HIGH);
          digitalWrite(motorIzqAde,HIGH);
          delay(1000);
          digitalWrite(motorDerAde,LOW);
          digitalWrite(motorIzqAde,LOW);
          delay(1000);
      }*/
  }
   ble_do_events();
   /*
   digitalWrite(motIzqAde,LOW);
   digitalWrite(motIzqAtr,LOW);
   digitalWrite(motDerAde,LOW);
   digitalWrite(motDerAtr,LOW);
   analogWrite(potMotDer,0);
   analogWrite(potMotIzq,0);
   servoX.write(90);
   servoY.write(90);*/
   //digitalWrite(motIzqAde,motorIzqAde);
   //digitalWrite(motIzqAtr,motorIzqAtr);
   //analogWrite(potMotIzq,potMotorIzq);
    
   //digitalWrite(motDerAde,motorDerAde);
   //digitalWrite(motDerAtr,motorDerAtr);
   //analogWrite(potMotDer,potMotorDer);
}

long microsecondsToCentimeters(long microseconds){
  // La velocidad del sonido a 20º de temperatura es 340 m/s o
  // 29 microsegundos por centrimetro.
  // La señal tiene que ir y volver por lo que la distancia a 
  // la que se encuentra el objeto es la mitad de la recorrida.
  return microseconds / 29 /2 ;
}
