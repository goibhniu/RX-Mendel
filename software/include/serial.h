/*
 *   RX-Mendel Reprap printer controller - G Code Interpreter
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


#ifndef _SERIAL_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SERIAL_H_

#define GOOD_CHECKSUM (1)
#define BAD_CHECKSUM (0)

#include "FreeRTOS.h"
#include "semphr.h"

int checksum(char *);
extern xSemaphoreHandle xSemSerialCommandAvailable;
static xQueueHandle xQueueSerialCommand = NULL;

static void prvSerialReceiveTask( void *pvParameters);

#ifdef __cplusplus
 }
#endif
#endif /* _SERIAL_H_ */
