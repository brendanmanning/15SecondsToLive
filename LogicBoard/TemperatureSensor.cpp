/**
 * TemperatureSensor.cpp
 * 
 * Manages the thermometer and defines a callback for when it is too hot
 *
 */

#include "Arduino.h";
#include "TemperatureSensor.h"

 /**
  * Initilizes the sensor by saving its pin
  * 
  * Note, since this uses analogRead, we don't need pinMode()
  */
 void TemperatureSensor::init(int p) {
  pin = p;
 }

 /**
  * Sets the upper threshold temperature (in degrees Fahrenheit)
  */
  void TemperatureSensor::setUpperThreshold(int limit) {
    thresholdTemperatureHigh = limit;
  }

 /**
  * Sets the callback for when the maximum temperature is exceeded
  */
 void TemperatureSensor::setCallback( void(*f)(Lock*) ) {
  callback = f;
 }

 /**
  * Checks if the temperature is above the safe threshold, and if it is, calls the callback
  * 
  * Should be called at the start loop()
  */
 void TemperatureSensor::tick() {

  // Read the sensor's value
  int sensorValue = analogRead(pin);

  // Convert to voltage
  float voltage = (temperature/1024.0) * 5.0;

  // Convert to degrees centigrade
  float celcius = (voltage - .5) * 100;

  // Convert to fahrenheit
  temperature = celcius * (5.0/9.0) + 32;

  Serial.print("Temperature: ");
  Serial.println(temperature);

  // Is this above the threshold value?
  if(temperature > thresholdTemperatureHigh) {
    callback(lock);
  }
  
 }

