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


#ifndef _MACHINE_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _MACHINE_H_

/*
 * Public definitions
 */

#define REPRAP_DARWIN			0
#define REPRAP_MENDEL			1
#define MAKERBOT				2
#define MULTI_AXIS_CNC_STEPPER 	3
#define MULTI_AXIS_CNC_SERVO	4

/*
 * Public types
 */
typedef struct{
	int 			tool_heads;
	unsigned int 	machine_type;
	long int 		bed_steps_x;
	long int 		bed_steps_y;
	long int 		bed_steps_z;
	long int 		bed_steps_a;
	long int 		bed_steps_b;
	long int 		bed_steps_c;
	unsigned char 	extruders;
    double 			steps_per_mm_x;
    double			steps_per_mm_y;
    double			steps_per_mm_z;
    double			steps_per_degree_a;
    double			steps_per_degree_b;
    double			steps_per_degree_c;
    unsigned char	tool_changer_type;
} Machine;

typedef struct {
	unsigned char 	extruder_num;
	unsigned char 	thermistor_table;
	double 			max_temp;
	double			current_temp;
	double			steps_per_mm;
	unsigned char	material_sensor_type;
	double			material_remaining;
} Extruder;

int load_machine(Machine *);
int load_extruder(Extruder *, int);
int home_axis(int);
int intialize_extruder(int);
int BoardInitialize();

#ifdef __cplusplus
 }
#endif
#endif /* _MACHINE_H_ */
