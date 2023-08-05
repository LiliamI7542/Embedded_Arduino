
int led = 12;
int bz = 8;
int but = 7;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(but, INPUT);
pinMode(bz, OUTPUT);
}
little star
void loop() {
  int i;
  for(i=0;i<5;i++){
    tone(bz, 261);
    delay(300);
    noTone(bz);
    tone(bz, 262);
    delay(300);
    noTone(bz);
    tone(bz, 391);
    delay(300);
    noTone(bz);
    tone(bz, 391);
    delay(300);
    noTone(bz);
    tone(bz, 440);
    delay(300);
    noTone(bz);
    tone(bz, 440);
    delay(300);
    noTone(bz);
    tone(bz, 391);
    delay(600);
    noTone(bz);
    
    tone(bz, 349);
    delay(300);
    noTone(bz);
    tone(bz, 349);
    delay(300);
    noTone(bz);
    tone(bz, 329);
    delay(300);
    noTone(bz);
    tone(bz, 329);
    delay(300);
    noTone(bz);
    tone(bz, 293);
    delay(300);
    noTone(bz);
    tone(bz, 293);
    delay(300);
    noTone(bz);
    tone(bz, 261);
    delay(300);
    noTone(bz);
    break;
  }
  noTone(bz);
  delay(10000);
  return 0;
}
