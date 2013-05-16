#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  ,               sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_6,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_7,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_8,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           clawLeft,      tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port2,           leftLifter,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           backRight,     tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port5,            ,             tmotorVex393, openLoop)
#pragma config(Motor,  port7,           rightLifter,   tmotorVex393, openLoop, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port8,           frontRight,    tmotorVex393, openLoop)
#pragma config(Motor,  port9,           frontLeft,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          clawRight,     tmotorVex269, openLoop, encoder, encoderPort, I2C_4, 1000)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int x1=0;
int x2=0;
int x3=0;
int x4=0;

int leftDrive=0;
int rightDrive=0;

task Drive();
task lift();
task claw();
//main program for
task main()
{
	nMotorEncoder[backRight]=0;
	nMotorEncoder[backLeft]=0;
	nMotorEncoder[rightLifter]=0;
	nMotorEncoder[clawRight]=0;

	StartTask(Drive);
//	StartTask(lift);
//	StartTask(claw);

	while(true)
		{
			Sleep(100);
	  }

}

task Drive()
{

  while(true)
  {
		int Ch1Value = vexRT[Ch1];
		int Ch2Value = vexRT[Ch2];

    leftDrive  = (Ch2Value + Ch1Value)/2;  // (y + x)/2
    rightDrive = (Ch2Value - Ch1Value)/2;  // (y - x)/2

    motor[backLeft] = leftDrive;
    motor[frontLeft] = leftDrive;

    motor[backRight] = rightDrive;
    motor[frontRight] = rightDrive;

  	x1=SensorValue[I2C_1];  //backLeft
  	x2=SensorValue[I2C_2];  //backRight
  	x3=SensorValue[I2C_3];  //rightLifter
  	x4=SensorValue[I2C_4];  //clawRight
  }
}
int liftSpeed = 0;

task lift()
{
	while (true)
		{
			int liftSpeed = SensorValue[Ch3]/2;

    	motor[rightLifter] = liftSpeed;
    	motor[leftLifter] = liftSpeed;
    }

}

int clawSpeed=0;

task claw()
{
	while(true)
	{
		 clawSpeed = SensorValue[Ch4]/2;

     motor[clawLeft]=clawSpeed;
     motor[clawRight]=clawSpeed;
  }

}


void prepareToScoop()
{

}

void Scoop()
{

}

void liftLow()
{

}

void liftHigh()
{

}
