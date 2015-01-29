#include "delay.h"

void delayMicroSecond (unsigned int time)
{
	while (time--)
	{
		_delay_cycles(MICRO_SECOND);
	}
}

void delayMiliSecond  (unsigned int time)
{
	while (time--)
	{
		_delay_cycles(MILI_SECOND);
	}
}
