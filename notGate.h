#ifndef NOTGATE
#define NOTGATE

#include "transistor.h"

typedef struct _notGate {
	transistor *t;
} notGate;

notGate *notGate_new(transistor *input);
int notGate_output(notGate *n);
void notGate_print(notGate* n);

#endif
