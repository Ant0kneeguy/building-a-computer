#ifndef NORGATE
#define NORGATE

#include "notGate.h"
#include "andGate.h"

typedef struct _norGate {
	notGate *not1;
	notGate *not2;
	andGate *and;
} norGate;

norGate *norGate_new(void *input1, void *input2);
void norGate_print(norGate *nor);

int norGate_input1(norGate *nor);
int norGate_input2(norGate *nor);
int norGate_output(norGate *nor);


#endif
