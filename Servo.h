//moveServo.h header file
//header file- contains prototypes (return, name, params) for functions


#ifndef libs
#define libs

#define __MODE1 0x00
#define __MODE2 0x01
#define __SUBADR1 0x02
#define __SUBADR2 0x03
#define __SUBADR3 0x04
#define __PRESCALE 0xFE
#define __LED0_ON_L 0x06
#define __LED0_ON_H 0x07
#define __LED0_OFF_L 0x08
#define __LED0_OFF_H 0x09
#define __ALL_LED_ON_L 0xFA
#define __ALL_LED_ON_H 0xFB
#define __ALL_LED_OFF_L 0xFC
#define __ALL_LED_OFF_H 0xFD

  //Bits
#define __RESTART 0x80
#define __SLEEP 0x10
#define __ALLCALL 0x01
#define __INVRT 0x10
#define __OUTDRV 0x04

char buffer[2];
float prescaleval;
float prescale;
unsigned int oldmode;
unsigned int newmode;
void init1(unsigned int address);
int init2(unsigned int slave_address);
void setPWMFreq(int freq); //sets the PWM frequency


void setPWM(int channel, int on, int off); //set a single PWM channel
void setAllPWM(int on, int off);		//set all PWM channels
void write8(unsigned char reg, unsigned char value);		//writes 8-bit value to register/address
unsigned int readU8(unsigned char reg);				//read an unsigned byte from the I2C device

#endif