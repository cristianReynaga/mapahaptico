#include "Arduino.h"
#include <Thread.h>
#include <ThreadController.h>
#include "config.h"



void setup() {
  pinMode(24, INPUT);//ONLY 4 TEST!
  logs("Starting up...", true);
  Thread* myThread = new Thread();
  myThread->onRun(generalClock);
  myThread->setInterval(eventIt);
  controll.add(myThread);
  String m = "GeneralClock done!... at: " + String(eventIt) + "ms";
  logs(m, true);
  prepareVias();
}

void generalClock() {
  for(int i = 0; i < maxVias; i++){
    if(viasTime[i] > 0){
      viasTime[i] -=eventIt; 
    }
     switch(viasAct[i]){
     case lightOn   :{viasValues[i] < 255 ? viasValues[i] += lsFadeMod :viasAct[i] = lightHold; logs("LON LS: "+String(i+1)); break;}
     case lightHold :{viasValues[i] = 255; if((viasTime[i]-eventIt*12) <= 0) {viasAct[i] = lightOff;} logs("LHOLD LS: "+String(i+1)); break;}
     case lightOff  :{viasValues[i] > 0 ? viasValues[i] -= lsFadeMod :viasAct[i] = lightIdle; logs("LOFF LS: "+String(i+1)); break;}
    }
   } 
}

void loop() {
  /* REMOVEME! */
  controll.run();
  if (havePublic() == false) {
    botonera();
    for(int i = 0; i < maxVias; i++){
      ledStripsControll(vias[i], viasValues[i]);}
  }

  /* FOO TEST */
}

void botonera()
{
  char r;
  if (Serial.available() > 0 ){
    r = Serial.read();
  }
  if(r == '1'){viasAct[0] = 1; viasTime[0]=defaultEventTime; Serial.println(">>CMD: LS 1");}
  if(r == '2'){viasAct[1] = 1; viasTime[1]=defaultEventTime; Serial.println(">>CMD: LS 2");}
  if(r == '3'){viasAct[2] = 1; viasTime[2]=defaultEventTime; Serial.println(">>CMD: LS 3");}
  if(r == '4'){viasAct[3] = 1; viasTime[3]=defaultEventTime; Serial.println(">>CMD: LS 4");}
  if(r == '5'){viasAct[4] = 1; viasTime[4]=defaultEventTime; Serial.println(">>CMD: LS 5");}
  if(r == '6'){viasAct[5] = 1; viasTime[5]=defaultEventTime; Serial.println(">>CMD: LS 6");}
  if(r == '7'){viasAct[6] = 1; viasTime[6]=defaultEventTime; Serial.println(">>CMD: LS 7");}
  
}
void test() {
  if (Serial.available() > 0) {
    char s = Serial.read();
    if (s == '1') {
      for (int i = 0; i < maxVias; i++) {
        ledStripsControll(vias[i], 0);
        logs("PING HIGH");
      }
      Serial.flush();
    }
    if (s == '2') {
      for (int i = 0; i < maxVias; i++) {
        ledStripsControll(vias[i], 1);
        logs("PING LOW");
      }
      Serial.flush();
    }
  }
}



void logs(String msg) {
  logs(msg, false);
}
boolean havePublic() {
  //redef!
  boolean r = false;
  int s = digitalRead(24);
  if (s == HIGH) {
    r = true;
  }
  return r;
}

void logs(String msg, boolean dl) {
  if (serialReady == false ) {
    Serial.begin(9600);
    serialReady = !serialReady;
  }
  Serial.print(">> \"");
  Serial.print(msg);
  dl == true ? Serial.print("\"\n") : Serial.print("\"");
  Serial.println();
}

void fade(){

}

void ledStripsControll(int via, int value ) {
  analogWrite(via, value);
  //analogWrite(vias[0], 255);
}

void prepareVias() {
  logs("Setting up vias LS");
  /*  for(int i = 0; i < maxVias ; i++){
      pinMode(vias[i],OUTPUT);
    }*/
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  logs("All vias are ready!", true);

}
