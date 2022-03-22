#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;


class Complex 
{
private:
	int real;
	int imaginar;

public:
	Complex();
	Complex(int re, int im);
	~Complex();

	void Print();
	
};

