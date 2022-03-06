#pragma once

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;

#pragma warning (disable:4996)

typedef int (*pf1)(int, int);
typedef int (*pf2)(int, int);
typedef int (*pfs1)(void*, int);
typedef void (*pfs2)();
extern int main();

//--------------------------------------------------
struct Data {
	int a;
	int b;
	int f1(char a, char b);
	int f2(char a, char b);
};

class Clasa {
	char a;
	char* b;

	static int secret1(Clasa* inst, int a);
	void secret2();

public:
	Clasa();
	Clasa(char _a, const char* _b);
	~Clasa();	

protected:
	int f1(int x);
	int shared;
};

class Clasa2 : public Clasa {
public:
	Clasa2();
	~Clasa2();
	int func(int x);
};

