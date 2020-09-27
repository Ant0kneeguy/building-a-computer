#include <stdio.h>
#include <stdlib.h>
#include "transistor.h"


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
transistor* transistor_new(void *emitter, void *type_of_emitter, void *base,
							void *type_of_base) {

	transistor* t = malloc(sizeof(transistor));
	if (t==NULL) {
		printf("ERROR: malloc failed!");
		exit(-1);
	}

//if t1 is vcc then we want getEmitter to point to vcc
	if (emitter == vcc) {
		t->emitter_connection = NULL;
		t->getEmitter = vcc;
		if (debug == 1) {
			printf("Debug: emitter connected to vcc\n");
		}
	} else if (emitter == ground) {
		t->emitter_connection = NULL;
		t->getEmitter = ground;
		if (debug == 1) {
			printf("Debug: emitter connected to ground\n");
		}
	} else if (type_of_emitter == is_transistor) {
		//emitter must be a transistor
		t->emitter_connection = emitter;
		t->getEmitter = (int(*)(void*))transistor_at_emitter;
		if (debug == 1) {
			printf("Debug: emitter connected to a transistor\n");
		}
	} else if (type_of_emitter == is_wire) {
		//emitter must be a wire
		t->emitter_connection = emitter;
		t->getEmitter = (int(*)(void*))transistor_at_emitter;
		if (debug == 1) {
			printf("Debug: emitter connected to a wire\n");
		}
	} else {
		printf("ERROR: unable to determine type of emitter!\n");
		exit(-1);
	}

	if (base == vcc) {
		t->base_connection = NULL;
		t->getBase = vcc;
		if (debug == 1) {
			printf("Debug: base connected to vcc\n");
		}
	} else if (base == ground) {
		t->base_connection = NULL;
		t->getBase = ground;
		if (debug == 1) {
			printf("Debug: base connected to ground\n");
		}
	} else if (type_of_base == is_transistor) {
		t->base_connection = base;
		t->getBase = (int(*)(void*))transistor_at_base;
		if (debug == 1) {
			printf("Debug: base connected to a transistor\n");
		}
	} else if (type_of_base == is_wire) {
		//base must be a wire
		t->base_connection = base;
		t->getBase = (int(*)(void*))wire_at_base;
		if (debug == 1) {
			printf("Debug: base connected to a wire\n");
		}
	} else {
		printf("ERROR: unable to determine type of base!\n");
		exit(-1);
	}

	return t;
}


							//*** OUTPUT ***//

int transistor_at_emitter(transistor *this) {
	// transistor *t = (transistor*)this;
	return transistor_output(this->emitter_connection);
};

int transistor_at_base(transistor *this) {
	// transistor *t = (transistor*)this;
	return transistor_output(this->base_connection);
};

int wire_at_emitter(transistor *this) {
	// wire *w = (wire*)this;
	return wire_output((wire*)this->emitter_connection);
}

int wire_at_base(transistor *this) {
	return wire_output((wire*)this->base_connection);
}

//collector - should only be called on transistors. We use a void pointer
//because getEmitter and getBase may not point to transistors.
int collector(transistor* this) {
	if (this->getBase(this) == 0) {
		if (debug == 1) {
			printf("Debug: this->getBase = 0\n");
		}
		return this->getEmitter(this);
	} else {
		if (debug == 1) {
			printf("Debug: this->getBase = 1\n");
		}
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
