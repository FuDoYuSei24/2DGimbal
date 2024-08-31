#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include "PWM.h"
#include "Servo.h"
#include <math.h>
#include "Kalman.h"

int16_t AX,AY,AZ,GX,GY,GZ;
static float ax, ay, az, gx, gy, gz, yaw, roll, pitch;
uint8_t ID;
float pAccelOut[3]; 
float pEularAngleOut[3];
float pGyroOut[3];

int main()
{
	
	Servo_Init();
	OLED_Init();
	MPU6050_Init();
	
	while(1)
	{
    MPU6050_Proc();
		App_MPU6050_GetResult(pAccelOut, pGyroOut, pEularAngleOut);
		OLED_ShowSignedNum(1,1,pitch,4);
    OLED_ShowSignedNum(2,1,roll,4);
		Servo_SetAngle1(pEularAngleOut[0]);
		Servo_SetAngle2(pEularAngleOut[1]);
		
	}
}
