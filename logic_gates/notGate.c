#include <stdlib.h>
#include <stdio.h>

#include "notGate.h"
#include "../constants/libconst.h"
#include "../debugging/stacktrace.h"

notGate *notGate_new(void *input) {
	stacktrace_add();

	notGate *not = malloc(sizeof(notGate));
	if (not==NULL) {
		printf("ERROR: malloc failed!");
		exit(-1);
	}
	not->t = transistor_new(vcc, input);

	stacktrace_remove();
	return not;
}

int notGate_input(notGate *not) {
	return transistor_input2(not->t);
}
int notGate_output(notGate *not) {
	return transistor_output(not->t);
}

void notGate_print(notGate* not) {
	printf("Input: %d\n", notGate_input(not));
	printf("Output: %d\n", notGate_output(not));
}
