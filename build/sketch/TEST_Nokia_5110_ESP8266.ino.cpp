#include <Arduino.h>
#line 1 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\TEST_Nokia_5110_ESP8266\\TEST_Nokia_5110_ESP8266.ino"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(14, 13, 4, 15, 5);

#line 5 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\TEST_Nokia_5110_ESP8266\\TEST_Nokia_5110_ESP8266.ino"
void setup();
#line 21 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\TEST_Nokia_5110_ESP8266\\TEST_Nokia_5110_ESP8266.ino"
void loop();
#line 5 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\TEST_Nokia_5110_ESP8266\\TEST_Nokia_5110_ESP8266.ino"
void setup() {
    // инициализация и очистка дисплея
    display.begin();
    //display.clearDisplay();
    //display.display();
    delay(1000);
    display.setContrast(60); // установка контраста
    //delay(1000);
    //display.setTextSize(1);  // установка размера шрифта
    //display.setTextColor(BLACK); // установка цвета текста
    //display.setCursor(0,0); // установка позиции курсора
  
    //display.println("!!!!!!!!!!");
    //display.display();
}

void loop() {
}

