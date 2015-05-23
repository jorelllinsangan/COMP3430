#include <stdio.h>
#include <stdlib.h>

#include "getexeccounts.h"


int main(int argc, char* argv[]){
	int pArray[4];
	int pid;

	if(argc == 2){
		pid = atoi(argv[1]);

		getExecCounts(pid, pArray);
	
		printf("pid %s:\n", argv[1]);

		printf("\t%d\t%s\n", pArray[0], "fork");
		printf("\t%d\t%s\n", pArray[1], "vfork");
		printf("\t%d\t%s\n", pArray[2], "execve");
		printf("\t%d\t%s\n", pArray[3], "clone");

	}else{
		printf("Invalid number of arguments\n");

	}
	
	return 0;
}