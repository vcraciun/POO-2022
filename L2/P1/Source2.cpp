#include "Header2.h"

int FunctiePrivata(int a, int b)
{
	return a - b;
}

int FunctiePubica2(int a, int b)
{
	return a * b + FunctiePrivata(a, b);
}

