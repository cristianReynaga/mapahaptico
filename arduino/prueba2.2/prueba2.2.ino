#include <Keypad.h>
#include <Wtv020sd16p.h>
#define ledPin 13
#define TiempoGiro 1;
#define BANIOS                '0'
#define AUDITORIO             '1'
#define JUNTA_EVALUADORA      '2'
#define SALA_DE_ESPERA        '4'
#define CAPACITACION          '3'
#define COPIDISA_E            '5'
#define SALA_ADMINISTRATIVA   '6'

#define OFF HIGH
#define ON  LOW
#define LED1 0x01
#define LED2 0x02
#define LED3 0x03
//macros para el sensor ultrasonico
#define echoPin 11 // Echo Pin
#define trigPin 12 // Trigger Pin
#define LEDPin 13 // Onboard LED

int resetPin = 22;//2;  // The pin number of the reset pin.
int clockPin = 24;//3;  // The pin number of the clock pin.
int dataPin = 4;  // The pin number of the data pin.
int busyPin = 26;//5;  // The pin number of the busy pin.
bool aux = 0;
//variables para el sensor ultrasonico
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance = 0; // Duration used to calculate distance


//pwm
int R = 8;
int G = 9;
int B = 10;
//habilitaciones
int h1 = 36;//BAÑO
int h2 = 34;//AUDITORIO
int h3 = 32;//JUNTA EVALUADORA
int h4 = 33;//SALA_DE_ESPERA
int h5 = 35;//CAPACITACION
int h6 = 37;//COPIDISE
int h7 = 53;//SALA_ADMINISTRATIVA
//entradas
int in1 = 28;
int in2 = 30;
int in3 = 32;
//variables auxiliares
char hled ;
char customKey = 0xff;
const byte ROWS = 3; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'}
/*  {'0','1','2'},
  {'3','4','5'},
  {'6','7','8'},
  {'9','A','B'}*/
};
byte rowPins[ROWS] = {48,46,50}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {44, 42, 38, 40}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);
//Ultrasonic sensor(12,11);   // (Trig PIN,Echo PIN)

void setup() {
  digitalWrite(ledPin,HIGH);
  noInterrupts();           // disable all interrupts
  TCCR3A = 0;
  TCCR3B = 0;
             // preload timer 65536-16MHz/256/2Hz
  TCNT3 = 3036; 
  TCCR3B |= (1 << CS32);    // 256 prescaler 
  TIMSK3 |= (1 << TOIE3);   // enable timer overflow interrupt
  interrupts();  
  
  //Serial.begin(9600);
  wtv020sd16p.reset();
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
  pinMode(h1,OUTPUT);
  pinMode(h2,OUTPUT);
  pinMode(h3,OUTPUT);
  pinMode(h4,OUTPUT);
  pinMode(h5,OUTPUT);
  pinMode(h6,OUTPUT);
  pinMode(h7,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  Apagar();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  //wtv020sd16p.pauseVoice();
  wtv020sd16p.stopVoice();
  delay(500);
 /* wtv020sd16p.asyncPlayVoice(4);
  wtv020sd16p.playVoice(0);
  wtv020sd16p.pauseVoice();
  wtv020sd16p.stopVoice();
  wtv020sd16p.mute();
  wtv020sd16p.unmute();*/
}

void loop() {

 
  
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 //Serial.println(distance);
 delay(40);
 //distance = sensor.Ranging(CM);
 //if (distance>10 && distance < 30){
 if (distance>10 && distance < 80){
                 Rgb(125, 125 , 125, ON, ON , ON , ON , ON , ON , ON);
                 wtv020sd16p.asyncPlayVoice(16);
                 delay(5000);
                 wtv020sd16p.stopVoice();
                 Apagar();
 }
 customKey = customKeypad.getKey();
 //Serial.println(customKey);
  switch(customKey)
   {
     case BANIOS:
                 Rgb(181, 255 , 58, ON, OFF , OFF, OFF, OFF, OFF, OFF);
                 wtv020sd16p.asyncPlayVoice(0);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break;
    case AUDITORIO :
                 Rgb(255, 0 , 0, OFF, ON , OFF, OFF, OFF, OFF, OFF);
                 wtv020sd16p.asyncPlayVoice(1);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break;
     case  JUNTA_EVALUADORA:
                 Rgb(115, 228 , 255, OFF, OFF , ON, OFF, OFF, OFF, OFF);
                 wtv020sd16p.asyncPlayVoice(2);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break;
     case  SALA_DE_ESPERA: 
                 Rgb(50, 100 ,150, OFF, OFF, OFF, OFF, ON, OFF, OFF);
                 wtv020sd16p.asyncPlayVoice(3);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break; 
      case  CAPACITACION: 
                 Rgb(231, 46, 241, OFF, OFF , OFF, ON, OFF, OFF, OFF);
                 wtv020sd16p.asyncPlayVoice(4);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break; 
       case COPIDISA_E : 
                 Rgb(240, 255 , 60, OFF, OFF, OFF, OFF, OFF, ON , OFF);              
                 wtv020sd16p.asyncPlayVoice(5);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break; 

      case SALA_ADMINISTRATIVA : 
                 Rgb(0, 0 , 255, OFF, OFF , OFF, OFF, OFF, OFF, ON);
                 wtv020sd16p.asyncPlayVoice(6);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break; 
      case '7' : 
                 //Rgb(50, 50 , 50, ON, OFF , ON);
                  wtv020sd16p.asyncPlayVoice(7);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break; 
      case '8' : 
                 wtv020sd16p.asyncPlayVoice(8);
                // Rgb(100, 100 ,  100, OFF, ON , ON);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break; 

      case '9' : 
                 wtv020sd16p.asyncPlayVoice(9);
                // Rgb(0, 255 , 255, ON, ON , ON);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break; 
      case 'A' : 
                 //Rgb(0, 250 ,80, ON, OFF , OFF);
                 wtv020sd16p.asyncPlayVoice(10);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break; 
      case 'B' : 
                 // Rgb(50, 80 , 255, OFF, OFF , ON);
                  wtv020sd16p.asyncPlayVoice(11);
                  delay(3000);
                  wtv020sd16p.stopVoice();
                  Apagar();
                  break; 
      /*case 'C' : 
                  Rgb(255, 50 , 80, OFF, ON , OFF);
                  wtv020sd16p.asyncPlayVoice(12);
                  delay(3000);
                  wtv020sd16p.stopVoice();
                  Apagar();
                 break; 
      case 'D' : 
                  Rgb(0, 0 , 255, OFF, OFF , ON);
                  wtv020sd16p.asyncPlayVoice(13);
                  delay(3000);
                  wtv020sd16p.stopVoice();
                  Apagar();
                 break; 
      case 'E' : 
                  Rgb(250, 150 , 30, OFF, ON, OFF);
                  wtv020sd16p.asyncPlayVoice(14);
                  delay(3000);
                  wtv020sd16p.stopVoice();
                  Apagar();
                 break; 
       case 'F' : 
                 Rgb(0, 0 , 0, ON, OFF , ON);
                 wtv020sd16p.asyncPlayVoice(15);
                 delay(3000);
                 wtv020sd16p.stopVoice();
                 Apagar();
                 break;*/              
   } 
}

