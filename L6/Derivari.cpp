#include "Derivari.h"

A::A()
{
	cout << "A::A()" << endl;
	x = 15;
}

A::A(int xx)
{
	cout << "A::A(int)" << endl;
	x = xx;
}

A::~A()
{
	cout << "A::~A()" << endl;
	x = 0;
}

void A::Chenge(int xx)
{
	cout << "A::Change(int)" << endl;
	x = xx;
}

int A::Get()
{
	cout << "A::Get()" << endl;
	return x;
}

void A::Specific()
{
	cout << "A::Specific()" << endl;
}
//-----------------------------------------------------------

B::B()
{
	cout << "B::B()" << endl;
	y = 0;
}

B::B(int yy)
{
	cout << "B::B(int)" << endl;
	y = yy;
}

B::~B()
{
	cout << "B::~B()" << endl;
	y = 0;
}

void B::Chenge(int yy)
{
	cout << "B::Change(int)" << endl;
	y = yy;
}

int B::Get()
{
	cout << "B::Get()" << endl;
	return y;
}

void B::Specific()
{
	cout << "B::Specific()" << endl;
}
//--------------------------------------------------------

C::C()
{
	cout << "C::C()" << endl;
	z = 0;
}

C::C(int zz)
{
	cout << "C::C(int)" << endl;
	z = zz;
}

C::~C()
{
	cout << "C::~C()" << endl;
	z = 0;
}

void C::Chenge(int zz)
{
	cout << "C::Change(int)" << endl;
	z = zz;
}

int C::Get()
{
	cout << "C::Get()" << endl;
	return z;
}

void C::Specific()
{
	cout << "C::Specific()" << endl;
}
//--------------------------------------------------------

D::D()
{
	cout << "D::D()" << endl;
	q = 0;
}

D::D(int qq)
{
	cout << "D::D(int)" << endl;
	q = qq;
}

D::~D()
{
	cout << "D::~D()" << endl;
	q = 0;
}

void D::Chenge(int qq)
{
	cout << "D::Change(int)" << endl;
	q = qq;
}

int D::Get()
{
	cout << "D::Get()" << endl;
	return q;
}

void D::Specific()
{
	cout << "D::Specific()" << endl;
}
//--------------------------------------------------------