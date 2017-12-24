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
 * Set the lock object that is passed to the callback
 */
 void TemperatureSensor::setLockObject(Lock* l) {
  lock = l;
 }

 /**
  * Sets the update threshold
  */
  void TemperatureSensor::setUpdateThreshold(int threshold) {
    updateTemperatureThreshold = threshold;
  }

  /**
  * Sets the callback for when the temperature has significantly changed
  */
 void TemperatureSensor::setUpdateCallback( void(*f)(int, StatusIndicator*) ) {
    updatecallback = f;
 }

 /**
  * Sets the status indicator object (which controls the LED)
  */
  void TemperatureSensor::setStatusIndicatorObject(StatusIndicator* si) {
    statusindicator = si;
  }

 /**
  * Checks if the temperature is above the safe threshold, and if it is, calls the callback
  * 
  * Should be called at the start loop()
  */
 void TemperatureSensor::tick() {

  // Read the sensor's value
  int sensorValue = analogRead(A0);

  // Convert to voltage
  float voltage = (sensorValue/1024.0) * 5.0;

  // Convert to degrees centigrade
  float celcius = (voltage - .5) * 100;

  // Convert to fahrenheit
  float temperature = (celcius * (9.0/5.0)) + 32;

  // Should we change the update threshold value?
  if( (lastUpdateTemperature == -999999.0) || (lastUpdateTemperature - temperature > updateTemperatureThreshold) || (temperature - lastUpdateTemperature > updateTemperatureThreshold) ) {
    lastUpdateTemperature = temperature;
    updatecallback(temperature, statusindicator);
  }

  // Is this above the threshold value?
  if(temperature > thresholdTemperatureHigh) {
    callback(lock);
  }
  
 }

