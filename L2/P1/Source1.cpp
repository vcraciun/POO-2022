#include "Header1.h"

int FunctiePrivata(int a, int b)
{
	return a + b;
}

int FunctiePubica1(int a, int b)
{
	return a * b + FunctiePrivata(a, b);
}

