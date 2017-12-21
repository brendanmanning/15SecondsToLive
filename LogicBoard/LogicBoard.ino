/**
 * Bishop Shanahan STEM Development 2018
 * Fifteen Seconds Could Save A Life
 * (Door that unlocks automatically in the event of fire)
 * 
 * Code below is Copyright 2017 Brendan Manning. All rights reserved.
 */

/* Library Imports */
#include <Servo.h>

/* Temperature sensor setup */
const int temperatureSensorPin = A0;
const float temperatureBaseline = 20.0;
const int temperatureDelta = 0;

/* Servo setup */

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  /* Read from the temperature sensor */
  int temperatureDelta = analogRead(temperatureSensorPin);
  Serial.print("Sensor value: ");
  Serial.println(temperatureDelta);
}
