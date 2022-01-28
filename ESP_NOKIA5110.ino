#include "SPI.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(14, 13, 4, 15, 5);



void setDC (uint8_t bit){
  pinMode(4, OUTPUT);
  if(bit==0){
    digitalWrite(4, LOW);
  }
  else if(bit==1){
    digitalWrite(4, HIGH);
  }
  
}

void chipSelect(uint8_t bit){

 // pinMode(4, OUTPUT);
 // if(bit==0){
 //   digitalWrite(4, LOW);
//  }
//  else if(bit==1){
 //   digitalWrite(4, HIGH);
 // }

  
}

void resetN5110(uint8_t bit){

  pinMode(5, OUTPUT);
  if(bit==0){
    digitalWrite(5, LOW);
  }
  else if(bit==1){
    digitalWrite(5, HIGH);
  }

  
}




void setup() {
  // put your setup code here, to run once:

  pinMode(15, OUTPUT);
  digitalWrite(15,HIGH);
  //resetN5110(1);
  //delay(20);
  resetN5110(0);
  delay(69);
  resetN5110(1);
  //delay(20);
  //resetN5110(0);
  //delay(200);
  //resetN5110(1);
  //delay(100);
    display.begin();
    display.clearDisplay();
    display.display();
    
    display.setContrast(60); // установка контраста
    delay(1000);

  
  chipSelect(0);
  SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));
  //SPI.setClockDivider (SPI_CLOCK_DIV128);
  SPI.begin();
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
  SPI.transfer(13);
  SPI.endTransaction();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  




  

}
