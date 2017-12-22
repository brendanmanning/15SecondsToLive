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

 /**
  * Prepares the default state by making sure all lights are off
  * 
  * Should be called in the setup() function
  */
 void StatusIndicator::init() {
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
 }

 /**
  * The unlocked (green) state.
  * 
  * In order to keeps the lights on for longer than a millisecond, call in every iteration of the loop() function
  */
 void StatusIndicator::unlocked() {
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
 }


 /**
  * The locked (red) state.
  * 
  * In order to keeps the lights on for longer than a millisecond, call in every iteration of the loop() function
  */
 void StatusIndicator::locked() {
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
 }

