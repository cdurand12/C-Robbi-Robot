#include <bcm2835.h>
#include "MotorHat.h"
#include "Servo.h"
#include <stdio.h>
#include <stdlib.h>

int i2caddr;
int frequency;
motor list[4];


extern void dcInit()
{
	//Motor at list[0]
  list[0].pwm = 8;
  list[0].in2 = 9;
  list[0].in1 = 10;
  //Motor at list[1]
  list[1].pwm = 13;
  list[1].in2 = 12;
  list[1].in1 = 11;
  //Motor at list[2]
  list[2].pwm = 2;
  list[2].in2 = 3;
  list[2].in1 = 4;
  //Motor at list[3]
  list[3].pwm = 7;
  list[3].in2 = 6;
  list[3].in1 = 5;

}

extern void run(int num, int command)
{
	if(command == FORWARD)
	{
		setPin(list[num].in2, 0);
		setPin(list[num].in1, 1);
	}
	if(command == BACKWARD)
	{
		setPin(list[num].in1, 0);
		setPin(list[num].in2, 1);
	}
	if(command == RELEASE)
	{
		setPin(list[num].in1, 0);
		setPin(list[num].in2, 0);
	}
}

extern void setSpeed(int speed, int num)
{
	if( speed < 0){
		speed = 0;
	}
	if(speed > 255){
		speed = 255;
	}
	setPWM(list[num].pwm, 0, speed*16);
}

extern void hatInit(int addr, int freq)	//<------????
{

	i2caddr = addr;
	frequency = freq;
	init1(addr);

	dcInit();
	init1(addr);
	setPWMFreq(frequency);
}

extern void setPin(int pin, int value)
{
	if ( (pin < 0) || (pin > 15)){
		printf("PWM must be between 0 and 15 inclusive\n");
	}
	if( (value != 0) && (value != 1)){
		printf("Pin value must be 0 or 1!\n");
	}
	if(value == 0){
		setPWM(pin, 0, 4096);
	}
	if( value ==1 ){
		setPWM(pin, 4096, 0);
	}
}

extern motor getMotor(int num)
{
	return list[num-1];
}
