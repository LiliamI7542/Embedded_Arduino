int inpin=10;
int i, t = 0;
int led1[]={2, 3, 4, 5, 6, 7, 8, 9};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inpin, INPUT);
  for(i=0;i<8;i++){
    pinMode(led1[i], OUTPUT);
  }
}

void loop() {
  int inpin1;
 
  // put your main code here, to run repeatedly:
  
    inpin1=digitalRead(inpin);
    if(inpin1==1){
      Serial.print(1);
      if(t%2==0){
        for(i=0;i<3;i++){
          digitalWrite(led1[i], HIGH);
        }
        delay(200);
      }
      if(t%2==1){
        for(i=0;i<8;i++){
          digitalWrite(led1[i], HIGH);
      }
      delay(200);
      }
    }
    else{
      Serial.print(0);
      for(i=0;i<8;i++){
          digitalWrite(led1[i], LOW);
      }
      t++;
      delay(200);
    }
    Serial.print("\n");
}
