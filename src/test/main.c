/* Copyright (c) 2010, Bjoern Heller <tec@hellercom.de>. All rights reserved
* This code is licensed under GNU/ GPL
*/

#include <msp430.h>
#include <legacymsp430.h>
#include "pindef.h"

void BUZZERbeep1(void)
{
    /* Set BUZZER pins as outputs */
    BUZZER_DIR |= BUZZER;

    /* Turn on BUZZER */
    BUZZER_OUT |= BUZZER;

    /* Toggle BUZZER */
int c = 0;
do
{
c ++;
__delay_cycles(300);
    BUZZER_OUT ^= (BUZZER);
}
while (c < 1000);

}

int main(void)
{

 /*
     * Halt the watchdog timer. According to the datasheet the watchdog
     * timer starts automatically after powerup. It must be configured
     * or halted at the beginning of code execution to avoid a system
     * reset. Furthermore, the watchdog timer register (WDTCTL) is
     * password protected, and requires the upper byte during write
     * operations to be 0x5A, which is the value associated with WDTPW.
     */
    WDTCTL = WDTPW + WDTHOLD;

/* Set ACLK to use internal VLO (12 kHz clock) */
    BCSCTL3 |= LFXT1S_2;

/* Set TimerA to use auxiliary clock in UP mode */
    TACTL = TASSEL_1 | MC_1;

    /* Enable the interrupt for TACCR0 match */
    TACCTL0 = CCIE;

    /* Set TACCR0 which also starts the timer. At 12 kHz, counting to
     * 12000 should output an LED change every 1 second. Try this out
     * and see how inaccurate the VLO can be */
    TACCR0 = 11999;

    /* Enable global interrupts */
    eint();

BUZZERbeep1();

    while(1) {
        /* Loop forever, interrupts take care of the rest */

}
}
