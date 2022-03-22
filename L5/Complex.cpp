#include "Complex.h"

Complex::Complex()
{
	cout << "Complex::Complex() - " << hex << this << endl;
	real = 0;
	imaginar = 0;
}

Complex::Complex(int re, int im): real(re), imaginar(im) 
{
	cout << "Complex::Complex(re, im) - " << hex << this << endl;
}

Complex::~Complex()
{
	cout << "Complex::~Complex() - " << hex << this << endl;
	real = -1;
	imaginar = -1;
}

void Complex::Print()
{
	cout << "Complex::Print() - " << hex << this << endl;
	cout << dec << real << " + " << dec << imaginar << "j" << endl;
}

