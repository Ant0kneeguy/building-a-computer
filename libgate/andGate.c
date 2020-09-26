#include <stdlib.h>
#include <stdio.h>

#include "andGate.h"
#include "../libconst/libconst.h"

andGate *andGate_new(void *input1, void *input2) {
	andGate *and = malloc(sizeof(andGate));
	if (andGate_debug) {
		printf("andGate_new:\n");
		printf("Creating notGate for input 2:\n");
	}
	and->not = notGate_new(input2);
	if (andGate_debug == 1) {
		printf("Created notGate:\n");
		notGate_print(and->not);
		printf("Creating transistor for input 1:\n");
		//printf("Size of and->not->t: %d\n", sizeof(*(and->not->t)));
		//void *test = and->not->t;
		//printf("Size of void pointer: %d\n", sizeof(test));
	}
	and->t = transistor_new(input1, and->not->t);
	if (andGate_debug == 1) {
		printf("andGate_new:\n");
		printf("Created transistor:\n");
		transistor_print(and->t);
	}
	return and;
}

void andGate_print(andGate* and) {
	printf("Input 1: %d\n", andGate_input1(and));
	printf("Input 2: %d\n", andGate_input2(and));
	printf("Output: %d\n", andGate_output(and));
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
