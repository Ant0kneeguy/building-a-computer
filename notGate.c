#include <stdlib.h>
#include <stdio.h>

#include "notGate.h"

notGate *notGate_new(transistor *input) {
		notGate *n = malloc(sizeof(notGate));
		if (n==NULL) {
			printf("ERROR: malloc failed!");
			exit(-1);
		}
		n->t = transistor_new(vcc, input);
		return n;
}

int notGate_input(notGate *n) {
	return transistor_input2(n->t);
}
int notGate_output(notGate *n) {
	return transistor_output(n->t);
}

void notGate_print(notGate* n) {
	printf("Input: %d\n", notGate_input(n));
	printf("Output: %d\n", notGate_output(n));
}
