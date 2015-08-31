#include "Arduino.h"
#include <Thread.h>
#include <ThreadController.h>
#include "config.h"



void setup() {
  pinMode(24, INPUT);//ONLY 4 TEST!
  logs("Starting up...", true);
  Thread* myThread = new Thread();
  Thread hisThread = Thread();
  myThread->onRun(generalClock);
  myThread->setInterval(eventIt);
  String m = "GeneralClock done!... at: " + String(eventIt) + "ms";
  logs(m, true);
  prepareVias();
}

void generalClock() {
  for(int i = 0; i < maxVias; i++){
    if(viasTime[i] > 0){
       viasTime[i] -=eventIt; 
       switch(viasAct[i]){
       case lightOn   :{viasValues[i] < 255 ? viasValues[i] += 20 :viasAct[i] = lightHold ; break;}
       case lightHold :{if((viasTime[i]-eventIt*13) < 0) {viasAct[i] = lightOff;} break;}
       case lightOff  :{viasValues[i] > 0 ? viasValues[i] -= 20 :viasAct[i] = lightIdle; break;}
       }
   }
  }  
}

void loop() {
  /* REMOVEME! */
  if (havePublic() == true) {
    test();
  }

  /* FOO TEST */
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

void ledStripsControll(int via, int action ) {
  action == 0 ? analogWrite(via, 255) : analogWrite(via, 0);
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
  logs("All vias are ready!", true);
  ledStripsControll(vias[1], 1);
}
