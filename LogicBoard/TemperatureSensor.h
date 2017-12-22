/**
 * Class definition/header for TemperatureSensor.cpp
 */

#include "Lock.h"

 class TemperatureSensor {

  int pin;
  
  int temperature;
  float temperatureBaseline;
  
  int thresholdTemperatureHigh;
  
  void (*callback)(Lock*);
  Lock* lock; 
  
  public:
    void init(int);
    void setUpperThreshold(int);
    void setCallback( void(*f)(Lock*) );
    void tick();
 };

