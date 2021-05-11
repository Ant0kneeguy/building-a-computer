#include <stdlib.h>
#include <stdio.h>

#include "andGate.h"
#include "../constants/libconst.h"
#include "../debugging/stacktrace.h"

andGate *andGate_new(void *input1, void *input2) {
	stacktrace_add();

	andGate *and = malloc(sizeof(andGate));
	if (and==NULL) {
		printf("ERROR: malloc failed!");
		exit(-1);
	}
	and->not = notGate_new(input2);
	and->t = transistor_new(input1, and->not->t);
	
	stacktrace_remove();
	return and;
}

void andGate_print(andGate* and) {
	printf("Input 1: %d\n", andGate_input1(and));
	printf("Input 2: %d\n", andGate_input2(and));
	printf("Output: %d\n", andGate_output(and));
}

int andGate_input1(andGate *and) {
	return transistor_input1(and->t);
}
int andGate_input2(andGate *and) {
	return notGate_input(and->not);
}
int andGate_output(andGate *and) {
	return transistor_output(and->t);
}
