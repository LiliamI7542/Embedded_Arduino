
int latchPin = 10;

//Pin connected to Pin 11 of 74HC595 (Clock)
int clockPin = 13;

//Pin connected to Pin 14 of 74HC595 (Data)
int dataPin = 11;
uint8_t led[8];
uint8_t car[8];
uint8_t trackLine[5];
long counter1 = 0;
void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  led[0] = B11100011;
  led[1] = B11100011;
  led[2] = B11100011;
  led[3] = B11100011;
  led[4] = B11100011;
  led[5] = B11100011;
  led[6] = B11100011;
  led[7] = B11100011;

  trackLine[0] = B10001111;
  trackLine[1] = B11000111;
  trackLine[2] = B11100011;
  trackLine[3] = B11110001;

  car[0]=B00001000;
  car[1]=B00010000;
  car[2]=B00010000;
  car[3]=B00010000;
  car[4]=B00001000;
  car[5]=B00001000;
  car[6]=B00001000;
  car[7]=B00001000;

  
}

void loop() {
  if (counter1 >=75) {
counter1 = 0;


  for (int i = 0 ; i < 7 ; i++){
  led[i] = led[i+1];
}
// check of the car has crashed if it has then do a crash signal
if (led[0] & car[carPosition]){
 
  crash();
 
}

led[0] = led[0] | car[carPosition];

randNumber = random(3)-1;

currentLine = currentLine +randNumber;
if (currentLine == 0){
  currentLine = 1;}
 
if (currentLine == 5){
  currentLine = 4;}

led[7] = trackLine[currentLine-1];
}

}
