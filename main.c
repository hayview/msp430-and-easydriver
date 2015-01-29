#include <msp430.h>
#include "easydriver.h"
#include "delay.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	BCSCTL2 = SELM_0 | DIVM_0 | DIVS_0;

	if (CALBC1_16MHZ != 0xFF) {
	    /* Adjust this accordingly to your VCC rise time */
	    __delay_cycles(100000);

	    /* Follow recommended flow. First, clear all DCOx and MODx bits. Then
	     * apply new RSELx values. Finally, apply new DCOx and MODx bit values.
	     */
	    DCOCTL = 0x00;
	    BCSCTL1 = CALBC1_16MHZ;     /* Set DCO to 16MHz */
	    DCOCTL = CALDCO_16MHZ;
	}

	motorsInit();

	while(1){
		motorsRunCycles(+2);
		delayMiliSecond(2000);

		motorsRunCycles(-2);
		delayMiliSecond(2000);

		motorsGotoPosition(90);
		delayMiliSecond(1000);
		motorsGotoPosition(90);
		delayMiliSecond(1000);
		motorsGotoPosition(90);
		delayMiliSecond(1000);
		motorsGotoPosition(90);
		delayMiliSecond(1000);

		motorsGotoPosition(-90);
		delayMiliSecond(1000);
		motorsGotoPosition(-90);
		delayMiliSecond(1000);
		motorsGotoPosition(-90);
		delayMiliSecond(1000);
		motorsGotoPosition(-90);
		delayMiliSecond(1000);

	}
}
