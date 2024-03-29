#ifndef WIRE
#define WIRE

#include "../transistor/libtrans.h"
#include "../constants/libconst.h"

typedef struct _wire {
	void *input;
	int state;
} wire;

wire *wire_new(void *input);
void wire_connect(wire *w, void *input);
void wire_print(wire *w);

void wire_update(wire *w);
int wire_output(wire *w);


#endif
