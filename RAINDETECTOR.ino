#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int rainPin = 2;
int buzzer = 8;

void setup() {
  pinMode(rainPin, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Rain Detector");
  delay(2000);
  lcd.clear();
}

void loop() {

  int rain = digitalRead(rainPin);

  if (rain == LOW) {

    digitalWrite(buzzer, HIGH);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("RAIN DETECTED");
    lcd.setCursor(0,1);
    lcd.print("Raining");

  } 
  else {

    digitalWrite(buzzer, LOW);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Rain");
    lcd.setCursor(0,1);
    lcd.print("Weather Clear");
  }

  delay(500);
}
