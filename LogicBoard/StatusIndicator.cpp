/**
 * StatusIndicator.cpp
 * 
 * This manages a set of two LEDs: One red, One green
 * Only one light will ever be active at any given time, based on whether locked() or unlocked() was called last
 * 
 * Pin 12 = green (unlocked)
 * Pin 13 = red (locked)
 */

 #include "Arduino.h";
 #include "StatusIndicator.h";
 #include <LiquidCrystal.h>
 LiquidCrystal lcd(12,11,5,4,3,2);

 /**
  * Utility function, clears just one line
  */
  void StatusIndicator::clearLine(int line) {
    lcd.setCursor(0,line);
    lcd.print("                ");
    lcd.setCursor(0,line);
  }
 
 /**
  * Prepares the default state by making sure all lights are off
  * 
  * Should be called in the setup() function
  */
 void StatusIndicator::init(int f,int s) {
  lcd.begin(f,s);
  //pinMode(9, OUTPUT);
  //pinMode(10, OUTPUT);
 }

 /**
  * The unlocked (green) state.
  * 
  * In order to keeps the lights on for longer than a millisecond, call in every iteration of the loop() function
  */
 void StatusIndicator::unlocked() {
  clearLine(0);
  lcd.print("Status: Open");
 }


 /**
  * The locked (red) state.
  * 
  * In order to keeps the lights on for longer than a millisecond, call in every iteration of the loop() function
  */
 void StatusIndicator::locked() {
  clearLine(0);
  lcd.print("Status: Locked");
 }


void StatusIndicator::setStatus(String s) {
  clearLine(0);
  lcd.print("Status: ");
  lcd.print(s);
}

void StatusIndicator::setTemperature(int t) {
  clearLine(1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.setCursor(0,0);
}

