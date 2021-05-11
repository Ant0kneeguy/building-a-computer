#include <stdio.h>
#include <stdlib.h>
#include "transistor.h"
#include "../debugging/stacktrace.h"


/**
A transistor has 3 fields, 2 input (emitter and base) and 1 output (collector).
The collector output is equal to the emitter input if the base is set to 0.
If instead the base is 1, the output is always 0.
**/


							//*** INPUTS ***//

//We use a struct to store values for the emitter and base inputs.
//These are function pointers, because our inputs can be set to the outputs of
//other transistors (and we need function to determine the output of a
//collector).
//The struct also contains two pointers to transistors that the collector will
//need later on.



							//***CONSTRUCTOR***//

//To create a new transistor we must specify what the values of the emitter and
//base inputs will be. These can be ground, vcc, other transistors or wires.

//we could create a void* to represent 'transistor' and 'wire' in libconst...
transistor* transistor_new(void *emitter, void *base) {
	stacktrace_add();

	transistor* t = malloc(sizeof(transistor));
	if (t==NULL) {
		printf("ERROR: malloc failed!");
		exit(-1);
	}

	//if emitter is connected to vcc
	if (emitter == vcc) {
		t->emitter_connection = NULL;
		t->getEmitter = vcc;
	//if emitter is connected to ground
	} else if (emitter == ground) {
		t->emitter_connection = NULL;
		t->getEmitter = ground;
	//if emitter is connected to a transistor
	} else if (sizeof(*emitter) == sizeof(transistor)) {
		t->emitter_connection = emitter;
		t->getEmitter = (int(*)(void*))transistor_at_emitter;
	//if emitter is connected to a wire
	} else if (sizeof(*emitter) == sizeof(wire)) {
		t->emitter_connection = emitter;
		t->getEmitter = (int(*)(void*))wire_at_emitter;
	} else {
		printf("ERROR: unable to determine type of emitter!\n");
		exit(-1);
	}

	//if base is connected to vcc
	if (base == vcc) {
		t->base_connection = NULL;
		t->getBase = vcc;
	//if base is connected to ground
	} else if (base == ground) {
		t->base_connection = NULL;
		t->getBase = ground;
	//if base is connected to a transistor
	} else if (sizeof(*base) == sizeof(transistor)) {
		t->base_connection = base;
		t->getBase = (int(*)(void*))transistor_at_base;
	//if base is connected to a wire
	} else if (sizeof(*base) == sizeof(wire)) {
		t->base_connection = base;
		t->getBase = (int(*)(void*))wire_at_base;
	} else {
		printf("ERROR: unable to determine type of base!\n");
		printf("Size of base: %lu\n", sizeof(*base));
		printf("Size of transistor: %lu\n", sizeof(transistor));
		printf("Size of wire: %lu\n", sizeof(wire));
		printf("Size of const: %lu\n", sizeof(ground));
		exit(-1);
	}

	stacktrace_remove();
	return t;
}


							//*** OUTPUT ***//

int transistor_at_emitter(transistor *this) {
	return transistor_output(this->emitter_connection);
};

int transistor_at_base(transistor *this) {
	return transistor_output(this->base_connection);
};

int wire_at_emitter(transistor *this) {
	//(causes a seg fault)
	//wire_update((wire*)this->emitter_connection);
	return wire_output((wire*)this->emitter_connection);
}

int wire_at_base(transistor *this) {
	//wire_update((wire*)this->base_connection);
	return wire_output((wire*)this->base_connection);
}

//collector - should only be called on transistors. We use a void pointer
//because getEmitter and getBase may not point to transistors.
int collector(transistor* this) {
	if (this->getBase(this) == 0) {
		return this->getEmitter(this);
	} else {
		return 0;
	}
};

void transistor_print(transistor* t) {
	printf("Emitter: %d\n", transistor_input1(t));
	printf("Base: %d\n", transistor_input2(t));
	printf("Collector: %d\n", transistor_output(t));
}

int transistor_input1(transistor *t) {
	return t->getEmitter(t);
}
int transistor_input2(transistor *t) {
	return t->getBase(t);
}
int transistor_output(transistor* t) {
	return collector(t);
}

//could possible modify getEmitter and getBase to not take in void pointers...
