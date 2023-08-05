#include <SPI.h>
byte Decode = 0x9;
byte Intensity = 0xA;
byte Scan = 0xB;
byte Shutdown = 0xC;
byte Test = 0xF;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 600;
int Label = 0;

void max7219(byte r,byte d){
  digitalWrite(SS, LOW);  //選取晶片
  SPI.transfer(r);  //暫存器位址
  SPI.transfer(d);  //資料
  digitalWrite(SS, HIGH);  //取消選取晶片
}
void clear(){
  for(int i = 1;i <= 8;i++){
    max7219(i, 0);
  }
}

byte data[8]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

byte image_0[8] = {0x86, 0x44, 0x28, 0x12, 0x9c, 0x78, 0x0c, 0x1c}; //up
byte image_1[8] = {0x86, 0x44, 0x28, 0x16, 0x9c, 0x78, 0x0c, 0x1c}; //right
byte image_2[8] = {0x44, 0x24, 0x28, 0x34, 0x58, 0x38, 0x0c, 0x1c}; //down
byte image_3[8] = {0x60, 0x30, 0x30, 0x18, 0x38, 0x18, 0x0c, 0x1c}; //left
byte image_4[8] = {0x44, 0x24, 0x28, 0x14, 0x58, 0x38, 0x0c, 0x1c}; //left

void setup() {
  SPI.begin();
  max7219(Decode,0);
  max7219(Intensity,7);
  max7219(Scan,7);
  max7219(Shutdown,1);
  max7219(Test,0);
  clear();
}

void loop() {
  for(int i = 0; i< 8;i++){
    max7219(i+1, data[i]);
  }

  if((millis() - lastDebounceTime) > debounceDelay) {

    switch(Label) {
      case 1:
        for(int i = 0; i < 8; i++) {
          data[i] = image_1[i];
        }
        Label = 2;
        break;

      case 2:
        for(int i = 0; i < 8; i++) {
          data[i] = image_2[i];
        }
        Label = 3;
        break;

      case 3:
        for(int i = 0; i < 8; i++) {
          data[i] = image_3[i];
        }
        Label = 4;
        break;

      case 4:
        for(int i = 0; i < 8; i++) {
          data[i] = image_4[i];
        }
        Label = 0;
        break;

      default:
        for(int i = 0; i < 8; i++) {
          data[i] = image_0[i];
        }
        Label = 1;
        break;
    }

    lastDebounceTime = millis();
  }
}
