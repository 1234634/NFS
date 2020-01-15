#include<stdio.h>
#include<stdlib.h>

int main(int argC, char*argV[])
{
	
	
	int counter = 0,pwmCounter = 0;
	int pwmR,pwmL,pwmValue,offset = 4,speed =1,right=2,left=1,halfPwm = 0,sign_offset = 0;
	
	if(argC < 2)
		speed = 0;
	else
		speed = atoi(argV[1]);

	while(counter != 20){
	

		if ( speed >= 0)
		{
			pwmValue = speed + offset * (speed != 0);
			
		}
		else
		{
			pwmValue =  speed - offset;
			
		}		

		sign_offset = (speed < 0)*10;

			
		pwmL = sign_offset + pwmValue/left  >= pwmCounter;
		pwmR = sign_offset + pwmValue/right >= pwmCounter;

	//	gpioOutput( PWM_RIGHT, pwmR);
	//	gpioOutput( PWM_LEFT, pwmL);
		printf("pwmCounter = %d pwmL = %d, pwmR =%d \n",pwmCounter,pwmL,pwmR);
		++pwmCounter;
        	pwmCounter %= 10;
		counter++;
	}
	return 0;
}
