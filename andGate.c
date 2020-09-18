#include <stdlib.h>
#include <stdio.h>

#include "andGate.h"

andGate *andGate_new(transistor *input1, transistor *input2) {
	andGate *a = malloc(sizeof(andGate));
	a->n = notGate_new(input2);
	a->t = transistor_new(input1, a->n->t);
	return a;
}

void andGate_print(andGate* a) {
	printf("Input 1: %d\n", andGate_input1(a));
	printf("Input 2: %d\n", andGate_input2(a));
	printf("Output: %d\n", andGate_output(a));
}

int andGate_input1(andGate *a) {
	transistor_input1(a->t);
}
int andGate_input2(andGate *a) {
	notGate_input(a->n);
}
int andGate_output(andGate *a) {
	transistor_output(a->t);
}
