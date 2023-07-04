//in this example we are receiving the target we sent as we have set motor1.monitor_variables = _MON_TARGET. for receiving other parameters we can change this line accordingly

#include <SimpleFOC.h>

BLDCMotor motor = BLDCMotor(7);
BLDCDriver3PWM driver = BLDCDriver3PWM(32, 33, 25, 22);

BLDCMotor motor1 = BLDCMotor(7);
BLDCDriver3PWM driver1 = BLDCDriver3PWM(26, 27, 14, 12);

//Target variable
float target_velocity = 0;
float target_velocity1 = 0;

//Serial command setting
Commander command = Commander(Serial);
void doTarget(char* cmd) { command.scalar(&target_velocity, cmd); }
void doTarget1(char* cmd) { command.scalar(&target_velocity1, cmd); }

void setup() {

  driver.voltage_power_supply = 12;
  driver.init();
  motor.linkDriver(&driver);
  motor.voltage_limit = 3;   // [V]
  motor.velocity_limit = 15; // [rad/s]
  
  driver1.voltage_power_supply = 12;
  driver1.init();
  motor1.linkDriver(&driver1);
  motor1.voltage_limit = 3;   // [V]
  motor1.velocity_limit = 15; // [rad/s]

 
  //Open loop control mode setting
  motor.controller = MotionControlType::angle_openloop;
  motor1.controller = MotionControlType::angle_openloop;

  //Initialize the hardware
  motor.init();
  motor1.init();


  //Add T command
  command.add('A', doTarget, "target velocity");
  command.add('B', doTarget1, "target velocity");

  Serial.begin(115200);
  motor.useMonitoring(Serial);
 c;
  motor.monitor_downsample = 100;
  motor.monitor_decimals = 3;
  motor.monitor_start_char = 'A';
  motor1.useMonitoring(Serial);
  motor1.monitor_variables = _MON_TARGET;
  motor1.monitor_downsample = 100;
  motor1.monitor_decimals = 3;
  motor1.monitor_start_char = 'B';
  _delay(1000);
}

void loop() {
  motor.move(target_velocity);
  motor1.move(target_velocity1);
  motor.monitor();
  motor1.monitor();

  //User newsletter
  command.run();
}