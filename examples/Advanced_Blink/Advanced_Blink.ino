#include <EasyTimers.h>

ETimer test_timer(1000);                  // create timer with 1000 ms delay

bool led_flag = false;               // LED state variable

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (test_timer.check() == true)        // check timer ready
  {
    led_flag = !led_flag;            // invert LED flag
    digitalWrite(LED_BUILTIN, led_flag);  // set LED state from flag
  }
}