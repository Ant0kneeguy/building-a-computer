#include <stdlib.h>
#include <stdio.h>
#include "norGate.h"

norGate *norGate_new(transistor *input1, transistor *input2) {
	norGate *no = malloc(sizeof(norGate));

	no->n1 = notGate_new(input1);
	no->n2 = notGate_new(input2);
	no->a = andGate_new(no->n1->t, no->n2->t);

	return no;
}

void norGate_print(norGate *no) {
	printf("Input 1: %d\n", norGate_input1(no));
	printf("Input 2: %d\n", norGate_input2(no));
	printf("Output: %d\n", norGate_output(no));
}

int norGate_input1(norGate *no) {
	return notGate_input(no->n1);
}
int norGate_input2(norGate *no) {
	return notGate_input(no->n2);
}
int norGate_output(norGate *no) {
	return andGate_output(no->a);
}
