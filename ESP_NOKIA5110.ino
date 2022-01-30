#include "SPI.h"


#define D1 5  // reset N5110
#define D2 4  // DC N5110
#define D8 15 // Chip Select



void initPin(){
  
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D8, OUTPUT);

}
void setDC (uint8_t bit){
  if(bit==0){
    digitalWrite(D2, LOW);
  }
  else if(bit==1){
    digitalWrite(D2, HIGH);
  }
  
}

void chipSelect(uint8_t bit){
  if(bit==0){
    digitalWrite(D8, LOW);
    }
    else if(bit==1){
      digitalWrite(D8, HIGH);
    }
}

void resetN5110(uint8_t bit){
  
  if(bit==0){
    digitalWrite(D1, LOW);
  }
  else if(bit==1){
    digitalWrite(D1, HIGH);
  }

}

void testing() {
  // put your setup code here, to run once:
  initPin();
  resetN5110(0);
  delay(1000);
  resetN5110(1);
  delay(100);
  chipSelect(0);
  SPI.begin();
  SPI.setFrequency(60000);
  delay(1000);
  setDC(0);
  SPI.transfer(0x21);
  //SPI.transfer(0xFF);
  SPI.transfer(0x14);
  SPI.transfer(0x20);
  SPI.transfer(0x21);
  SPI.transfer(0xC0);
  SPI.transfer(0x20);
  SPI.transfer(0x20);
  SPI.transfer(0x0C);
  SPI.transfer(0x40);
  SPI.transfer(0x80);
  //SPI.transfer(0xFF);

 
  setDC(1);
  for(int i=1;i<=16;i++)
  {
  SPI.transfer(0);
  }
  

}



void testing_not_work() {
  // put your setup code here, to run once:
  initPin();
  chipSelect(0);
  resetN5110(0);
  delay(100);
  resetN5110(1);
  chipSelect(0);
  SPI.begin();
  SPI.beginTransaction(SPISettings(600000, MSBFIRST, SPI_MODE0));
  
  setDC(0);
  digitalWrite(15,LOW);
  delay(20);
  SPI.transfer(33); //2
  digitalWrite(15,HIGH);

  delay(20);
  digitalWrite(15,LOW);
  
  SPI.transfer(144); //3

  digitalWrite(15,HIGH);

  delay(20);
  digitalWrite(15,LOW);
  
  SPI.transfer(32); //4
  
  digitalWrite(15,HIGH);

  delay(20);
  digitalWrite(15,LOW);
  
  SPI.transfer(12); //5
  digitalWrite(15,HIGH);

  delay(20);
  setDC(1);
  digitalWrite(15,LOW);
  
  SPI.transfer(31);//6
  digitalWrite(15,HIGH);
  delay(20);
  digitalWrite(15,LOW);
  SPI.transfer(5);//7
  
  digitalWrite(15,HIGH);
  delay(20);
  digitalWrite(15,LOW);
  
  SPI.transfer(7);//8
  digitalWrite(15,HIGH);

  delay(20);
  digitalWrite(15,LOW);
  delay(10);
  
  setDC(0);
  //SPI.transfer(13);
  SPI.endTransaction();
  

}

void setup(){
  testing();

  
}

void loop() {
  // put your main code here, to run repeatedly:
  SPI.transfer(255);
  delay(500);
  




  

}
