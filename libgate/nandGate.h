#ifndef NANDGATE
#define NANDGATE

#include "notGate.h"
#include "andGate.h"

typedef struct _nandGate {
	andGate *and;
	notGate *not;
} nandGate;

nandGate *nandGate_new(void *input1, void *type_of_input1, void *input2,
						void *type_of_input2);
void nandGate_print(nandGate *nand);

int nandGate_input1(nandGate *nand);
int nandGate_input2(nandGate *nand);
int nandGate_output(nandGate *nand);

#endif
