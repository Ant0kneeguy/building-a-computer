#ifndef WIRE
#define WIRE

#include "../libtrans/libtrans.h"

typedef struct _wire {
	transistor *input_transistor;
	int state;
} wire;

wire *wire_new(void *input);
void wire_print(wire* w);

int wire_getState(wire *w);

#endif
