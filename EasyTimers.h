#ifndef ETimers
#define ETimers
#include <Arduino.h>

class ETimer
{
    private:
        uint32_t _triggerTime;
        uint16_t _delay;

    public:
        ETimer(uint16_t);             // create timer with delay in millis
        void setDelay(uint16_t);      // set timer delay in millis
        bool check();                 // check timer ready
};

#endif
