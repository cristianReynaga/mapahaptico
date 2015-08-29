#define ARRAY_SIZE 7

int ledPin[] = {5, 6, 8, 9, 10, 11, 12};
int value[ARRAY_SIZE];
int led13=13;

void setup() {
  //Serial.begin(115200);

  for (int i = 0; i < ARRAY_SIZE; i++) {
    pinMode(ledPin[i], OUTPUT);
    
  }
pinMode(led13, OUTPUT);
}


void loop() {
 /* for (int i = 0; i < ARRAY_SIZE; i++) {
    analogWrite(ledPin[i], 255);
    digitalWrite(13, HIGH);
   // delay(500);
  }
  */
analogWrite(12, 255);
digitalWrite(13, HIGH);
  delay(1000);
/*
  for (int i = 0; i < ARRAY_SIZE; i++) {
    analogWrite(ledPin[i], 0);
    digitalWrite(13, LOW);
   // delay(500);
  }
*/
analogWrite(12, 0);
digitalWrite(13, LOW);
  delay(1000);

}
