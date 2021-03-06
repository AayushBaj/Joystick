#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     irs,            sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S2_C1_1,     motorD,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S2_C1_2,     motorE,        tmotorTetrix, PIDControl, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     motorF,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S2_C2_2,     motorG,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C3_2,     motorI,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_6,    servo6,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S3_C1_1,    servo7,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S3_C1_2,    servo8,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S3_C1_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int motor1speed;
int motor2speed;
int motor3speed;
int motor4speed;

void initializeRobot()
{
	servo[servo1] = 0;
	servo[servo2] = 256;
	servo[servo3] = 256;
	servo[servo7] = 127;

	return;
}

task main()
{

	initializeRobot();

	while(true) // Infinite loop:
	{
		getJoystickSettings(joystick); // Robot control SAURABH

		motor1speed = joystick.joy1_y1;
		motor2speed = joystick.joy1_y2;
		motor3speed = joystick.joy1_y1;
		motor4speed = joystick.joy1_y2;

		///////////////////////////////////////////////////////////////////////////
		////////////////////////////DRIVER 1//////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////

		if(joystick.joy1_y1 || joystick.joy1_y2) //reducing the motor speed by half
		{
			motor[motorD] = motor1speed/2;
			motor[motorE] = motor2speed/2;
			motor[motorF] = motor3speed/2;
			motor[motorG] = motor4speed/2;
		}

		else //brake when there is no joystick value
		{
			motor[motorD] = 0;
			motor[motorE] = 0;
			motor[motorF] = 0;
			motor[motorG] = 0;
		}

		if(joy1Btn(1) == 1)//80 20 goes up or down (30 CM)
		{
			motor[motorH] = 60;
			motor[motorI] = 60;
			wait1Msec(1975);
			motor[motorH] = 0;
			motor[motorI] = 0;
		}

		if(joy1Btn(3) == 1)//80 20 goes up or down (90 CM)
		{
			motor[motorH] = 30;
			motor[motorI] = 30;
			wait1Msec(7125);
			motor[motorH] = 0;
			motor[motorI] = 0;
		}

		if(joy1Btn(4) == 1)//80 20 goes up or down (60 CM)
		{
			motor[motorH] = 60;
			motor[motorI] = 60;
			wait1Msec(3950);
			motor[motorH] = 0;
			motor[motorI] = 0;
		}

		if(joy1Btn(5) == 1) //Arm goes up (not precise)
		{
			servo[servo4] = 80;
			servo[servo5] = 166;
		}

		if(joy1Btn(6) == 1) //Arm goes down (not precise)
		{
			servo[servo4] = 80;
			servo[servo5] = 166;
			wait1Msec(200);

			servo[servo4] = 256;
			servo[servo5] = 0;
		}

		if(joy1Btn(7) == 1) //Arm assist (precise)
		{
			servo[servo6] = 256;
			wait1Msec(3);
		}

		else if(joy1Btn(8) == 1) //Arm assist (precise)
		{
			servo[servo6] = 0;
			wait1Msec(3);
		}

		else
		{
			servo[servo6] = 127;
		}

		if(joy1Btn(9) == 1)
		{
			servo[servo7] = 256;
			wait1Msec(3);
		}

		else if(joy1Btn(10) == 1)
		{
			servo[servo7] = 127;
			wait1Msec(3);
		}

		///////////////////////////////////////////////////////////////////////////
		////////////////////////////DRIVER 2//////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////

		if(joy2Btn(1) == 1) //IR Up
		{
			servo[servo3] = 256;
		}

		if(joy2Btn(2) == 1) //Ir Down
		{
			servo[servo3] = 0;
		}

		if(joy2Btn(3) == 1) //Scoop Intake Close
		{
			servo[servo8] = 0;
		}

		else if(joy2Btn(4) == 1) //Scoop Intake Open
		{
			servo[servo8] = 256;
		}
		
		else
		{
			servo[servo8] = 127;
		}

		if(joy2Btn(5) == 1)//80 20 goes up or down (precise)
		{
			motor[motorH] = 60;
			motor[motorI] = 60;
			wait1Msec(3);
			motor[motorH] = 0;
			motor[motorI] = 0;
		}

		if(joy2Btn(6) == 1) //80 20 goes up or down (precise)
		{
			motor[motorH] = -60;
			motor[motorI] = -60;
			wait1Msec(3);
			motor[motorH] = 0;
			motor[motorI] = 0;
		}

		if(joy2Btn(7) == 1) //Rolling goal gripper leaves
		{
			servo[servo1] = 0;
			servo[servo2] = 244;
			wait1Msec(200);
		}

		if(joy2Btn(8) == 1) //Rolling goal gripper grabs
		{
			servo[servo1] = 244;
			servo[servo2] = 0;
			wait1Msec(200);
		}
	}
}

//The Metal Magicians
//JLSNRM
