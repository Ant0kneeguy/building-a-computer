#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "libtrans/libtrans.h"
#include "libgate/libgate.h"
#include "libconst/libconst.h"
#include "libwire/libwire.h"

//test harness
int main() {
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
		printf("AND gate error");
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

	printf("Tests succeeded!\n");

	return 0;
}

//todo
	//move defs of one and zero to libconst
	//try connecting a transistor to a wire?
	//or a wire to a source?
	//change link to emitter to link from emitter
	//*** work out how to use make **
