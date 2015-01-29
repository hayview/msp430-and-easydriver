#ifndef DELAY_H
#define DELAY_H

//define the cpu clock speed
#define CPU_CLOCK_KHZ	16000/*changing this value according to dco clock frequency*/
#define MICRO_SECOND	CPU_CLOCK_KHZ/1000
#define MILI_SECOND		CPU_CLOCK_KHZ

void delayMicroSecond (unsigned int time);
void delayMiliSecond  (unsigned int time);

#endif
