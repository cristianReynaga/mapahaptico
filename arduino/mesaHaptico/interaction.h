//ULTRASONIC SENSOR
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance;
#define echoPin 52 // Echo Pin
#define trigPin 9 // Trigger Pin

boolean havePublic() {
 return true;
}

void initKeyboard(){
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
}

void botonera()
{  
 customKey = customKeypad.getKey();
 if(customKey != 0){
      switch(customKey){
      case '3': {viasAct[0] = 1; viasTime[0]=defaultEventTime; wtv020sd16p.playVoice(0); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 1"); break;}
      case '2': {viasAct[1] = 1; viasTime[1]=defaultEventTime; wtv020sd16p.playVoice(1); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 2"); break;}
      case '1': {viasAct[2] = 1; viasTime[2]=defaultEventTime; wtv020sd16p.playVoice(2); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 3"); break;}
      case '0': {viasAct[3] = 1; viasTime[3]=defaultEventTime; wtv020sd16p.playVoice(3); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 4"); break;}
      case '7': {viasAct[4] = 1; viasTime[4]=defaultEventTime; wtv020sd16p.playVoice(4); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 5"); break;}
      case '6': {viasAct[5] = 1; viasTime[5]=defaultEventTime; wtv020sd16p.playVoice(5); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 6"); break;}
      case '5': {viasAct[6] = 1; viasTime[6]=defaultEventTime; wtv020sd16p.playVoice(6); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 7"); break;}
      case '4': {wtv020sd16p.playVoice(7);  soundRunTime = audioDefaultTime; playing=true; Serial.println("JUST SOUND SAMPLE 1"); break;}
      case 'B': {wtv020sd16p.playVoice(8);  soundRunTime = audioDefaultTime; playing=true; Serial.println("JUST SOUND SAMPLE 2"); break;}
      case 'A': {wtv020sd16p.playVoice(9);  soundRunTime = audioDefaultTime; playing=true; Serial.println("JUST SOUND SAMPLE 3"); break;}
      case '9': {wtv020sd16p.playVoice(10); soundRunTime = audioDefaultTime; playing=true; Serial.println("JUST SOUND SAMPLE 4"); break;}
      }
   } 
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

