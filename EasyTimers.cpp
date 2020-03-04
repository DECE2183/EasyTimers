#include "EasyTimers.h"


////////////////////////////////////////
//               ETimer               //

ETimer::ETimer() {
  _last_trigger_time = 0;
  _delay = 0;
}

ETimer::ETimer(uint16_t delay) {
  _last_trigger_time = 0;
  _delay = delay;
}

uint16_t ETimer::getDelay() {
  return _delay;
}

uint32_t ETimer::getLastTriggerTime() {
  return _last_trigger_time;
}

void ETimer::reset() {
  _last_trigger_time = 0;
}

void ETimer::setDelay(uint16_t delay) {
  _delay = delay;
  reset();
}

bool ETimer::check() {
  if (millis() - _last_trigger_time >= _delay) {
    _last_trigger_time = millis();
    return true;
  } else
    return false;
}

//               ETimer               //
////////////////////////////////////////


////////////////////////////////////////
//               EThread              //

EThread::EThread(uint16_t delay) {
  timer.setDelay(delay);
  state = STOPED;
  _has_callback = false;
}

EThread::EThread(uint16_t delay, void (*func)(bool)) {
  timer.setDelay(delay);
  state = STOPED;
  _callback_function = func;
  _has_callback = true;
}

EThread::EThread(void (*func)(bool)) {
  timer.setDelay(0);
  state = STOPED;
  _callback_function = func;
  _has_callback = true;
}

bool EThread::hasCallback() {
  return _callback_function;
}

bool EThread::getState() {
  return state;
}

void EThread::setCallback(void (*func)(bool)) {
  _callback_function = func;
  _has_callback = true;
}

void EThread::start() {
  state = RUNNING;
  _execute_callback();
}

void EThread::pause() {
  state = STOPED;
  _execute_callback();
}

void EThread::update() {
  if (state == true && timer.check() == true) {
    _execute_callback();
  }
}

void EThread::_execute_callback() {
  if (_has_callback == true) {
    _callback_function(state);
  } else {
    state = STOPED;
  }
}

//               EThread              //
////////////////////////////////////////
