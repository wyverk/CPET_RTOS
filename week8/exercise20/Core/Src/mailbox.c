/*
 * mailbox.c
 *
 *  Created on: Mar 26, 2021
 *      Author: hoang
 */

#include "FreeRTOS.h"
#include "semphr.h"
#include "cmsis_os.h"
#include "mailbox.h"

osMessageQId MessageQHandle;

SemaphoreHandle_t MailboxMutex;
SemaphoreHandle_t SemaSync1;
SemaphoreHandle_t SemaSync2;

void InitMailbox(){
	osMessageQDef(MessageQue, 1, uint16_t);
	MessageQHandle = osMessageCreate(osMessageQ(MessageQue), NULL);

	MailboxMutex = xSemaphoreCreateMutex();
	xSemaphoreGive(MailboxMutex);
	SemaSync1 = xSemaphoreCreateBinary();
	xSemaphoreGive(SemaSync1);
	SemaSync2 = xSemaphoreCreateBinary();
	xSemaphoreGive(SemaSync2);
}

void Post(int syncMessage){
	xSemaphoreTake(MailboxMutex, portMAX_DELAY);
	osMessagePut(MessageQHandle, syncMessage, 0);
	xSemaphoreGive(MailboxMutex);

	xSemaphoreGive(SemaSync2);

	xSemaphoreTake(SemaSync1, portMAX_DELAY);
}

int Pend(){
	osEvent QMessage;

	xSemaphoreGive(SemaSync1);

	xSemaphoreTake(SemaSync2, portMAX_DELAY);

	while(QMessage.status != osEventMessage){
		xSemaphoreTake(MailboxMutex, portMAX_DELAY);
		QMessage = osMessageGet(MessageQHandle, 0);
		xSemaphoreGive(MailboxMutex);
	}

	return QMessage.value.v;
}






