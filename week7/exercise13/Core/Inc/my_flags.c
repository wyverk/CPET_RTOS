/*
 * my_flags.c
 *
 *  Created on: Mar 12, 2021
 *      Author: hoang
 */

#include "my_flags.h"

Flag SFlag1 = Reset;
Flag SFlag2 = Reset;

void Set_Flag(int num){
	switch(num){
	case 1: SFlag1 = Set;
	break;

	case 2: SFlag2 = Set;
	break;
	}
}


void Reset_Flag(int num){
	switch(num){
	case 1: SFlag1 = Reset;
	break;

	case 2: SFlag2 = Reset;
	break;
	}
}

Flag Check_Flag(int num){
	Flag temp;

	switch(num){
	case 1: temp = SFlag1;
	break;

	case 2: temp = SFlag2;
	break;
	}

	return temp;
}
