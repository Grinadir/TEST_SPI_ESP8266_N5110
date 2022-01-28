#include <Arduino.h>
#line 1 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
#include "SPI.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(14, 13, 4, 15, 5);

#define D1 5  // reset N5110
#define D2 4  // DC N5110
#define D8 15 // Chip Select



#line 12 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
void pinInit();
#line 19 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
void setDC(uint8_t bit);
#line 29 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
void chipSelect(uint8_t bit);
#line 38 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
void resetN5110(uint8_t bit);
#line 51 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
void setup();
#line 116 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
void loop();
#line 12 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
void pinInit(){
  
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



void setup() {
  // put your setup code here, to run once:
  pinInit();
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

void loop() {
  // put your main code here, to run repeatedly:
  




  

}

