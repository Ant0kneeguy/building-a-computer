#ifndef TRANSISTOR
#define TRANSISTOR

typedef struct _transistor {
	//emitter
	int(*getEmitter)(struct _transistor*);
	struct _transistor *emitter_transistor;

	//base
	int(*getBase)(struct _transistor*);
	struct _transistor *base_transistor;
} transistor;

int vcc(transistor *t);

int ground(transistor *t);

transistor* transistor_new(void *emitter_connection, void *base_connection);
int link_to_emitter(transistor* this);
int link_to_base(transistor* this);
int collector(transistor* target);
void transistor_print(transistor* t);

#endif
