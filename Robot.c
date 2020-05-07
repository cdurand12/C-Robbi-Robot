#include <bcm2835.h>
#include "Robot.h"
#include "MotorHat.h"
#include "Servo.h"
int lefttrim;
int righttrim;


//robotinit - accepts the i2c address, id for the left and right Motors
//this allows the motors to be utilized
void robotInit(unsigned int address, int left_id, int right_id, int left_trim, int right_trim)
{
	hatInit(address, 1600);

	motor left = getMotor(left_id);
	motor right = getMotor(right_id);
	lefttrim = left_trim;
	righttrim = right_trim;

	run(left_id, RELEASE);
	run(right_id, RELEASE);

	//Motors should stop once program stops
	//atexit(stop());

}
void leftSpeed(int num, int speed)
{
	speed = speed + lefttrim;
	if(speed < 0){
		speed = 0;
	}
	if(speed > 255){
			speed = 255;
	}
	setSpeed(num, speed);
}
void rightSpeed(int num, int speed)
{
	speed = speed + righttrim;
  if(speed < 0){
  	speed = 0;
	}
	if(speed > 255){
		speed = 255;
	}
	setSpeed(num, speed);
}
void stop(int leftM, int rightM)
{
	run(leftM, RELEASE);
	run(rightM, RELEASE);
}
void forward(int leftM, int rightM, int speed, int seconds)
{

	leftSpeed(leftM, speed);
	rightSpeed(rightM, speed);
	run(leftM, BACKWARD);
	run(rightM, FORWARD);
	if( seconds != 0)
	{
		bcm2835_delay(seconds*1000);
		stop(leftM, rightM);
	}
}
void backward(int leftM, int rightM, int speed, int seconds)
{
	leftSpeed(leftM, speed);
  rightSpeed(rightM, speed);
  run(leftM, FORWARD);
  run(rightM, BACKWARD);
  if( seconds != 0)
  {
    bcm2835_delay(seconds*1000);
    stop(leftM, rightM);
  }
}

void right(int leftM, int rightM,int speed, int seconds)
{
	leftSpeed(leftM, speed);
  rightSpeed(rightM, speed);
  run(leftM, BACKWARD);
  run(rightM, BACKWARD);
  if( seconds != 0)
  {
    bcm2835_delay(seconds*250);
    stop(leftM, rightM);
  }
}
void left(int leftM, int rightM,int speed, int seconds)
{
	leftSpeed(leftM, speed);
  rightSpeed(rightM, speed);
  run(leftM, FORWARD);
  run(rightM, FORWARD);
  if( seconds != 0)
  {
    bcm2835_delay(seconds*250);
    stop(leftM, rightM);
  }

}
// int main()
// {
// 	robotInit( 0x60, 1, 2, 0, 0);
// 	forward(0,1, 200, 5);
// 	backward(0,1, 200, 2);
// 	left(0,1, 200, 2);
// 	right(0,1, 200, 5);
// }

int main(){
	//initialize the sensor pins
	startInit();
	//bcm2835_gpio_write(TRIG,LOW);
	//bcm2835_delay(2);
	//intializes the motor pins
	robotInit(0x60, 1, 2, 0, 0);
	//forward(0, 1, 100, 1);
	while(1){
		double Test = doubleDistance();
		printf("Distance: %.2f", Test);
		//if there is an object 30 cm in front
		if(Test <= 30){
			backward(0, 1, 20, 2);
			right(0, 1, 10, 1);
		}
		//if there isn't anything infront of robbi
		else{
			forward(0, 1, 70, 1);
		}
	}

}
