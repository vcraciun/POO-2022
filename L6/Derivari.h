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

	virtual void Chenge(int xx) = 0;
	virtual int Get();
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

	virtual void Chenge(int yy);
	virtual int Get();
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

	virtual void Chenge(int yy);
	virtual int Get();
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

	virtual void Chenge(int yy);
	virtual int Get();
	void Specific();
};
