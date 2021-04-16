#ifndef NOTGATE
#define NOTGATE

#include "../libtrans/libtrans.h"

typedef struct _notGate {
	transistor *t;
} notGate;

notGate *notGate_new(void *input);
int notGate_input(notGate *not);
int notGate_output(notGate *not);
void notGate_print(notGate* not);

#endif
