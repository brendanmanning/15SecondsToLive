/**
 * Lock.cpp
 * 
 * This file provides helper methods for manitulating the state of the lock
 * 
 * This lock works by driving a fixed servo back and forth. That servo is manipulated here
 */

 #include "Arduino.h"
 #include "Lock.h"
 #include <Servo.h>

 /**
  * Initilizes the lock: 
  * Connects the servo, sets default locked/unlocked state (which is asssumed to be false), and logs to the console
  * 
  * Should be called in the setup() function
  */
 void Lock::init(int pin) {
  servo = Servo();
  servo.attach(9);

  locked = false;
  
  Serial.println("[ log ]: Lock initilized!");
 }

 /**
  * Locks the door (waiting approximately 1 second to give the servo time to move)
  * 
  * (Also logs the action to the console
  */
 void Lock::lock() {
  Serial.println("[ log ]: Locking...");
  
  servo.write(10);
  delay(1500);

  locked = true;

  Serial.println("[ log ]: Locked!");
 }

 /**
  * Locks the door (waiting approximately 1 second to give the servo time to move)
  * 
  * (Also logs the action to the console
  */
 void Lock::unlock() {
  Serial.println("[ log ]: Unlocking...");
 
  servo.write(170);
  delay(1500);

  locked = false;

  Serial.println("[ log ]: Unlocked!");
 }

 /**
  * Accessor method for the current locked/unlocked state
  */
 bool Lock::isLocked() {
  return locked;
 }

