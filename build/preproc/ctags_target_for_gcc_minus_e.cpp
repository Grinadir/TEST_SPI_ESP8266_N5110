# 1 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\TEST_Nokia_5110_ESP8266\\TEST_Nokia_5110_ESP8266.ino"
# 2 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\TEST_Nokia_5110_ESP8266\\TEST_Nokia_5110_ESP8266.ino" 2
# 3 "C:\\Users\\Alexsandr\\Documents\\Arduino\\ARDUINO_PROJECT\\TEST_Nokia_5110_ESP8266\\TEST_Nokia_5110_ESP8266.ino" 2
Adafruit_PCD8544 display = Adafruit_PCD8544(14, 13, 4, 15, 5);

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
