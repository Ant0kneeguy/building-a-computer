#include <stdlib.h>
#include <stdio.h>
#include "orGate.h"

orGate *orGate_new(transistor *input1, transistor *input2) {
	orGate *or = malloc(sizeof(orGate));

	or->nor = norGate_new(input1, input2);
	or->not = notGate_new(or->nor->and->t);

	return or;
}

void orGate_print(orGate *or) {
	printf("Input1: %d\n", orGate_input1(or));
	printf("Input2: %d\n", orGate_input2(or));
	printf("Output: %d\n", orGate_output(or));
}

int orGate_input1(orGate *or) {
	return norGate_input1(or->nor);
}
int orGate_input2(orGate *or) {
	return norGate_input2(or->nor);
}
int orGate_output(orGate *or) {
	return  notGate_output(or->not);
}
