#include "Arduino.h";
#include "Button.h";

/**
 * Binds the button object to a pin & perform necessary setup
 */
void Button::init(int p) {
  
  pin = p;
  pressed = false;
  
  pinMode(pin, INPUT);
}

/**
 * Sets callback for when the button is pressed
 */
void Button::setCallback(void (*f)(Lock*) ) {
  callback = f;
}

void Button::setLockObject(Lock* l) {
  lock = l;
}

/**
 * Checks the state and calls the callback on presses
 * 
 * Should calledm at the beginning of loop()
 */
void Button::tick() {
  if(digitalRead(pin) == HIGH && !pressed) {
    pressed = true;
    callback(lock);
  } else if(digitalRead(pin) == LOW && pressed) {
    pressed = false;
  }
}

