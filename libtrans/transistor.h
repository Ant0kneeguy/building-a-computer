#ifndef TRANSISTOR
#define TRANSISTOR

#include "../libconst/libconst.h"
#include "../libwire/libwire.h"

//ideally, right, the transistor shouldn't care whether it's linked to
//another transistor or a wire.
typedef struct _transistor {
	//emitter
	//has to be a void* because it links to transistor_at_emitter etc and
	//those functions need a 'this'
	int(*getEmitter)(void*);
	void *emitter_connection;

	//base
	int(*getBase)(void*);
	void *base_connection;

} transistor;

transistor* transistor_new(void *emitter, void *base);
int transistor_at_emitter(transistor *t);
int transistor_at_base(transistor *t);
int wire_at_emitter(transistor *t);
int wire_at_base(transistor *t);

int collector(transistor* target);
void transistor_print(transistor* t);

int transistor_input1(transistor *t);
int transistor_input2(transistor *t);
int transistor_output(transistor *t);

#endif
