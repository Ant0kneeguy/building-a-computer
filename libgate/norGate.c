#include <stdlib.h>
#include <stdio.h>
#include "norGate.h"

norGate *norGate_new(void *input1, void *type_of_input1, void *input2,
						void *type_of_input2) {
	norGate *nor = malloc(sizeof(norGate));

	nor->not1 = notGate_new(input1, type_of_input1);
	nor->not2 = notGate_new(input2, type_of_input2);
	nor->and = andGate_new(nor->not1->t, is_transistor, nor->not2->t,
							is_transistor);

	return nor;
}

void norGate_print(norGate *nor) {
	printf("Input 1: %d\n", norGate_input1(nor));
	printf("Input 2: %d\n", norGate_input2(nor));
	printf("Output: %d\n", norGate_output(nor));
}

int norGate_input1(norGate *nor) {
	return notGate_input(nor->not1);
}
int norGate_input2(norGate *nor) {
	return notGate_input(nor->not2);
}
int norGate_output(norGate *nor) {
	return andGate_output(nor->and);
}
