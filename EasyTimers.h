#ifndef ETimers
#define ETimers
#include <Arduino.h>

#define STOPED 0
#define RUNNING 1

class ETimer
{
  private:
    uint32_t _last_trigger_time;
    uint16_t _delay;

  public:
    ETimer();                      // create timer with 0 delay
    ETimer(uint16_t);              // create timer with delay in millis

    void setDelay(uint16_t);       // set timer delay in millis
    uint16_t getDelay();           // get timer delay in millis
    uint32_t getLastTriggerTime(); // get last trigger time

    void reset();                  // reset last trigger time
    bool check();                  // check timer ready
};

class EThread
{
  private:
    void (*_callback_function)(bool state);
    bool _has_callback;

    void _execute_callback();

  public:
    ETimer timer;                  // timer object
    bool   state;                  // state of thread (may be STOPED or RUNNING)

    EThread(uint16_t);                            // create thread with delay in millis
    EThread(uint16_t, void (*func)(bool state));  // create thread with delay in millis and callback function
    EThread(void (*func)(bool state));            // create thread with callback function and 0 delay

    void setCallback(void (*func)(bool state));   // set callback function

    void start();                  // resume thread
    void pause();                  // pause thread
    void update();                 // process thread

    bool hasCallback();            // returns true if callback function is set
    bool getState();               // returns thread state
};

#endif
