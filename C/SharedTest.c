/*
	Author: Dung Harry
	Date created: 22nd, December 2013
	Operating System: Minix 3.2.1 OS
	Compiler: GNU compiler 4.4.0

	Description: this is the testing source code for SharedLib.c for 
using of shared library in C programming language

	Compile and run by following commands:
		gcc -c SharedTest.c
		gcc -L./ -o SharedTest SharedTest.o -lSharedLib
		./SharedTest
*/

#include "SharedLib.c"

void main(int argc, char *argv[]) {
	Caculator *obj;
	int iTemp;

	Caculator1(&obj);
	obj->input(obj);

	obj->print(obj);

	printf("\nEnter the value you wanted to add: ");
	scanf("%d", &iTemp);

	obj->add(obj, iTemp);

	obj->print(obj);

	printf("\nEnter the value you wanted to multiply: ");
	scanf("%d", &iTemp);

	obj->multiply(obj, iTemp);

	obj->print(obj);
}
