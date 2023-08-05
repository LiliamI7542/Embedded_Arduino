int P0=0;
void SetP0(void)
{
  int i,tmp;
  for(i=0;i<=7;i++)
  {
    tmp=((P0>>i)&0x01);
    if(tmp==0x01)
      digitalWrite(i+2,HIGH);  
    else
      digitalWrite(i+2,LOW);  
  }
}



//Setup Pin Mode, we set pin 2~9 to be Output
void setup()
{
  int i;
  for(i=2;i<=9;i++)
      pinMode(i,OUTPUT); //P0
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  Serial.begin(9600);
}

void loop(){

  int LED1[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//P_R
  int LED2[8]={0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};//P_Y

 P_Y=LED2[0]
  for(int i=0;i<=7;i++)
  {
   P_R=LED[i];
   P0=P_R|P_Y;

    SetP0();
    delay(500);
   
  }
}
