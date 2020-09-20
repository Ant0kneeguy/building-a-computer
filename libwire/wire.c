#include <stdio.h>
#include <stdlib.h>
#include "wire.h"
#include "../libtransistor/libtransistor.h"

wire *wire_new(void *input) {
	wire *w = malloc(sizeof(wire));
	if (input == NULL || input == ground) {
		w->state = 0;
	} else if(input == vcc) {
		w->state = 1;
	} else {
		//assumes it is connected to a transistor pointer
		w->state = transistor_output(input);
	}
	return w;
}

void wire_print(wire* w) {
	printf("State: %d\n", wire_getState(w));
}

void wire_setState(wire *w, int state) {
	w->state = state;
}

int wire_getState(wire *w) {
	return w->state;
}
