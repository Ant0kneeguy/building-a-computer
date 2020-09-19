#include <stdlib.h>
#include <stdio.h>
#include "orGate.h"

orGate *orGate_new(transistor *input1, transistor *input2) {
	orGate *o = malloc(sizeof(orGate));

	o->no = norGate_new(input1, input2);
	o->n = notGate_new(o->no->a->t);

	return o;
}

void orGate_print(orGate *o) {
	printf("Input1: %d\n", orGate_input1(o));
	printf("Input2: %d\n", orGate_input2(o));
	printf("Output: %d\n", orGate_output(o));
}

int orGate_input1(orGate *o) {
	return norGate_input1(o->no);
}
int orGate_input2(orGate *o) {
	return norGate_input2(o->no);
}
int orGate_output(orGate *o) {
	return  notGate_output(o->n);
}
