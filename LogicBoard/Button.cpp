#include "Button.h";

void Button::init(int p) {
  pin = p;
}

void Button::setCallback(void (*f)) {
  callback = f;
}

void Button::tick() {
  
}

