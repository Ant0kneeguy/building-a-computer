#include <stdio.h>
#include <stdlib.h>
#include "wire.h"
#include "../libtrans/libtrans.h"
#include "../libconst/libconst.h"

wire *wire_new(void *input) {
	wire *w = malloc(sizeof(wire));
	if (input == ground) {
		w->input_transistor = NULL;
		w->state = 0;
	} else if(input == vcc) {
		w->input_transistor = NULL;
		w->state = 1;
	} else {
		//assumes it is connected to a transistor pointer
		w->input_transistor = input;
		w->state = transistor_output(input);
	}
	return w;
}

void wire_print(wire* w) {
	printf("State: %d\n", wire_getState(w));
}

int wire_getState(wire *w) {
	if (w->input_transistor == NULL) {
		return w->state;
	} else {
		w->state = collector(w->input_transistor);
		return w->state;
	}
}
