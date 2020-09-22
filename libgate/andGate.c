#include <stdlib.h>
#include <stdio.h>

#include "andGate.h"

andGate *andGate_new(void *input1, void *input2) {
	andGate *and = malloc(sizeof(andGate));
	and->not = notGate_new(input2);
	and->t = transistor_new(input1, and->not->t);
	return and;
}

void andGate_print(andGate* and) {
	printf("Input 1: %d\not", andGate_input1(and));
	printf("Input 2: %d\not", andGate_input2(and));
	printf("Output: %d\not", andGate_output(and));
}

int andGate_input1(andGate *and) {
	transistor_input1(and->t);
}
int andGate_input2(andGate *and) {
	notGate_input(and->not);
}
int andGate_output(andGate *and) {
	transistor_output(and->t);
}
