#ifndef ANDGATE
#define ANDGATE

#include "transistor.h"
#include "notGate.h"

typedef struct _andGate {
	transistor *t;
	notGate *n;
} andGate;

andGate *andGate_new(transistor *input1, transistor *input2);
void andGate_print(andGate* a);
int andGate_output(andGate *a);

#endif
