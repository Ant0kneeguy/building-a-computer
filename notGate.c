#include <stdlib.h>
#include <stdio.h>

#include "notGate.h"

notGate *notGate_new(transistor *input) {
		notGate *n = malloc(sizeof(notGate));
		if (n==NULL) {
			printf("ERROR: malloc failed!");
			exit(-1);
		}
		n->t = transistor_new(vcc, input);
		return n;
}

int notGate_output(notGate *n) {
	return collector(n->t);
}

void notGate_print(notGate* n) {
	printf("Input: %d\n", n->t->getBase(n->t));
	printf("Output: %d\n", notGate_output(n));
}



// int main() {
//
// 	notGate *n1 = notGate_new(ONE);
// 	notGate_print(n1);
// 	printf("%d\n", notGate_output(n1));
//
// }
