#ifndef ORGATE
#define ORGATE

#include "norGate.h"
#include "notGate.h"

typedef struct _orGate {
	norGate *no;
	notGate *n;
} orGate;

orGate *orGate_new(transistor *input1, transistor *input2);
void orGate_print(orGate *o);
int orGate_input1(orGate *o);
int orGate_input2(orGate *o);
int orGate_output(orGate *o);

#endif
