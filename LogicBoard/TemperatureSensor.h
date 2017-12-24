/**
 * Class definition/header for TemperatureSensor.cpp
 */

#include "Lock.h"
#include "StatusIndicator.h"

 class TemperatureSensor {

  int pin;
  
  float temperatureBaseline;
  int updateTemperatureThreshold;
  float lastUpdateTemperature = -999999.0;
  
  int thresholdTemperatureHigh;
  
  void (*callback)(Lock*);
  Lock* lock; 

  void (*updatecallback)(int, StatusIndicator*);
  StatusIndicator* statusindicator;
  
  public:
    void init(int);
    void setUpperThreshold(int);
    void setCallback( void(*f)(Lock*) );
    void setLockObject(Lock*);

    void setUpdateThreshold(int);
    void setUpdateCallback( void(*f)(int,StatusIndicator*) );
    void setStatusIndicatorObject(StatusIndicator*);
    
    void tick();
 };

