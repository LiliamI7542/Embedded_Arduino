
int led1[]={2, 3, 4, 5, 6, 7, 8, 9};
int i, t;
void setup() {
  // put your setup code here, to run once:
  for(i=0;i<8;i++){
    pinMode(led1[i], OUTPUT);
  }
}

void allonoff(){
  for(i=0;i<8;i++){
    digitalWrite(led1[i], HIGH);
  }
  delay(500);
  
  for(i=0;i<8;i++){
    digitalWrite(led1[i], LOW);
  }
  delay(500);
}

void goRightLeft(){
  for(i=0;i<8;i++){
    digitalWrite(led1[i], HIGH);
    digitalWrite(led1[i-1], LOW);
    delay(500);
  }
  for(i=7;i>-1;i--){
    digitalWrite(led1[i], HIGH);
    digitalWrite(led1[i+1], LOW);
    delay(500);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  allonoff();
  goRightLeft();
}
