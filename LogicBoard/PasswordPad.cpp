
/**
 * PasswordPad.cpp
 * 
 * Interfaces with the Keypad lock
 *
 */

 #include "Arduino.h"
 #include "Lock.h"
 #include "PasswordPad.h"
 #include <Keypad.h>
 #include <EEPROM.h>


 const byte ROWS = 4;
 const byte COLS = 4;

 char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
 };

 byte rowPins[ROWS] = {9,8,7,6};
 byte colPins[COLS] = {5,4,3,2};

 Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

 void PasswordPad::tick() {
  char key = keypad.getKey();

  if(key) {
    // The asterisk is the end sequence key
    if(key == '*') {

      // Did whatever action we do work out?
      if(handleInput(input)) {
        
      }
    }

    // Otherwise, just append to the buffer we're keeping
    else {
      input += key;
    }
  }
 }

 void handleInput(String i) {

  // Does the user want to change the password?
  if(i == "CC") {
    changePassword = true;
    canChangePassword = false;
    return;
  }

  // Is the user validating to enter a new password?
  if(changePassword && !canChangePassword) {
    if(i == getPassword()) {
      canChangePassword = true;
      return true;
    } else {
      changePassword = false;
      canChangePassword = false;
      return false;
    }
  }

  // Is the user entering the new password?
  if(changePassword && canChangePassword) {
    EEPROM.write(0, i);
    return true;
  }

  // Is the user just straight up entering a password?
  if(i == getPassword()) {
    callback(lock);
    return true;
  } else {
    return false;
  }
 }

 void PasswordPad::setCallback( void(*f)(Lock*) ) {
  callback = f;
 }

 void PasswordPad::setLockObject(Lock* l) {
  lock = l;
 }

 void PasswordPad::setPassword(String s) {
  password = s;
 }

