#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "transistor/libtrans.h"
#include "logic_gates/libgate.h"
#include "constants/libconst.h"
#include "wire/libwire.h"
#include "debugging/stacktrace.h"

//test harness
int main(int argc, char** argv) {
	stacktrace_add();

//testing transistors
	transistor *t1 = transistor_new(ground, ground);
	transistor *t2 = transistor_new(vcc, ground);
	transistor *t3 = transistor_new(ground, vcc);
	transistor *t4 = transistor_new(vcc, vcc);
	if (transistor_output(t1) != 0 || transistor_output(t2) != 1 ||
		transistor_output(t3) != 0 || transistor_output(t4) != 0) {
		printf("Transistor error");
		return(-1);
	}


//testing NOT gates
	notGate *n1 = notGate_new(zero);
	notGate *n2 = notGate_new(one);
	if (notGate_output(n1) != 1 || notGate_output(n2) != 0) {
		printf("NOT gate error");
		return(-1);
	}

//testing AND gates
	andGate *and1 = andGate_new(zero, zero);
	andGate *and2 = andGate_new(zero, one);
	andGate *and3 = andGate_new(one, zero);
	andGate *and4 = andGate_new(one, one);
	if (andGate_output(and1) != 0 || andGate_output(and2) != 0 ||
		andGate_output(and3) != 0 || andGate_output(and4) != 1) {
		printf("AND gate error\n");
		return(-1);
	}

//testing NAND gates
	nandGate *nand1 = nandGate_new(zero, zero);
	nandGate *nand2 = nandGate_new(zero, one);
	nandGate *nand3 = nandGate_new(one, zero);
	nandGate *nand4 = nandGate_new(one, one);
	if (nandGate_output(nand1) != 1 || nandGate_output(nand2) != 1 ||
		nandGate_output(nand3) != 1 || nandGate_output(nand4) != 0) {
		printf("NAND gate error");
		return(-1);
	}

//testing NOR gates
	norGate* nor1 = norGate_new(zero, zero);
	norGate* nor2 = norGate_new(one, zero);
	norGate* nor3 = norGate_new(zero, one);
	norGate* nor4 = norGate_new(one, one);
	if (norGate_output(nor1) != 1 || norGate_output(nor2) != 0 ||
		norGate_output(nor3) != 0 || norGate_output(nor4) != 0) {
		printf("NOR gate error");
		return(-1);
	}

//testing OR gates
	orGate *or1 = orGate_new(zero, zero);
	orGate *or2 = orGate_new(zero, one);
	orGate *or3 = orGate_new(one, zero);
	orGate *or4 = orGate_new(one, one);
	if (orGate_output(or1) != 0 || orGate_output(or2) != 1 ||
		orGate_output(or3) != 1 || orGate_output(or4) != 1) {
		printf("OR gate error");
		return(-1);
	}

//testing XOR gates
	xorGate *xor1 = xorGate_new(zero, zero);
	xorGate *xor2 = xorGate_new(zero, one);
	xorGate *xor3 = xorGate_new(one, zero);
	xorGate *xor4 = xorGate_new(one, one);
	if (xorGate_output(xor1) != 0 || xorGate_output(xor2) != 1 ||
		xorGate_output(xor3) != 1 || xorGate_output(xor4) != 0) {
		printf("XOR gate error");
		return(-1);
	}


//testing wires
	wire *w1 = wire_new(ground);
	// wire_print(w1);
	wire *w2 = wire_new(vcc);
	// wire_print(w2);

//can we connect a transistor to a wire?
	transistor *t5 = transistor_new(w1, w1);
	transistor *t6 = transistor_new(w1, w2);
	transistor *t7 = transistor_new(w2, w1);
	transistor *t8 = transistor_new(w2, w2);
	if (transistor_output(t5) != 0 || transistor_output(t6) != 0 ||
		transistor_output(t7) != 1 || transistor_output(t8) != 0) {
			printf("Transistor error (wires)!");
			exit(-1);
	}

//how about a mixture?
	transistor *t9 = transistor_new(w2, t5);
	transistor *t10 = transistor_new(w2, t7);
	transistor *t11 = transistor_new(t7, w1);
	transistor *t12 = transistor_new(t7, w2);
	if (transistor_output(t9) != 1 || transistor_output(t10) != 0 ||
		transistor_output(t11) != 1 || transistor_output(t12) != 0) {
			printf("Transistor error (wires and transistors)!");
			exit(-1);
	}

//and mix in the consts
	transistor *t13 = transistor_new(vcc, w1);
	transistor *t14 = transistor_new(vcc, w2);
	transistor *t15 = transistor_new(w2, ground);
	transistor *t16 = transistor_new(w2, vcc);
	transistor *t17 = transistor_new(vcc, t5);
	transistor *t18 = transistor_new(vcc, t7);
	transistor *t19 = transistor_new(t7, ground);
	transistor *t20 = transistor_new(t7, vcc);
	if (transistor_output(t13) != 1 || transistor_output(t14) != 0 ||
		transistor_output(t15) != 1 || transistor_output(t16) != 0) {
			printf("Transistor error (consts and wires)!");
			exit(-1);
	}
	if (transistor_output(t17) != 1 || transistor_output(t18) != 0 ||
		transistor_output(t19) != 1 || transistor_output(t20) != 0) {
			printf("Transistor error (consts and transistors)!");
			exit(-1);
	}

	printf("Tests succeeded!\n");

	//trying to connect a transistor to itself with a wire
	wire *w3 = wire_new(vcc);
	transistor *t21 = transistor_new(w3, ground);
	w3->input = t21;
	w3->state = collector(t21);
	//transistor_print(t21);
	//wire_print(w3);

	//printf("%d\n", transistor_output(t21));
	//printf("%d\n", wire_output(w3));

	//trying to connect a NOT gate to itself with a wire
	wire *w4 = wire_new(NULL);
	notGate *n3 = notGate_new(w4);
	wire_connect(w4, n3->t);
	printf("Wire: %d\n", wire_output(w4));
	printf("NOT gate: %d\n", notGate_output(n3));
	//wire_update(w4);
	printf("Wire: %d\n", wire_output(w4));
	printf("NOT gate: %d\n", notGate_output(n3));


	printf("Size of wire: %lu\n", sizeof(*w1));
	printf("Size of transistor: %lu\n", sizeof(*t1));
	printf("Size of const: %lu\n", sizeof(ground));
	return 0;

	//SUCCESS
}


//debug, perhaps we could redefine transistor_new() using a macro to keep track of where the function was called from?
//rename folders
//add stacktrace
//edit cmake (maybe find a shortcut for compiling all files in subfolders)
