#include "stacktrace.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sizeOfStacktrace = 0;
char* stacktrace[50];

//As every function begins, this should get called so that the function is added
//to the stacktrace
void stacktrace_add() {

	char error[100];
	char* filename = getFilename(__FILE__);
	sprintf(error, "Error in function %s at %s:%d", __FUNCTION__, filename, __LINE__);

	stacktrace[sizeOfStacktrace] = error;
	sizeOfStacktrace += 1;

	printf("Error stored in stacktrace: %s\n", stacktrace[sizeOfStacktrace]);

	stacktrace_print();
}

//As every function returns, this should be called in order to remove that
//function from the stacktrace
void stacktrace_remove() {
	stacktrace[sizeOfStacktrace] = NULL;
	sizeOfStacktrace -= 1;
}

//When a function returns an error, this should be called in order to
//print the stacktrace
void stacktrace_print() {
	printf("Contents of stacktrace:");
	for (int i=0; i<sizeOfStacktrace; i++) {
		printf("%s\n", stacktrace[i]);
	}
}

//Used in stacktrace_add to trim the filepath
char* getFilename(char* fullFilepath) {
	char* position_pointer = strrchr(fullFilepath, '/');
	if (position_pointer == NULL) {
		return NULL;
	} else {
		return position_pointer + 1;
	}
}
