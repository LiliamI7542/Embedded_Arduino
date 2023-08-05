#include <LiquidCrystal.h>

int btn;
int led = 13;
int kl = 7;
int bz = 8;

int mm = 5, ss = 1;

unsigned long ti = 0;
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(kl, INPUT);
  digitalWrite(kl, HIGH);
  pinMode(bz, OUTPUT);
  digitalWrite(bz, LOW);
}

void led_blk(){//閃光
  int i;
  Serial.print("blink\n");
  for(i=0;i<20;i++){
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led, LOW);
    delay(150);
  }
}

void be(){//嗶嗶聲
  int i;
  Serial.print("be\n");
  for(i=0;i<100;i++){
    digitalWrite(bz, HIGH);
    delay(1);
    digitalWrite(bz, LOW);
    delay(1);
  }
}

void show_tdo(){
  int c;
  Serial.print("show\n");
  c = (mm/10);
  lcd.setCursor(0, 1);
  lcd.print(c);
  c = (mm%10);
  lcd.setCursor(1, 1);
  lcd.print(c);
  lcd.setCursor(2, 1);
  lcd.print(":");
  c=(ss/10);
  lcd.setCursor(3, 1);
  lcd.print(c);
  c=(ss%10);
  lcd.setCursor(4, 1);
  lcd.print(c);
}
void loop() {//主程迴圈
  
  //Serial.print("1");
  // put your main code here, to run repeatedly:
  int klc;
  led_blk();
  be();
  lcd.setCursor(0, 0);
  lcd.print("AR TDO");
  show_tdo();
  //Serial.print("2");
  while(1){
    Serial.print("in\n");
    if(millis()-ti>=1000){
      ti=millis();
      show_tdo();
      
      if(ss == 1 && mm == 0){
        while(1){
          be();
          klc=digitalRead(kl);
          //Serial.print(klc);
          if(klc==1){
              be();
              led_blk();
              mm=5;ss=1;
              show_tdo();
              break;
          }
        }
      }
      ss--;
      if(ss==-1){
        mm--;
        ss=59;
      }
    }
    klc=digitalRead(kl);
    if(klc==1){
        be();
        led_blk();
        mm=5;ss=1;
        show_tdo();
    }
  }
  
}
