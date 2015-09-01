#include "Arduino.h"
#include <Thread.h>
#include <Wtv020sd16p.h>
#include <ThreadController.h>
#include <Keypad.h>
#include "config.h"
#include "interaction.h"



void setup() {
  logs("-----------| Mesa haptica |-----------");
  logs("Starting up...", true);
  prepareClockThreads();//CREATE AND START CLOCK THREAD
  prepareVias();//INIT LED STRIP VIAS
  wtv020sd16p.reset();//START AUDIO DEVICE
}

void generalClock() {
  for(int i = 0; i < maxVias; i++){
    if(viasTime[i] > 0){
      viasTime[i] =  viasTime[i]-eventIt ; 
    }
   } 
  if(soundRunTime > 0 & playing == true){
    soundRunTime -= eventIt;
  }else{
    playing = false;
    wtv020sd16p.stopVoice();
  }
}

void loop() {
  /* REMOVEME! */
  controll.run();
  if (havePublic() == true) {
    botonera();
    for(int i = 0; i < maxVias; i++){
      if(viasAct[i] == lightOn){if(viasValues[i] < 255) {viasValues[i] += lsFadeMod;} else{viasAct[i] = lightHold;viasValues[i] = 255;} logs("+");ledStripsControll(vias[i], viasValues[i]); 
        for(int j = 0 ; j < maxVias; j++){
          if(j != i){
            if(viasAct[j]==lightOn || viasAct[j] == lightHold){
              viasAct[j]  = lightOff;

            }
           }
        }
      }
      else if(viasAct[i] == lightHold){ if((viasTime[i]-eventIt*12) <= 0) {viasAct[i] = lightOff;} logs("*");}
      else if(viasAct[i]==lightOff){if(viasValues[i] > 0){viasValues[i] -= lsFadeMod;}
                                      else{viasAct[i] = lightIdle;
                                      viasTime[i]=0;
                                      viasValues[i]=0;} 
                                      logs("-");
                                      ledStripsControll(vias[i], viasValues[i]);  
                                    }
      else{ledStripsControll(vias[i], 0); }
       
    }
  }

  /* FOO TEST */
}


void test() {

}



void logs(String msg) {
  logs(msg, false);
}


void logs(String msg, boolean dl) {
  if(logEnable == true){
    if (serialReady == false ) {
      Serial.begin(9600);
      serialReady = !serialReady;
    }
    Serial.print(">> \"");
    Serial.print(msg);
    dl == true ? Serial.print("\"\n") : Serial.print("\"");
    Serial.println();
  }
}


void ledStripsControll(int via, int value ) {
  analogWrite(via, value);
}

void prepareVias() {
  logs("Setting up vias LS");
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
  logs("All vias are ready!", true);

}

void prepareClockThreads(){
  Thread* myThread = new Thread();
  myThread->onRun(generalClock);
  myThread->setInterval(eventIt);
  controll.add(myThread);
  logs("GeneralClock done!... at: " + String(eventIt) + "ms", true);
}
