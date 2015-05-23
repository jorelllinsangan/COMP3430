#include "getexeccounts.h"

int getExecCounts(int pid, int* pArray){
	int i;

	for(i = 0; i < 4; i++){
		pArray[i] = i;
	}

	return 0;
}