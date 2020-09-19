#ifndef NANDGATE
#define NANDGATE

#include "notGate.h"
#include "andGate.h"

typedef struct _nandGate {
	andGate *and;
	notGate *not;
} nandGate;

nandGate *nandGate_new(transistor *input1, transistor *input2);
void nandGate_print(nandGate *nand);

int nandGate_input1(nandGate *nand);
int nandGate_input2(nandGate *nand);
int nandGate_output(nandGate *nand);

#endif
