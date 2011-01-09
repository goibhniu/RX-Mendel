/*
 * RX-Mendel Motherboard
 * Copyright 2011  - Gobhainn-Saor Armail Inc.
 *
 *
 *
 */
/* Hardware specific includes. */
#include "iodefine.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "serial.h"

/* Priorities at which the tasks are created. */
#define 	configQUEUE_RECEIVE_TASK_PRIORITY	( tskIDLE_PRIORITY + 2 )
#define		configQUEUE_SEND_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )

/* The rate at which data is sent to the queue, specified in milliseconds. */
#define mainQUEUE_SEND_FREQUENCY_MS				( 500 / portTICK_RATE_MS )

#define mainQUEUE_LENGTH						( 1 )

/*
 * The tasks as defined at the top of this file.
 */
static void prvQueueReceiveTask( void *pvParameters );
static void prvQueueSendTask( void *pvParameters );
static void prvSerialReceiveTask( void *pvParameters);

static xQueueHandle xQueue = NULL;

int main(void)
{
	extern void HardwareSetup( void );

		/* Renesas provided CPU configuration routine.  The clocks are configured in
		here. */
		HardwareSetup();
		BoardInitialize();
		xQueue = xQueueCreate( mainQUEUE_LENGTH, sizeof( unsigned long ) );
		xQueueSerialCommand = xQueueCreate( mainQUEUE_LENGTH, sizeof( unsigned long ) );
		vSemaphoreCreateBinary( xSemSerialCommandAvailable );
		if( xQueue != NULL )
		{
			/* Start the two tasks as described at the top of this file. */
			xTaskCreate( prvQueueReceiveTask, ( signed char * ) "Rx", configMINIMAL_STACK_SIZE, NULL, configQUEUE_RECEIVE_TASK_PRIORITY, NULL );
			xTaskCreate( prvQueueSendTask, ( signed char * ) "TX", configMINIMAL_STACK_SIZE, NULL, configQUEUE_SEND_TASK_PRIORITY, NULL );
			xTaskCreate( prvSerialReceiveTask, ( signed char * ) "SerialRX", configMINIMAL_STACK_SIZE, NULL, configQUEUE_RECEIVE_TASK_PRIORITY, NULL );
			/* Start the tasks running. */
			vTaskStartScheduler();
		}

		/* If all is well we will never reach here as the scheduler will now be
		running.  If we do reach here then it is likely that there was insufficient
		heap available for the idle task to be created. */
		for( ;; );
}



static void prvQueueSendTask( void *pvParameters )
{
portTickType xNextWakeTime;
const unsigned long ulValueToSend = 100UL;

	/* Initialise xNextWakeTime - this only needs to be done once. */
	xNextWakeTime = xTaskGetTickCount();

	for( ;; )
	{
		/* Place this task in the blocked state until it is time to run again.
		The block state is specified in ticks, the constant used converts ticks
		to ms. */
		vTaskDelayUntil( &xNextWakeTime, mainQUEUE_SEND_FREQUENCY_MS );

		/* Send to the queue - causing the queue receive task to flash its LED.  0
		is used so the send does not block - it shouldn't need to as the queue
		should always be empty here. */
		xQueueSend( xQueue, &ulValueToSend, 0 );
		xQueueSend( xQueueSerialCommand , &ulValueToSend, 0 );
	}
}
/*-----------------------------------------------------------*/

static void prvQueueReceiveTask( void *pvParameters )
{
unsigned long ulReceivedValue;

	for( ;; )
	{
		/* Wait until something arives in the queue - this will block
		indefinitely provided INCLUDE_vTaskSuspend is set to 1 in
		FreeRTOSConfig.h. */
		xQueueReceive( xQueue, &ulReceivedValue, portMAX_DELAY );

		/*  To get here something must have arrived, but is it the expected
		value?  If it is, toggle the LED. */
		if( ulReceivedValue == 100UL )
		{
			vTogglePIN( 0 );
			vTogglePIN( 1 );
		}
	}
}
/*-----------------------------------------------------------*/

static void prvSerialReceiveTask( void *pvParameters )
{
unsigned long ulReceivedValue;

	for( ;; )
	{

		xQueueReceive( xQueueSerialCommand, &ulReceivedValue, portMAX_DELAY );


		if( ulReceivedValue == 100UL )
		{
			vTogglePIN( 8 );
			if(checksum("N4 G93 E0*67") == GOOD_CHECKSUM)
			{
				vTogglePIN( 9 );
			}
		}
	}
}



void vApplicationSetupTimerInterrupt( void )
{
	/* Enable compare match timer 0. */
	MSTP( CMT0 ) = 0;

	/* Interrupt on compare match. */
	CMT0.CMCR.BIT.CMIE = 1;

	/* Set the compare match value. */
	CMT0.CMCOR = ( unsigned short ) ( ( ( configPERIPHERAL_CLOCK_HZ / configTICK_RATE_HZ ) -1 ) / 8 );

	/* Divide the PCLK by 8. */
	CMT0.CMCR.BIT.CKS = 0;

	/* Enable the interrupt... */
	_IEN( _CMT0_CMI0 ) = 1;

	/* ...and set its priority to the application defined kernel priority. */
	_IPR( _CMT0_CMI0 ) = configKERNEL_INTERRUPT_PRIORITY;

	/* Start the timer. */
	CMT.CMSTR0.BIT.STR0 = 1;
}
/*-----------------------------------------------------------*/

/* This function is explained by the comments above its prototype at the top
of this file. */
void vApplicationMallocFailedHook( void )
{
	for( ;; );
}
/*-----------------------------------------------------------*/

/* This function is explained by the comments above its prototype at the top
of this file. */
void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
	for( ;; );
}
/*-----------------------------------------------------------*/

/* This function is explained by the comments above its prototype at the top
of this file. */
void vApplicationIdleHook( void )
{
}
/*-----------------------------------------------------------*/

/* The following four functions are here just to allow all three build
configurations to use the same vector table.  They are not used in this
demo, but linker errors will result if they are not defined.  They can
be ignored. */
void vT0_1_ISR_Handler( void ) {}
void vT2_3_ISR_Handler( void ) {}
void vEMAC_ISR_Handler( void ) {}
void vTimer2_ISR_Handler( void ) {}
volatile unsigned long ulHighFrequencyTickCount = 0;
