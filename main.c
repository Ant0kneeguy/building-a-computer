#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "transistor.h"
#include "notGate.h"
#include "andGate.h"
#include "nandGate.h"
#include "norGate.h"
#include "orGate.h"
#include "xorGate.h"

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
	notGate *n1 = notGate_new(t1);
	notGate *n2 = notGate_new(t2);
	if (notGate_output(n1) != 1 || notGate_output(n2) != 0) {
		printf("NOT gate error");
		return(-1);
	}

//testing AND gates
	andGate *and1 = andGate_new(t1, t1);
	andGate *and2 = andGate_new(t1, t2);
	andGate *and3 = andGate_new(t2, t1);
	andGate *and4 = andGate_new(t2, t2);
	if (andGate_output(and1) != 0 || andGate_output(and2) != 0 ||
		andGate_output(and3) != 0 || andGate_output(and4) != 1) {
		printf("AND gate error");
		return(-1);
	}

//testing NAND gates
	nandGate *nand1 = nandGate_new(t1, t1);
	nandGate *nand2 = nandGate_new(t1, t2);
	nandGate *nand3 = nandGate_new(t2, t1);
	nandGate *nand4 = nandGate_new(t2, t2);
	if (nandGate_output(nand1) != 1 || nandGate_output(nand2) != 1 ||
		nandGate_output(nand3) != 1 || nandGate_output(nand4) != 0) {
		printf("NAND gate error");
		return(-1);
	}

//testing NOR gates
	norGate* nor1 = norGate_new(t1, t1);
	norGate* nor2 = norGate_new(t2, t1);
	norGate* nor3 = norGate_new(t1, t2);
	norGate* nor4 = norGate_new(t2, t2);
	if (norGate_output(nor1) != 1 || norGate_output(nor2) != 0 ||
		norGate_output(nor3) != 0 || norGate_output(nor4) != 0) {
		printf("NOR gate error");
		return(-1);
	}

//testing OR gates
	orGate *or1 = orGate_new(t1, t1);
	orGate *or2 = orGate_new(t1, t2);
	orGate *or3 = orGate_new(t2, t1);
	orGate *or4 = orGate_new(t2, t2);
	if (orGate_output(or1) != 0 || orGate_output(or2) != 1 ||
		orGate_output(or3) != 1 || orGate_output(or4) != 1) {
		printf("OR gate error");
		return(-1);
	}

//testing XOR gates
	xorGate xo;

	printf("Tests succeeded!\n");

	return 0;
}
