#include "constant.h"

int debug = 0;

int ground(void *t) {
	return 0;
}

int vcc(void *t) {
	return 1;
}

int(*zero)(void *t) = ground;
int(*one)(void *t) = vcc;
