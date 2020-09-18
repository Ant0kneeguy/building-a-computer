#ifndef NANDGATE
#define NANDGATE

#include "notGate.h"
#include "andGate.h"

typedef struct _nandGate {
	notGate *n1;
	notGate *n2;
	andGate *a;
} nandGate;

nandGate *nandGate_new(transistor *input1, transistor *input2);
void nandGate_print(nandGate *na);

int nandGate_input1(nandGate *na);
int nandGate_input2(nandGate *na);
int nandGate_output(nandGate *na);

#endif