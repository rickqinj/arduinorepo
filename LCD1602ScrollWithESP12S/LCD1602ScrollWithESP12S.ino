/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>

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

bool startWPSPBC() {
  Serial.println("WPS config start");
  // WPS works in STA (Station mode) only -> not working in WIFI_AP_STA !!! 
  WiFi.mode(WIFI_STA);
  delay(1000);
  WiFi.begin("foobar",""); // make a failed connection
  while (WiFi.status() == WL_DISCONNECTED) {
    delay(500);
    Serial.print(".");
  }
  bool wpsSuccess = WiFi.beginWPSConfig();
  if(wpsSuccess) {
      // Well this means not always success :-/ in case of a timeout we have an empty ssid
      String newSSID = WiFi.SSID();
      if(newSSID.length() > 0) {
        // WPSConfig has already connected in STA mode successfully to the new station. 
        Serial.printf("WPS finished. Connected successfull to SSID '%s'", newSSID.c_str());
        // save to config and use next time or just use - WiFi.begin(WiFi.SSID().c_str(),WiFi.psk().c_str());
        //qConfig.wifiSSID = newSSID;
        //qConfig.wifiPWD = WiFi.psk();
        //saveConfig();
      } else {
        wpsSuccess = false;
      }
  }
  return wpsSuccess; 
}

void setup() {
  Serial.begin(115200);
  
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

// the loop function runs over and over again forever
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

//void loop() {
//  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
//  // but actually the LED is on; this is because
//  // it is active low on the ESP-01)
//  delay(1000);                      // Wait for a second
//  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
//  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
//}
