/*
 *   RX-Mendel Reprap printer controller - Serial Interface Handler
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


/* Includes */

#include "serial.h"
#include "gcode.h"

/*
 * checksum
 * returns GOOD_CHECKSUM on successful matching of submitted line
 * to checksum value
 *
 * this code was derived from the code available at:
 * 		http://reprap.org/wiki/GCodes#N_and_.2A
 *
 */


int checksum (char *buffer)
{
	int cs = 0;
	int i,j;
	unsigned char tmp[8];
	for(i = 0; buffer[i] != CHECKSUM && buffer[i] != NULL; i++)
		cs = cs ^ cmd[i];
	cs &= 0xff;
    if(buffer[i] == CHECKSUM)
    {
    	for(j = 0; buffer[i+j+1] != NULL; j++)
    		   tmp[j] = buffer[i+j+1];
    	if( cs == atoi(tmp))
    	{
    		return GOOD_CHECKSUM;
    	}
    }
    return BAD_CHECKSUM;

}
