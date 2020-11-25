# Yet Another Scrolling with LCD1602

## Table of Content

1. [General Info](#general-info)
2. [Existing Implement](#existing-implement)
3. [Open Issues](#open-issues)

## General Info

Strictly speaking, I am not talking about the original LCD1602 module but the module which is attached a Parallel to I2C interface adapter. Due to the modification done by manufacturers now we can program Arduino and let it communicate with the LCD1602 module much easier than before via I2C. And this modification simplifys the wiring between the module and Arduino board as well. We don't need to hook up 7 or 8 wires but only 4 wires instead. However, it is because of the modification that we need to import another dedicated **LiquidCrystal_I2C** lib for the operation.

You may find the lib here: [https://gitlab.com/fgomes/LiquidCrystal_I2C/-/archive/master/LiquidCrystal_I2C-master.zip](https://gitlab.com/fgomes/LiquidCrystal_I2C/-/archive/master/LiquidCrystal_I2C-master.zip)

## Existing Implement

As you may know, there are several main methods to operate LCD1602 module. They are:

| Method name                 | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| init()                      | Initialize the LCD1602 module.                               |
| backlight()                 | Enable back light of the screen. As this module is a liquid crystal screen, you can not see content clearly without backlight. |
| setCursor(col_idx, row_idx) | Set the start location on the screen where your text will be displaying from. |
| print(str)                  | Print the string specified by the argument from the location set by setCursor() method. |
| clear()                     | Clear cursor settings and screen. Remove all characters shown before. |
| scrollDisplayLeft()         | Shift all characters shown on the screen one bit left.       |

I list a snippet of pseudo code as below to show you the basic process of scrolling.

```c++
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
```

![1](D:\Workspace\arduinorepo\LCD1602Scrolling\1.gif)





## Open Issues

asdf

