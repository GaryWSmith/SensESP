#ifndef _ultrasonic_distance_H_
#define _ultrasonic_distance_H_
#include "sensor.h"

// FIXME: This class would need at least some minimal documentation
class UltrasonicDistance : public NumericSensor {
 public:
  UltrasonicDistance(int8_t trigger_pin, int8_t input_pin,
                     uint read_delay = 1000, String config_path = "");
  void enable() override final;
  uint read_delay;

 private:
  int8_t trigger_pin;
  int8_t input_pin;
  virtual void get_configuration(JsonObject& doc) override;
  virtual bool set_configuration(const JsonObject& config) override;
  virtual String get_config_schema() override;
};

[[deprecated("Use UltrasonicDistance instead.")]]
typedef UltrasonicDistance UltrasonicSens;

#endif
