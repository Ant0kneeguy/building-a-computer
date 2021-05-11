#ifndef STACKTRACE
#define STACKTRACE

extern char* stacktrace[50];
extern int sizeOfStacktrace;

void stacktrace_add();
void stacktrace_remove();
void stacktrace_print();

char* getFilename(char* filename);
#endif
