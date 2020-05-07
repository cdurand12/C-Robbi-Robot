//This library will contain all of the header information for the robot.

#ifndef ROBOT
#define ROBOT

//#ifndef Sensor
//#define Sensor



//By default the ID of the robot motors will be left_id = 1 and right_id = 2 and the default
//values for both trim will be set to 0
void robotInit(unsigned int address, int left_id, int right_id, int left_trim, int right_trim);
void leftSpeed(int num, int speed);
void rightSpeed(int num, int speed);
void stop(int leftM, int rightM);
void forward(int leftM, int rightM, int speed, int seconds);
void backward(int leftM, int rightM,int speed, int seconds);
void right(int leftM, int rightM,int speed, int seconds);
void left(int leftM, int rightM,int speed, int seconds);


//Sensor.c functions
double get_time();
void gpio_reset();
void startInit();
double doubleDistance();


#endif
