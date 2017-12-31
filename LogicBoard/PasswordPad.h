/**
 * Type heading/definition for PasswordPad.cpp
 */


#include "Lock.h"

#ifndef PAD 
#define PAD
class PasswordPad {

  /* Internal variables */
  String input = "";
  boolean changePassword = false;
  boolean canChangePassword = false;
  void (*callback)(Lock*);
  Lock* lock;

  /* Internal functions */
  void handleInput(String);
  void getPassword();
  void changePassword();
  
  public:
    void tick();
    void setCallback( void(*f)(Lock*) );
    void setLockObject(Lock*);
    void setPassword(String);
};
#endif
