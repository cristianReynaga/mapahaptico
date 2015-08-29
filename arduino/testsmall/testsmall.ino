
void setup() {
  // put your setup code here, to run once:
 pinMode(12,OUTPUT);
}

void loop() {
  analogWrite(12,0);
  delay(1000);
  analogWrite(12,255);
  delay(1000);

}
