/**
 * Class definition/header for Button.cpp
 */
#include "Lock.h"

 class Button {
  int pin;
  bool pressed;
  void (*callback)(Lock*);
  Lock* lock;
  public:
    void init(int);
    void setCallback( void (*f)(Lock*) );
    void setLockObject(Lock*);
    void tick();
 };
