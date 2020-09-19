#include <stdio.h>
#include <stdlib.h>
#include "transistor.h"

#define DEBUG 0
/**
A transistor has 3 fields, 2 input (emitter and base) and 1 output (collector).
The collector output is equal to the emitter input if the base is set to 0.
If instead the base is 1, the output is always 0.
**/

int vcc(transistor *t) {
	return 1;
}

int ground(transistor *t) {
	return 0;
}


							//*** INPUTS ***//

//We use a struct to store values for the emitter and base inputs.
//These are function pointers, because our inputs can be set to the outputs of
//other transistors (and we need function to determine the output of a
//collector).
//The struct also contains two pointers to transistors that the collector will
//need later on.



							//***CONSTRUCTOR***//

//To create a new transistor we must specify what the values of the emitter and
//base inputs will be.
//We cannot pass arguments inside a function pointer, so we must specify those
//arguments seperately (as "target" arguments), so that the collector function
//knows what transistor it is supposed to find the output of.






//arguments here are a bit dumb. link_to_ground and link_to_vcc make no sense.
//instead, 1st and 3rd arguments should be void points so they can take pointers
//to ints or transistors

transistor* transistor_new(void *emitter_connection, void *base_connection) {

	transistor* t = malloc(sizeof(transistor));
	if (t==NULL) {
		printf("ERROR: malloc failed!");
		exit(-1);
	}

//if t1 is vcc then we want getEmitter to point to vcc
	if (emitter_connection == vcc) {
		t->emitter_transistor = NULL;
		t->getEmitter = vcc;
		if (DEBUG == 1) {
			printf("Debug: emitter connected to a vcc\n");
		}
	} else if (emitter_connection == ground) {
		t->emitter_transistor = NULL;
		t->getEmitter = ground;
		if (DEBUG == 1) {
			printf("Debug: emitter connected to ground\n");
		}
	} else {
		t->emitter_transistor = (transistor*)emitter_connection;
		t->getEmitter = link_to_emitter;
		if (DEBUG == 1) {
			printf("Debug: emitter connected to a transistor\n");
		}
	}

	if (base_connection == vcc) {
		t->base_transistor = NULL;
		t->getBase = vcc;
		if (DEBUG == 1) {
			printf("Debug: base connected to vcc\n");
		}
	} else if (base_connection == ground) {
		t->base_transistor = NULL;
		t->getBase = ground;
		if (DEBUG == 1) {
			printf("Debug: emitter connected to a ground\n");
		}
	} else {
		t->base_transistor = (transistor*)base_connection;
		t->getBase = link_to_base;
		if (DEBUG == 1) {
			printf("Debug: base connected to a transistor\n");
		}
	}

	return t;
}


							//*** OUTPUT ***//

//The collector's output is determined by logic, and since we can't define a
//function within a struct, we must define it outside.

//The collector method must know whether it is the first or second argument of
//transistor_new so that it can choose the correct target out of emitter_target
//and base_target. This solution chosen here is to have two collector methods.
//Each method uses a different target and can only be used in a specific part of
//the constructor..

//The emitter_collector function pointer represents a collector linked to the emitter input of the
//transistor being constructed. It must go in place of the "arg1" argument
//of the constructor.
int link_to_emitter(transistor* this) {
	transistor* target = this->emitter_transistor;
	if (target->getBase(target) == 0) {
		return target->getEmitter(target);
	} else {
		return 0;
	}
};

//The base_collector
int link_to_base(transistor* this) {
	transistor* target = this->base_transistor;
	if (target->getBase(target) == 0) {
		return target->getEmitter(target);
	} else {
		return 0;
	}
};

//collector
int collector(transistor* target) {
	if (target->getBase(target) == 0) {
		if (DEBUG == 1) {
			printf("Debug: target->getBase = 0\n");
		}
		return target->getEmitter(target);
	} else {
		if (DEBUG == 1) {
			printf("target->getBase = 1\n");
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
int transistor_output(transistor *t) {
	return collector(t);
}
