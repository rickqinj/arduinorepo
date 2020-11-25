#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const char txt1[] = "Arduino         ";
const char txt2[] = "Hello World     ";

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(txt1);
  lcd.setCursor(15, 1);
  for (int pos = 0; pos < 16; pos++) {
    lcd.print(txt2[pos]);
    lcd.scrollDisplayLeft();
    delay(300);
  }
}
