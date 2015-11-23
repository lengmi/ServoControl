// ----------------------------------------------------------------------------
// main.c  (for lab_03a_gpio project) ('F5529 Launchpad)
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
#include <driverlib.h>                                                          // DriverLib include file


//***** Prototypes ************************************************************


//***** Defines ***************************************************************
#define ONE_SECOND  10
#define HALF_SECOND 10 / 2

//***** Global Variables ******************************************************


//*****************************************************************************
// Main
//*****************************************************************************
void main (void)
{
    // Stop watchdog timer
    WDT_A_hold( WDT_A_BASE );

    unsigned int counter = 0;

    // Set pin P1.0 to output direction and turn LED off
    GPIO_setAsOutputPin( GPIO_PORT_P2, GPIO_PIN0+GPIO_PIN4 );                             // Red LED (LED1)
    GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN0+GPIO_PIN4 );

    while(1) {
        // Turn on LED
    	if(counter == 1500 )
    		counter = 0;
    	if(counter < 750)
    	{
			GPIO_setOutputHighOnPin( GPIO_PORT_P2, GPIO_PIN0 );

			// Wait about a second
			__delay_cycles( HALF_SECOND );

			GPIO_setOutputHighOnPin( GPIO_PORT_P2, GPIO_PIN4 );

			__delay_cycles( HALF_SECOND );

			// Turn off LED
			GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN0 );

			__delay_cycles( HALF_SECOND );

			GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN4 );

			// Wait another second
			__delay_cycles( HALF_SECOND );

			counter ++;
    	}
    	else
    	{
    		GPIO_setOutputHighOnPin( GPIO_PORT_P2, GPIO_PIN4 );

    					// Wait about a second
    		__delay_cycles( HALF_SECOND );

    	    GPIO_setOutputHighOnPin( GPIO_PORT_P2, GPIO_PIN0 );

    		__delay_cycles( HALF_SECOND );

    					// Turn off LED
    		GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN4 );

    		__delay_cycles( HALF_SECOND );

    		GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN0 );

    					// Wait another second
    		__delay_cycles( HALF_SECOND );

    		counter ++;
    	}
    }
}
