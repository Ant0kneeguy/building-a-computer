#include "stacktrace.h"
#include <stdio.h>

int sizeOfStacktrace = 0;
char* stacktrace[50];

//As every function gets called, it adds itself to the stacktrace
void stacktrace_add() {
	char* error;
	sprintf(error, "Error in function %s at %s:%d",
		__FUNCTION__, __FILE__, __LINE__);
	stacktrace[sizeOfStacktrace] = error;
	sizeOfStacktrace += 1;
}

//As every function returns, it removes itself from the stacktrace
void stacktrace_remove() {
	stacktrace[sizeOfStacktrace] = NULL;
	sizeOfStacktrace -= 1;
}

//When a function returns an error, it prints the stacktrace
void stacktrace_print() {
	for (int i=0; i<sizeOfStacktrace; i++) {
		char* error = stacktrace[i];
		printf("%s\n", error);
	}
}
