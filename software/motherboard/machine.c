/*
 *   RX-Mendel Reprap printer controller - Machine initialization routines
 *    Copyright (C) 2011  Larry W Housner <gobhain@gsarmail.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *
 */
#include "FreeRTOS.h"
#include "task.h"

#include "machine.h"
#include "main.h"
#include "iodefine.h"

int load_machine(Machine *BigIron)
{
	return 0;
}

int load_extruder(Extruder *Spinnerette, int number)
{
	return 0;
}


int home_axis(int axis)
{
	return 0;
}


int intialize_extruder(int number)
{
	return 0;
}

int BoardInitialize()
{

	/* TODO -- Add initalization routines beyond the ones supplied by the Renesas routines */
	LED4 = LED_ON;
	LED5 = LED_ON;
	LED6 = LED_ON;
	LED7 = LED_ON;
	LED8 = LED_ON;
	LED9 = LED_ON;
	LED10 = LED_ON;
	LED11 = LED_ON;
	LED12 = LED_ON;
	LED13 = LED_ON;
	LED14 = LED_ON;
	LED15 = LED_ON;
}
#define partestNUM_LEDS ( 12 )

long lGetPINState( unsigned long ulLED );

/*-----------------------------------------------------------*/

void vParTestInitialise( void )
{
	/* Port pin configuration is done by the low level set up prior to this
	function being called. */
}
/*-----------------------------------------------------------*/

void vSetPIN( unsigned long ulPIN, signed long xValue )
{
	if( ulPIN < partestNUM_LEDS )
	{
		if( xValue != 0 )
		{
			/* Turn the LED on. */
			taskENTER_CRITICAL();
			{
				switch( ulPIN )
				{
					case 0:	LED4 = LED_ON;
							break;
					case 1:	LED5 = LED_ON;
							break;
					case 2:	LED6 = LED_ON;
							break;
					case 3:	LED7 = LED_ON;
							break;
					case 4:	LED8 = LED_ON;
							break;
					case 5:	LED9 = LED_ON;
							break;
					case 6:	LED10 = LED_ON;
							break;
					case 7:	LED11 = LED_ON;
							break;
					case 8:	LED12 = LED_ON;
							break;
					case 9:	LED13 = LED_ON;
							break;
					case 10:LED14 = LED_ON;
							break;
					case 11:LED15 = LED_ON;
							break;
				}
			}
			taskEXIT_CRITICAL();
		}
		else
		{
			/* Turn the LED off. */
			taskENTER_CRITICAL();
			{
				switch( ulPIN )
				{
					case 0:	LED4 = LED_OFF;
							break;
					case 1:	LED5 = LED_OFF;
							break;
					case 2:	LED6 = LED_OFF;
							break;
					case 3:	LED7 = LED_OFF;
							break;
					case 4:	LED8 = LED_OFF;
							break;
					case 5:	LED9 = LED_OFF;
							break;
					case 6:	LED10 = LED_OFF;
							break;
					case 7:	LED11 = LED_OFF;
							break;
					case 8:	LED12 = LED_OFF;
							break;
					case 9:	LED13 = LED_OFF;
							break;
					case 10:LED14 = LED_OFF;
							break;
					case 11:LED15 = LED_OFF;
							break;
				}

			}
			taskEXIT_CRITICAL();
		}
	}
}


void vTogglePIN( unsigned long ulPIN )
{
	if( ulPIN < partestNUM_LEDS )
	{
		taskENTER_CRITICAL();
		{
			if( lGetPINState( ulPIN ) != 0x00 )
			{
				vSetPIN( ulPIN, 0 );
			}
			else
			{
				vSetPIN( ulPIN, 1 );
			}
		}
		taskEXIT_CRITICAL();
	}
}
/*-----------------------------------------------------------*/

long lGetPINState( unsigned long ulPIN )
{
long lReturn = pdFALSE;

	if( ulPIN < partestNUM_LEDS )
	{
		switch( ulPIN )
		{
			case 0	:	if( LED4 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 1	:	if( LED5 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 2	:	if( LED6 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 3	:	if( LED7 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 4	:	if( LED8 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 5	:	if( LED9 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 6	:	if( LED10 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 7	:	if( LED11 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 8	:	if( LED12 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 9	:	if( LED13 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 10	:	if( LED14 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
			case 11	:	if( LED15 != 0 )
						{
							lReturn =  pdTRUE;
						}
						break;
		}
	}

	return lReturn;
}
