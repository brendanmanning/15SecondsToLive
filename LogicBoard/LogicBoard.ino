/**
 * Bishop Shanahan STEM Development 2018
 * Fifteen Seconds Could Save A Life
 * (Door that unlocks automatically in the event of fire)
 * 
 * Code below is Copyright 2017 Brendan Manning. All rights reserved.
 */

/* Arduino Library Imports */
#include <Servo.h>
#include <LiquidCrystal.h>

/* Custom-made Library Imports */
#include "Lock.h"
#include "TemperatureSensor.h"
#include "Button.h"
#include "StatusIndicator.h"

Lock lock = Lock();
TemperatureSensor temperaturesensor = TemperatureSensor();
StatusIndicator statusindicator = StatusIndicator();
Button insideButton = Button();

void setup() {

  Serial.begin(9600); 

  statusindicator.init(16,2);
  statusindicator.setStatus("Booting");
                                    
  lock.init(8);
  lock.lock();

  insideButton.init(7);
  insideButton.setCallback(&internalButtonOnClick);
  insideButton.setLockObject(&lock);

  temperaturesensor.init(A0);
  temperaturesensor.setUpperThreshold(80);
  temperaturesensor.setLockObject(&lock);
  temperaturesensor.setCallback(&upperThresholdExceeded);
  temperaturesensor.setUpdateThreshold(1);
  temperaturesensor.setUpdateCallback(&temperatureUpdated);
  temperaturesensor.setStatusIndicatorObject(&statusindicator);

  statusindicator.locked();
}

void loop() {

  // Listen for button presses
  insideButton.tick();

 /* // Keep the status lights in sync
  if(lock.isLocked()) {
    statusindicator.locked();
  } else {
    statusindicator.unlocked();
  }*/

  // Check the temperature
  temperaturesensor.tick();

}

void serialEvent() {
  Serial.print("[ serial data ]: ");
  String s = "";
  while(Serial.available()) 
   {
      char ch = Serial.read();
      s+=ch;
   }
   Serial.print(s);
}

/**
 * Called every time the button is pressed
 * 
 * Should lock/unlock the door from the inside
 */
void internalButtonOnClick(Lock* lock) {
  if(lock->isLocked()) {
    lock->unlock();
    statusindicator.unlocked();
  } else {
    lock->lock();
    statusindicator.locked();
  }
}

/** Called when the temperature has advanced/descended by a fixed interval
 *  
 */
void temperatureUpdated(int temperature, StatusIndicator* statusindicator) {
  statusindicator->setTemperature(temperature);
}

/**
 * Called when the upper threshold temperature is exceeded
 */
 void upperThresholdExceeded(Lock* lock) {
  lock->unlock();
  statusindicator.unlocked();
 }

