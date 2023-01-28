/*
 * CriticalCode.h
 *
 *  Created on: Mar 26, 2021
 *      Author: hoang
 */

#ifndef SRC_CRITICALCODE_H_
#define SRC_CRITICALCODE_H_


void InitSem(void);
void SetGreenRate(int);
int GetGreenRate();
void SetRedRate(int);
int GetRedRate();


#endif /* SRC_CRITICALCODE_H_ */
