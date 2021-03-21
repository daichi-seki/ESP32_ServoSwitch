# ESP32_ServoSwitch
Library for control Servo to toggle Switch for ESP32, M5 stack, M5 Stick...

## examples
See example example\ESP32_ServoSwitch_control\ESP32_ServoSwitch_control.cpp

### SetUp

```c++
#define SERVOPIN_1 (26)     // GPIO 26 is used for PWM
#define CHANNEL_SERVO_1 (0) // 0 - 15 can be used for PWM channel
#define SWITCH_OFF_DEG (75) // Switch OFF at 75 deg
#define SWITCH_ON_DEG (135) // Switch ON at 135 deg

ESP32_ServoSwitch switch1(SERVOPIN_1, CHANNEL_SERVO_1, SWITCH_OFF_DEG, SWITCH_ON_DEG); // Construct Switch1 object

void loop()
{
  switch1.update(); // need to be called in loop
}
```

### Fuctions

```c++
Control Switch : 
  switch1.on(); // Turn switch ON
  switch1.off(); // Turn switch OFF
  switch1.toggle(); // if switch is OFF, Turn ON. if switch is ON, Turn OFF.

Get Status :
bool switch1.Is_state_off() // if switch state is OFF (not "ON" or in middle)
bool switch1.Is_state_on()  // if switch state is ON (not "OFF" or in middle)
```