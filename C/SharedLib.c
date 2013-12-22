/*
	Author: Dung Harry
	Date created: 22nd, December 2013
	Operating System: Ubuntu 13.10 Desktop x86_64
	Compiler: GNU compiler 4.4.0

	Description: this is the testing source code for shared library 
in C programming language

	Compile this source code into shared library by following 
commands:
		gcc -c -fpic SharedLib.c
		gcc -shared -o libSharedLib.so SharedLib.o
		export LD_LIBRARY_PATH=[path to this 
folder]:$LD_LIBRARY_PATH
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stCaculator Caculator;

struct stCaculator {
	int data;
	int (*add) (Caculator *pCaculator, int a);
	int (*multiply) (Caculator *pCaculator, int a);
	void (*print) (Caculator *pCaculator);
	void (*input) (Caculator *pCaculator);
};

int iCCLT_add(Caculator *pCaculator, int a);
int iCCLT_multiply(Caculator *pCaculator, int a);
void vCCLT_print(Caculator *pCaculator);
void vCCLT_input(Caculator *pCaculator);

void Caculator1(Caculator **pCaculator) {
	(*pCaculator) = (Caculator *) malloc(sizeof(Caculator));
	(*pCaculator)->add = &iCCLT_add;
	(*pCaculator)->multiply = &iCCLT_multiply;
	(*pCaculator)->print = &vCCLT_print;
	(*pCaculator)->input = &vCCLT_input;
}

int iCCLT_add(Caculator *pCaculator, int a) {
	return pCaculator->data += a;
}

int iCCLT_multiply(Caculator *pCaculator, int a) {
	return pCaculator->data *= a;
}

void vCCLT_print(Caculator *pCaculator) {
	printf("The value is: %d\n", pCaculator->data);
}

void vCCLT_input(Caculator *pCaculator) {
	printf("Enter the value: ");
	scanf("%d", &(pCaculator->data));
}
