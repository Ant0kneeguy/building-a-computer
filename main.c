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

	#define ZERO t1
	#define ONE t2

//testing NOT gates
	notGate *n1 = notGate_new(ZERO);
	notGate *n2 = notGate_new(ONE);
	if (notGate_output(n1) != 1 || notGate_output(n2) != 0) {
		printf("NOT gate error");
		return(-1);
	}

//testing AND gates
	andGate *and1 = andGate_new(ZERO, ZERO);
	andGate *and2 = andGate_new(ZERO, ONE);
	andGate *and3 = andGate_new(ONE, ZERO);
	andGate *and4 = andGate_new(ONE, ONE);
	if (andGate_output(and1) != 0 || andGate_output(and2) != 0 ||
		andGate_output(and3) != 0 || andGate_output(and4) != 1) {
		printf("AND gate error");
		return(-1);
	}

//testing NAND gates
	nandGate *nand1 = nandGate_new(ZERO, ZERO);
	nandGate *nand2 = nandGate_new(ZERO, ONE);
	nandGate *nand3 = nandGate_new(ONE, ZERO);
	nandGate *nand4 = nandGate_new(ONE, ONE);
	if (nandGate_output(nand1) != 1 || nandGate_output(nand2) != 1 ||
		nandGate_output(nand3) != 1 || nandGate_output(nand4) != 0) {
		printf("NAND gate error");
		return(-1);
	}

//testing NOR gates
	norGate* nor1 = norGate_new(ZERO, ZERO);
	norGate* nor2 = norGate_new(ONE, ZERO);
	norGate* nor3 = norGate_new(ZERO, ONE);
	norGate* nor4 = norGate_new(ONE, ONE);
	if (norGate_output(nor1) != 1 || norGate_output(nor2) != 0 ||
		norGate_output(nor3) != 0 || norGate_output(nor4) != 0) {
		printf("NOR gate error");
		return(-1);
	}

//testing OR gates
	orGate *or1 = orGate_new(ZERO, ZERO);
	orGate *or2 = orGate_new(ZERO, ONE);
	orGate *or3 = orGate_new(ONE, ZERO);
	orGate *or4 = orGate_new(ONE, ONE);
	if (orGate_output(or1) != 0 || orGate_output(or2) != 1 ||
		orGate_output(or3) != 1 || orGate_output(or4) != 1) {
		printf("OR gate error");
		return(-1);
	}

//testing XOR gates
	xorGate *xor1 = xorGate_new(ZERO, ZERO);
	xorGate *xor2 = xorGate_new(ZERO, ONE);
	xorGate *xor3 = xorGate_new(ONE, ZERO);
	xorGate *xor4 = xorGate_new(ONE, ONE);
	if (xorGate_output(xor1) != 0 || xorGate_output(xor2) != 1 ||
		xorGate_output(xor3) != 1 || xorGate_output(xor4) != 0) {
		printf("XOR gate error");
		return(-1);
	}

	printf("Tests succeeded!\n");

	return 0;
}
