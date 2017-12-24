/**
 * Type heading/definition for StatusIndicator.cpp
 */

#ifndef STATUSINDICATOR
#define STATUSINDICATOR 
 class StatusIndicator {
  void clearLine(int);
  public:
    void init(int,int);
    void unlocked();
    void locked();
    void setStatus(String);
    void setTemperature(int);
 };
#endif

