/*
 * SemaSync.c
 *
 *  Created on: Apr 2, 2021
 *      Author: hoang
 */


#include "FreeRTOS.h"
#include "semphr.h"

SemaphoreHandle_t EFSema;

void InitEFSema(void){
	EFSema = xSemaphoreCreateBinary();
}

void SetEFSema(){
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	xSemaphoreGiveFromISR(EFSema, &xHigherPriorityTaskWoken);

	return;
}

void WaitEFSema(){
	xSemaphoreTake(EFSema, portMAX_DELAY);
	return;
}

