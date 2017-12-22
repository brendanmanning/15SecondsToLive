/**
 * Type heading/definition for Lock.cpp
 */


#include <Servo.h>

#ifndef LOCK 
#define LOCK
class Lock {
  boolean locked;
  Servo servo;
  public:
    void init(int pin);
    void lock();
    void unlock();
    bool isLocked();
};
#endif
