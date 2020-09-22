#ifndef CONSTANT
#define CONSTANT

extern int debug;

int ground(void *t);
int vcc(void *t);

extern int(*zero)(void *);
extern int(*one)(void *);


#endif
