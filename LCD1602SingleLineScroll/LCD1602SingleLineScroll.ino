#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LCD screen width.
int screenWidth = 16;
//Your text
const String fixedTxt = "CANADA";
//Original text
const String originalTxt = "Welcome to Niagara Falls!!!";
//Scroll text
String scrollTxt;
//Display screen
LiquidCrystal_I2C lcd(0x27, screenWidth, 2);


void setup() {
  //Padding 16 space at the end of the scroll text.
  String paddingSpaces;
  for (int i = 0; i < screenWidth; i++) {
    paddingSpaces += " ";
  }
  scrollTxt += paddingSpaces;
  scrollTxt += originalTxt;
  scrollTxt += paddingSpaces;
  
  lcd.init();
  lcd.backlight();
}

int startIdx = 0;
void loop() {
  lcd.setCursor(5, 1);
  lcd.print(fixedTxt);

  startIdx = startIdx % (scrollTxt.length() - screenWidth);
  lcd.setCursor(0, 0);
  lcd.print(scrollTxt.substring(startIdx, screenWidth + startIdx));
  startIdx++;

  delay(350);
}
