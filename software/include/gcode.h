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


#ifndef _GCODE_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _GCODE_H_

#define LINENUMBER	'N'
#define GCODE		'G'
#define MCODE		'M'
#define TOOLNUMBER	'T'
#define SPEED		'S'
#define PARAMETER	'P'
#define X_AXIS	    'X'
#define Y_AXIS		'Y'
#define Z_AXIS		'Z'
#define A_AXIS		'A'
#define B_AXIS		'B'
#define C_AXIS		'C'
#define I_FOCUS		'I'
#define J_FOCUS		'J'
#define K_FOCUS		'K'
#define R_RADIUS	'R'
#define Q_RADIUS	'Q'
#define CHECKSUM	'*'

#ifdef __cplusplus
 }
#endif
#endif /* _GCODE_H_ */
