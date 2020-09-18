#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "transistor.h"
#include "notGate.h"
#include "andGate.h"
#include "nandGate.h"

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
	andGate *a1 = andGate_new(t1, t1);
	andGate *a2 = andGate_new(t1, t2);
	andGate *a3 = andGate_new(t2, t1);
	andGate *a4 = andGate_new(t2, t2);
	if (andGate_output(a1) != 0 || andGate_output(a2) != 0 ||
		andGate_output(a3) != 0 || andGate_output(a4) != 1) {
		printf("AND gate error");
		return(-1);
	}

//testing NAND gates
	nandGate *na1 = nandGate_new(t1, t1);
	nandGate *na2 = nandGate_new(t1, t2);
	nandGate *na3 = nandGate_new(t2, t1);
	nandGate *na4 = nandGate_new(t2, t2);
	if (nandGate_output(na1) != 1 || nandGate_output(na2) != 1 ||
		nandGate_output(na3) != 1 || nandGate_output(na4) != 0) {
		printf("NAND gate error");
		return(-1);
	}

	printf("Tests succeeded!\n");

	return 0;
}
