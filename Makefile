robot: Robot.c
	gcc -c Robot.c -L /user/local/lib -lbcm2835
	gcc -c MotorHat.c -L /usr/local/lib -lbcm2835
	gcc -c Servo.c -L /usr/local/lib -lbcm2835 -lm
	gcc -c Sensor.c -L /usr/local/lib -lbcm2835

	gcc -o robot Robot.o MotorHat.o Servo.o Sensor.o -L /usr/local/lib -lbcm2835 -lm

clean:
	rm  *.o
