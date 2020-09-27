#include <stdlib.h>
#include <stdio.h>
#include "nandGate.h"


nandGate *nandGate_new(void *input1, void *type_of_input1, void *input2,
						void *type_of_input2) {
	nandGate *nand = malloc(sizeof(nandGate));

	nand->and = andGate_new(input1, type_of_input1, input2, type_of_input2);
	nand->not = notGate_new(nand->and->t, is_transistor);

	return nand;
}

void nandGate_print(nandGate *nand) {
	printf("Input 1: %d\n", nandGate_input1(nand));
	printf("Input 2: %d\n", nandGate_input2(nand));
	printf("Output: %d\n", nandGate_output(nand));
}

int nandGate_input1(nandGate *nand) {
	return andGate_input1(nand->and);
}
int nandGate_input2(nandGate *nand) {
	return andGate_input2(nand->and);
}
int nandGate_output(nandGate *nand) {
	return notGate_output(nand->not);
}
