#include <Arduino.h>
#include "ESP32_ServoSwitch.h"

#define SERVOPIN_1 (26)     // GPIO 26 is used for PWM
#define CHANNEL_SERVO_1 (0) // 0 - 15 can be used for PWM channel
#define SWITCH_OFF_DEG (75) // Switch OFF at 75 deg
#define SWITCH_ON_DEG (135) // Switch ON at 135 deg

int toggle = 0;
ESP32_ServoSwitch switch1(SERVOPIN_1, CHANNEL_SERVO_1, SWITCH_OFF_DEG, SWITCH_ON_DEG); // Construct Switch1 object
// please see "ESP32_ServoSwitch.h", servo parameter is configuable

void setup()
{
}

void loop()
{
  switch1.update(); // need to be called in loop

  if (switch1.Is_state_off()) // if switch state is OFF (not "ON" or in middle)
  {
    switch1.on(); // Turn switch ON
  }
  else if (switch1.Is_state_on()) // if switch state is ON (not "OFF" or in middle)
  {
    switch1.off(); // Turn switch OFF
  }

  if (toggle == 1)
  {
    switch1.toggle(); // if switch is OFF, Turn ON. if switch is ON, Turn OFF.
  }

  delay(100);
}