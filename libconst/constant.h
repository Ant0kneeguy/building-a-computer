#ifndef CONSTANT
#define CONSTANT

extern int debug;
extern int andGate_debug;

//these functions need a void pointer argument because getBase and getEmitter
//require it
int ground(void*);
int vcc(void*);

extern int(*zero)(void*);
extern int(*one)(void*);


#endif
