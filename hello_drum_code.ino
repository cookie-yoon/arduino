#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int sound = 8;
const int hihat = 9;
const int snare = 10;
const int bass = 11;

int i = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(hihat, INPUT);
  pinMode(snare, INPUT);
  pinMode(bass, INPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {

  lcd.setCursor(2,1);
  lcd.print("Hello Drum :D");
  
  lcd.setCursor(i,0);
  
  if (digitalRead(hihat) == 1) {
    tone(sound, 200);
    lcd.print("*");
    i = i + 1;
  }
  else if (digitalRead(snare) == 1) {
    tone(sound, 130);
    lcd.print("o");
    i = i + 1;
  }
  else if (digitalRead(bass) == 1) {
    tone(sound, 100);
    lcd.print("_");
    i = i + 1;
  }
  else {
    noTone(sound);
  }

  delay(100);
  
  if(i > 15){
    i = 0;
    lcd.clear();
  }
  
  lcd.setCursor(2,1);
  lcd.print("Hello Drum :D");
}
