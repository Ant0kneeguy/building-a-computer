#include <stdlib.h>
#include <stdio.h>
#include "nandGate.h"


nandGate *nandGate_new(transistor *input1, transistor *input2) {
	nandGate *na = malloc(sizeof(nandGate));

	na->a = andGate_new(input1, input2);
	na->n = notGate_new(na->a->t);

	return na;
}

void nandGate_print(nandGate *na) {
	printf("Input 1: %d\n", nandGate_input1(na));
	printf("Input 2: %d\n", nandGate_input2(na));
	printf("Output: %d\n", nandGate_output(na));
}

int nandGate_input1(nandGate *na) {
	return andGate_input1(na->a);
}
int nandGate_input2(nandGate *na) {
	return andGate_input2(na->a);
}
int nandGate_output(nandGate *na) {
	return notGate_output(na->n);
}
