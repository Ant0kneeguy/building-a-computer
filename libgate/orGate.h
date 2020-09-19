#ifndef ORGATE
#define ORGATE

#include "norGate.h"
#include "notGate.h"

typedef struct _orGate {
	norGate *nor;
	notGate *not;
} orGate;

orGate *orGate_new(transistor *input1, transistor *input2);
void orGate_print(orGate *or);
int orGate_input1(orGate *or);
int orGate_input2(orGate *or);
int orGate_output(orGate *or);

#endif
