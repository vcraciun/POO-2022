#pragma once

#include "Common.h"

class A
{
private:
	int x;
public:
	A();
	A(int xx);
	~A();

	virtual void Change(int xx) = 0;
	virtual void Print();
	void Specific();
};

class B : public A
{
private:
	int y;
public:
	B();
	B(int yy);
	~B();

	virtual void Change(int yy);
	virtual void Print();
	void Specific();
};

class C : public A
{
private:
	int z;
public:
	C();
	C(int zz);
	~C();

	virtual void Change(int yy);
	virtual void Print();
	void Specific();
};

class D : public B, public C
{
private:
	int q;
public:
	D();
	D(int qq);
	~D();

	virtual void Change(int yy);
	virtual void Print();
	void Specific();
};
