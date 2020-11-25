#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const char text1[] = "http://letshavefun.epizy.com";
const char text2[] = "Welcome to letshavefun!-";

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  while (!Serial) {;}
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Arduino");
}

void loop() {
//  lcd.clear();
  lcd.setCursor(15, 1);
  for (int pos = 0; pos < 28; pos++) {
    lcd.print(text1[pos]);
    Serial.println(text1[pos]);
    lcd.scrollDisplayLeft();
    delay(300);
  }
//  lcd.clear();
//  lcd.setCursor(16, 1);
//  for (int pos = 0; pos < 24; pos++) {
//    lcd.print(text2[pos]);
//    Serial.println(text2[pos]);
//    lcd.scrollDisplayLeft();
//    delay(300);
//  }
//  lcd.clear();
}
