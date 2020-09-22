#ifndef XORGATE
#define XORGATE

#include "notGate.h"
#include "andGate.h"
#include "orGate.h"

typedef struct _xorGate {
	notGate *not1;
	notGate *not2;
	andGate *and1;
	andGate *and2;
	orGate *or;
} xorGate;

xorGate *xorGate_new(void *input1, void *input2);
void xorGate_print(xorGate *xor);

int xorGate_input1(xorGate *xor);
int xorGate_input2(xorGate *xor);
int xorGate_output(xorGate *xor);


#endif
