/*
 * CriticalCode.c
 *
 *  Created on: Mar 26, 2021
 *      Author: hoang
 */

#include "FreeRTOS.h"
#include "semphr.h"

typedef struct{
	int GreenRate;
	int RedRate;
} SharedPool;

SharedPool DataPool = {10, 1};

SemaphoreHandle_t PoolSemaphore;

void InitSem(void){
	PoolSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(PoolSemaphore);
}

void SetGreenRate(int rate){
	xSemaphoreTake(PoolSemaphore, portMAX_DELAY);
	DataPool.GreenRate = rate;
	xSemaphoreGive(PoolSemaphore);
}

int GetGreenRate(){
	return DataPool.GreenRate;
}

void SetRedRate(int rate){
	xSemaphoreTake(PoolSemaphore, portMAX_DELAY);
	DataPool.RedRate = rate;
	xSemaphoreGive(PoolSemaphore);
}

int GetRedRate(){
	return DataPool.RedRate;
}


