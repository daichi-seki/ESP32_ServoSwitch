# ESP32_ServoSwitch
Library for pushing Switches by Servo(SG90 or) on ESP32 (incl. M5 stack, M5Stick-C and...)

## example
See example example\ESP32_ServoSwitch_control\ESP32_ServoSwitch_control.cpp

This liblary is tested on following environemnt

Hardware : 
* Board : M5Stick-C
* Servo : SG90

Wiring :
* Servo control Pin : GPIO26 on M5Stick-C
* Servo power supply pin : 5V pin on M5Stick-C
* Servo GND pin :  GND pin on M5Stick-C


### SetUp

```c++
#include <Arduino.h>
#include "ESP32_ServoSwitch.h"

#define SERVOPIN_1 (26)     // GPIO 26 is used for PWM
#define CHANNEL_SERVO_1 (0) // 0 - 15 can be used for PWM channel
#define SWITCH_OFF_DEG (75) // Switch OFF at 75 deg
#define SWITCH_ON_DEG (135) // Switch ON at 135 deg
#define SUSPEND_ENABLED (true) // Enable suspend support. (avoid shaking by detaching servo after few seconds)

ESP32_ServoSwitch switch1(SERVOPIN_1, CHANNEL_SERVO_1, SWITCH_OFF_DEG, SWITCH_ON_DEG, SUSPEND_ENABLED); // Construct Switch1 object

void loop()
{
  switch1.update(); // need to be called in loop()
}
```

### Fuctions

```c++
Control Switch : 
  switch1.on(); // Turn switch ON
  switch1.off(); // Turn switch OFF
  switch1.toggle(); // if switch is OFF, Turn ON. if switch is ON, Turn OFF.

Get Status :
  bool switch1.Is_state_off() // get switch status : if switch state is OFF (not "ON" or in middle)
  bool switch1.Is_state_on()  // get switch status : if switch state is ON (not "OFF" or in middle)
```
