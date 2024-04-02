/*
 * PKB4010.h
 *
 *  Created on: Apr 1, 2024
 *      Author: Kacper Lauk
 */


/*
 * This library is created to support the PKB4010-3600-G5-30T rotary, incremental encoder.
 * It allows of getting current rotation, and setting the start point in any position.
 * Supports up to 6 encoders.
 * Precision up to 0.05 degree.
*/


/* To initialize the encoder you have to:
 * choose the timer for Encoder
 * set the position "Combined Channels" to Encoder Mode
 * set the Counter Period as 7200
 * enable NVIC interrupt for timer
 * select pin for Z canal and set it in GPIO_EXTIx mode
 * enable NVIC interrupt for Z pin
 * call the Encoder_Init with proper parameters and one of 6 available encoders tags: E1, E2, E3, E4, E5 or E6
 * to call any function, use the tag of the selected encoder
*/


#ifndef INC_PKB4010_H_
#define INC_PKB4010_H_

#include "main.h"

extern struct Encoder E1;	//tag E1
extern struct Encoder E2;	//tag E2
extern struct Encoder E3;	//tag E3
extern struct Encoder E4;	//tag E4
extern struct Encoder E5;	//tag E5
extern struct Encoder E6;	//tag E6

typedef struct Encoder{
	TIM_HandleTypeDef *HTIM;
	uint16_t Z_PIN;
	int16_t revs;
	uint8_t flag;
} Encoder;


// initializes encoder by starting timer and takes address of canal Z pin
void Encoder_Init(TIM_HandleTypeDef *htim, uint16_t z_pin, Encoder *tag);
/*
 * htim is a pointer to selected timer struct
 * z_pin is a GPIO address of selected pin of canal Z
 * *tag is a pointer to selected encoder tag
*/


// returns actual counter of a timer
int16_t Encoder_Get_Counter(Encoder tag);
// tag is a tag of selected encoder


// returns actual number of rotation
int16_t Encoder_Get_Revs(Encoder tag);
// tag is a tag of selected encoder


// return overall angle (in degrees) of encoder rotation
int32_t Encoder_Get_Angle(Encoder tag);
// tag is a tag of selected encoder


//returns overall fully precision rotation
//value 7200 means one full rotation
int32_t Encoder_Get_Precission_Value(Encoder tag);
// tag is a tag of selected encoder


// resets values of timer counter and number of rotations,
// it can set a start point of measurement in any position
void Encoder_Reset(Encoder *tag);
// *tag is a pointer to selected encoder tag


#endif
