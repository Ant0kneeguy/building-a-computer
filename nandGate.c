#include <stdlib.h>
#include <stdio.h>
#include "nandGate.h"


nandGate *nandGate_new(transistor *input1, transistor *input2) {
	nandGate *na = malloc(sizeof(nandGate));

	na->n1 = notGate_new(input1);
	na->n2 = notGate_new(input2);
	na->a = andGate_new(na->n1->t, na->n2->t);

	return na;
}

void nandGate_print(nandGate *na) {
	printf("Input 1: %d\n", nandGate_input1(na));
	printf("Input 2: %d\n", nandGate_input2(na));
	printf("Output: %d\n", nandGate_output(na));
}

int nandGate_input1(nandGate *na) {
	return notGate_input(na->n1);
}
int nandGate_input2(nandGate *na) {
	return notGate_input(na->n2);
}
int nandGate_output(nandGate *na) {
	return andGate_output(na->a);
}
