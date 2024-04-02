/*
 * PKB4010.c
 *
 *  Created on: Apr 1, 2024
 *      Author: Kacper Lauk
 */
#include "PKB4010.h"

#define TO_DEGREES 20
#define FULL_DEGREES 360
#define FULL_VALUE 7200

struct Encoder E1;	//tag E1
struct Encoder E2;	//tag E2
struct Encoder E3;	//tag E3
struct Encoder E4;	//tag E4
struct Encoder E5;	//tag E5
struct Encoder E6;	//tag E6

void Encoder_Init(TIM_HandleTypeDef *htim, uint16_t z_pin, Encoder *tag) {
	HAL_TIM_Base_Start_IT(htim);
	HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
	tag -> HTIM = htim;
	tag -> Z_PIN = z_pin;
	tag -> flag = 1;
}

int16_t Encoder_Get_Counter(Encoder tag) {
	return tag.HTIM -> Instance -> CNT;
}

int16_t Encoder_Get_Revs(Encoder tag) {
	return tag.revs;
}

int32_t Encoder_Get_Angle(Encoder tag) {
	return  tag.HTIM -> Instance -> CNT/TO_DEGREES + tag.revs*FULL_DEGREES;
}

int32_t Encoder_Get_Precission_Value(Encoder tag) {
	return tag.HTIM -> Instance -> CNT + tag.revs*FULL_VALUE;
}

void Encoder_Reset(Encoder *tag) {
	tag -> HTIM -> Instance -> CNT = 0;
	tag -> revs = 0;
	tag -> flag = 1;
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
  if (GPIO_Pin == E1.Z_PIN) {
	  if(E1.flag == 0) E1.flag = 1;
	  else E1.flag = 0;
  }
  if (GPIO_Pin == E2.Z_PIN) {
	  if(E2.flag == 0) E2.flag = 1;
	  else E2.flag = 0;
  }
  if (GPIO_Pin == E3.Z_PIN) {
	  if(E3.flag == 0) E3.flag = 1;
	  else E3.flag = 0;
  }
  if (GPIO_Pin == E4.Z_PIN) {
	  if(E4.flag == 0) E4.flag = 1;
	  else E4.flag = 0;
  }
  if (GPIO_Pin == E5.Z_PIN) {
	  if(E5.flag == 0) E5.flag = 1;
	  else E5.flag = 0;
  }
  if (GPIO_Pin == E6.Z_PIN) {
	  if(E6.flag == 0) E6.flag = 1;
	  else E6.flag = 0;
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (htim == E1.HTIM) {
	  if((E1.HTIM -> Instance -> CNT > FULL_VALUE/2) && E1.flag == 1) {
		  E1.flag = 0;
		  E1.revs--;
	  }
	  if((E1.HTIM -> Instance -> CNT < FULL_VALUE/2) && E1.flag == 0) {
		  E1.flag = 1;
		  E1.revs++;
	  }
  }
  if (htim == E2.HTIM) {
	  if((E2.HTIM -> Instance -> CNT > FULL_VALUE/2) && E2.flag == 1) {
		  E2.flag = 0;
		  E2.revs--;
	  }
	  if((E2.HTIM -> Instance -> CNT < FULL_VALUE/2) && E2.flag == 0) {
		  E2.flag = 1;
		  E2.revs++;
	  }
  }
  if (htim == E3.HTIM) {
	  if((E3.HTIM -> Instance -> CNT > FULL_VALUE/2) && E3.flag == 1) {
		  E3.flag = 0;
		  E3.revs--;
	  }
	  if((E3.HTIM -> Instance -> CNT < FULL_VALUE/2) && E3.flag == 0) {
		  E3.flag = 1;
		  E3.revs++;
	  }
  }
  if (htim == E4.HTIM) {
	  if((E4.HTIM -> Instance -> CNT > FULL_VALUE/2) && E4.flag == 1) {
		  E4.flag = 0;
		  E4.revs--;
	  }
	  if((E4.HTIM -> Instance -> CNT < FULL_VALUE/2) && E4.flag == 0) {
		  E4.flag = 1;
		  E4.revs++;
	  }
  }
  if (htim == E5.HTIM) {
	  if((E5.HTIM -> Instance -> CNT > FULL_VALUE/2) && E5.flag == 1) {
		  E5.flag = 0;
		  E5.revs--;
	  }
	  if((E5.HTIM -> Instance -> CNT < FULL_VALUE/2) && E5.flag == 0) {
		  E5.flag = 1;
		  E5.revs++;
	  }
  }
  if (htim == E6.HTIM) {
	  if((E6.HTIM -> Instance -> CNT > FULL_VALUE/2) && E6.flag == 1) {
		  E6.flag = 0;
		  E6.revs--;
	  }
	  if((E6.HTIM -> Instance -> CNT < FULL_VALUE/2) && E6.flag == 0) {
		  E6.flag = 1;
		  E6.revs++;
	  }
  }
}


