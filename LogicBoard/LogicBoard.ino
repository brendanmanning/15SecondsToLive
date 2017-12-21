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
int servoPin = 9;
Servo servo;
int servoAngle;

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);

  servo.write(45);
}

void loop() {
  
  /* Read from the temperature sensor */
  int temperatureDelta = analogRead(temperatureSensorPin);
  Serial.print("Sensor value: ");
  Serial.println(temperatureDelta);

  servo.write(179);
  delay(1500);
  servo.write(0);
  delay(1500);
}
