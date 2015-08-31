#include <Thread.h>
#include <ThreadController.h>
#include "appSettings.h"

ThreadController controll = ThreadController();
Thread* myThread  = new Thread();
Thread  nyThreads = Thread();


void setup() {
  Serial.begin(9600);
  Thread* myThread = new Thread();
  Thread hisThread = Thread();
  myThread->onRun(scheduler);
  myThread->setInterval(100);

}

void scheduler() {
}

void loop() {

}

void logs(String msg) {
  if(serialReady == false ){
    Serial.begin(9600);
    serialReady = true;
  }
  Serial.print(">> \"");
  Serial.print(msg);
  Serial.print("\"");
  Serial.println();
}
