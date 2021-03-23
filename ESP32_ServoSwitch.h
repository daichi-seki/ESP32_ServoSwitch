/*ESP32_ServoSwitch.h - Library for control a Servo to toggle Switch.
  Created by Daichi SEKI, march 21, 2021.
  License : MIT */

#ifndef esp32_servoSwitch_h
#define esp32_servoSwitch_h

// Servo parameters
#define SERVO_MIN_DUTY float(2.5)   // 2.5% duty when servo is min deg
#define SERVO_MAX_DUTY float(7)     // 7.0% duty when servo is max deg
#define SERVO_MIN_DEG int(0)        // servo min 0 deg
#define SERVO_MAX_DEG int(180)      // servo max 180 deg
#define SERVO_MOVINGSTEP_DEG int(1) // servo deg is increased x deg each update steps
#define SERVO_SUSPEND_DELAY uint16_t(100) // times to suspend(detach) if suspend is enabled.

// PWM parameters
#define PWM_HZ double(50)
#define DUTY_BITRATE uint8_t(16)
#define DUTY_100_BIN uint16_t(65535)

class ESP32_ServoSwitch
{
public:
  ESP32_ServoSwitch(uint8_t pin, uint8_t channel, int switch_off_deg, int switch_on_deg, bool is_suspend_enabled);
  ~ESP32_ServoSwitch();
  void on();
  void off();
  void toggle();
  void update();
  void suspend();
  void resume();
  bool Is_state_on();
  bool Is_state_off();
  bool Is_suspend();

private:
  uint8_t _channel;
  uint8_t _pin;
  int _target_deg;
  int _current_deg;
  int _switch_off_deg;
  int _switch_on_deg;
  int _switch_mid_deg;
  int _time_to_suspend;
  bool _is_suspend;
  bool _is_suspend_enabled;
};

uint32_t deg_to_pwm(float deg);

#endif