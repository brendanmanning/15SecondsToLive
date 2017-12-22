/**
 * Bishop Shanahan STEM Development 2018
 * Fifteen Seconds Could Save A Life
 * (Door that unlocks automatically in the event of fire)
 * 
 * Code below is Copyright 2017 Brendan Manning. All rights reserved.
 */

/* Arduino Library Imports */
#include <Servo.h>

/* Custom-made Library Imports */
#include "Lock.h"
#include "StatusIndicator.h"
#include "Button.h"

/* Temperature sensor setup */
const int temperatureSensorPin = A0;
const float temperatureBaseline = 20.0;
const int temperatureDelta = 0;

Lock lock = Lock();
StatusIndicator statusindicator = StatusIndicator();
Button insideButton = Button();
void setup() {

  Serial.begin(9600);

  lock.init(9);
  lock.lock();

  statusindicator.init();

  insideButton.init(7);
  insideButton.setCallback(&internalButtonOnClick);
  insideButton.setLockObject(&lock);
}

void loop() {

  // Listen for button presses
  insideButton.tick();

  // Keep the status lights in sync
  if(lock.isLocked()) {
    statusindicator.locked();
  } else {
    statusindicator.unlocked();
  }
  
}

/**
 * Called every time the button is pressed
 * 
 * Should lock/unlock the door from the inside
 */
void internalButtonOnClick(Lock* lock) {
  if(lock->isLocked()) {
    lock->unlock();
  } else {
    lock->lock();
  }
}

