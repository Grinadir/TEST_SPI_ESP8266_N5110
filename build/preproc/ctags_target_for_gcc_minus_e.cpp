# 1 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino"
# 2 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino" 2
# 3 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino" 2
# 4 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\ESP_NOKIA5110\\ESP_NOKIA5110.ino" 2
Adafruit_PCD8544 display = Adafruit_PCD8544(14, 13, 4, 15, 5);







void pinInit(){

  pinMode(5 /* reset N5110*/, 0x01);
  pinMode(4 /* DC N5110*/, 0x01);
  pinMode(15 /* Chip Select*/, 0x01);

}
void setDC (uint8_t bit){
  if(bit==0){
    digitalWrite(4 /* DC N5110*/, 0x0);
  }
  else if(bit==1){
    digitalWrite(4 /* DC N5110*/, 0x1);
  }

}

void chipSelect(uint8_t bit){
  if(bit==0){
    digitalWrite(15 /* Chip Select*/, 0x0);
    }
    else if(bit==1){
      digitalWrite(15 /* Chip Select*/, 0x1);
    }
}

void resetN5110(uint8_t bit){

  if(bit==0){
    digitalWrite(5 /* reset N5110*/, 0x0);
  }
  else if(bit==1){
    digitalWrite(5 /* reset N5110*/, 0x1);
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
  SPI.beginTransaction(SPISettings(600000, 1, SPI_MODE0));

  setDC(0);
  digitalWrite(15,0x0);
  delay(20);
  SPI.transfer(33); //2
  digitalWrite(15,0x1);

  delay(20);
  digitalWrite(15,0x0);

  SPI.transfer(144); //3

  digitalWrite(15,0x1);

  delay(20);
  digitalWrite(15,0x0);

  SPI.transfer(32); //4

  digitalWrite(15,0x1);

  delay(20);
  digitalWrite(15,0x0);

  SPI.transfer(12); //5
  digitalWrite(15,0x1);

  delay(20);
  setDC(1);
  digitalWrite(15,0x0);

  SPI.transfer(31);//6
  digitalWrite(15,0x1);
  delay(20);
  digitalWrite(15,0x0);
  SPI.transfer(5);//7

  digitalWrite(15,0x1);
  delay(20);
  digitalWrite(15,0x0);

  SPI.transfer(7);//8
  digitalWrite(15,0x1);

  delay(20);
  digitalWrite(15,0x0);
  delay(10);

  setDC(0);
  //SPI.transfer(13);
  SPI.endTransaction();


}

void loop() {
  // put your main code here, to run repeatedly:







}
