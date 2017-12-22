/**
 * Class definition/header for Button.cpp
 */

 class Button {
  int pin;
  void (*callback);

  public:
    void init(int);
    void setCallback( void (*f) );
    void tick();
 };
