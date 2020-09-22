#include <stdlib.h>
#include <stdio.h>

#include "notGate.h"
#include "../libconst/libconst.h"

notGate *notGate_new(void *input) {
		notGate *not = malloc(sizeof(notGate));
		if (not==NULL) {
			printf("ERROR: malloc failed!");
			exit(-1);
		}
		not->t = transistor_new(vcc, input);
		return not;
}

int notGate_input(notGate *not) {
	return transistor_input2(not->t);
}
int notGate_output(notGate *not) {
	return transistor_output(not->t);
}

void notGate_print(notGate* not) {
	printf("Input: %d\not", notGate_input(not));
	printf("Output: %d\not", notGate_output(not));
}
