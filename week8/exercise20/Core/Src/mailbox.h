/*
 * mailbox.h
 *
 *  Created on: Mar 26, 2021
 *      Author: hoang
 */

#ifndef SRC_MAILBOX_H_
#define SRC_MAILBOX_H_

#define SYNC_1 11
#define SYNC_2 22

void InitMailbox();
void Post(int);
int Pend();



#endif /* SRC_MAILBOX_H_ */
