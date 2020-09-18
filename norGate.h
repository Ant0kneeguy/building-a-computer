#ifndef NORGATE
#define NORGATE

#include "notGate.h"
#include "andGate.h"

typedef struct _norGate {
	notGate *n1;
	notGate *n2;
	andGate *a;
} norGate;

norGate *norGate_new(transistor *input1, transistor *input2);
void norGate_print(norGate *no);

int norGate_input1(norGate *no);
int norGate_input2(norGate *no);
int norGate_output(norGate *no);


#endif
