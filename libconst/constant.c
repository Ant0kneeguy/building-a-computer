#include "constant.h"

int debug = 0;
int andGate_debug = 1;

int ground(void* uselessArg) {
	return 0;
}

int vcc(void* uselessArg) {
	return 1;
}

int(*zero)(void*) = ground;
int(*one)(void*) = vcc;
