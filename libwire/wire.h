#ifndef WIRE
#define WIRE

typedef struct _wire {
	int state;
} wire;

wire *wire_new(void *input);
void wire_print(wire* w);

void wire_setState(wire *w, int state);
int wire_getState(wire *w);

#endif
