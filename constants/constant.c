#include "constant.h"

int ground(void* uselessArg) {
	return 0;
}

int vcc(void* uselessArg) {
	return 1;
}

int(*zero)(void*) = ground;
int(*one)(void*) = vcc;

void *is_transistor = (void*)0;
void *is_wire = (void*)1;
