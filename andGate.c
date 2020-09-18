#include <stdlib.h>
#include <stdio.h>

#include "andGate.h"

andGate *andGate_new(transistor *input1, transistor *input2) {
	andGate *a = malloc(sizeof(andGate));
	a->n = notGate_new(input2);
	a->t = transistor_new(input1, a->n->t);
	return a;
}

void andGate_print(andGate* a) {
	printf("Input 1: %d\n", a->t->getEmitter(a->t));
	printf("Input 2: %d\n", a->n->t->getBase(a->n->t));
	printf("Output: %d\n", collector(a->t));
}

int andGate_output(andGate *a) {
	collector(a->t);
}

// int main() {
// 	andGate *a = andGate_new(ONE, ONE);
// 	//andGate_print(a);
// //AAH segfault
// 	//printf("%d/n", andGate_output(a));
// }
