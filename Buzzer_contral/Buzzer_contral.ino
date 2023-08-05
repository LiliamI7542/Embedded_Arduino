int bz = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(bz, OUTPUT);
  digitalWrite(bz, LOW);
}

void be1() {
  // put your main code here, to run repeatedly:
  int i;
  for(i=0;i<130;i++){
    digitalWrite(bz, HIGH);
    delayMicroseconds(700);
    digitalWrite(bz, LOW);
    delayMicroseconds(700);
  }
 // delay(100);
}
void be2() {
  // put your main code here, to run repeatedly:
  int i;
  for(i=0;i<100;i++){
    digitalWrite(bz, HIGH);
    delay(1);
    digitalWrite(bz, LOW);
    delay(1);
  }
 // delay(100);
}
void loop(){
  be2();
  be2();
  be1();
  while(1);
}
