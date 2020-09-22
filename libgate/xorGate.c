#include <stdlib.h>
#include <stdio.h>
#include "xorGate.h"

xorGate *xorGate_new(void *input1, void *input2) {
	xorGate *xor = malloc(sizeof(xorGate));

	xor->not1 = notGate_new(input1);
	xor->not2 = notGate_new(input2);
	xor->and1 = andGate_new(input1, xor->not2->t);
	xor->and2 = andGate_new(input2, xor->not1->t);
	xor->or = orGate_new(xor->and1->t, xor->and2->t);

	return xor;
}

void xorGate_print(xorGate *xor) {
	printf("Input1: %d\n", xorGate_input1(xor));
	printf("Input2: %d\n", xorGate_input2(xor));
	printf("Output: %d\n", xorGate_output(xor));
}

int xorGate_input1(xorGate *xor) {
	andGate_input1(xor->and1);
}
int xorGate_input2(xorGate *xor) {
	andGate_input1(xor->and2);
}
int xorGate_output(xorGate *xor) {
	orGate_output(xor->or);
}
