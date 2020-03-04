#include "EasyTimers.h"

ETimer::ETimer(uint16_t delay)
{
    _triggerTime = 0;
    _delay = delay;
}

void ETimer::setDelay(uint16_t delay)
{
    _delay = delay;
}

bool ETimer::check()
{
    if (millis() - _triggerTime >= _delay)
    {
        _triggerTime = millis();
        return true;
    }
    else
        return false;
}
