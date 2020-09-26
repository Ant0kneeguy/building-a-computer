#include <stdio.h>
#include <stdlib.h>
#include "wire.h"

wire *wire_new(void *input) {
	wire *w = malloc(sizeof(wire));
	w->input = input;
	if (input == ground) {
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
	printf("State: %d\n", wire_output(w));
}

void wire_update(wire *w) {
	if (w->input != ground && w->input != vcc) {
		w->state = collector(w->input);
	}
}

int wire_output(wire *w) {
	return w->state;
}

//what we want to happen:
	//NOT nate output
	//checks input (getEmitter/getBase)
	//one of them is a wire (0), calls function on that
	//outputs 1

	//wire now needs to update
