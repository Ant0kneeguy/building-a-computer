#ifndef ANDGATE
#define ANDGATE

#include "../libtrans/transistor.h"
#include "notGate.h"

typedef struct _andGate {
	transistor *t;
	notGate *not;
} andGate;

andGate *andGate_new(void *input1, void *type_of_input1, void *input2,
					void *type_of_input2);
void andGate_print(andGate* and);

int andGate_input1(andGate *and);
int andGate_input2(andGate *and);
int andGate_output(andGate *and);

#endif
