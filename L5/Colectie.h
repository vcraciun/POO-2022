#pragma once

#include "Complex.h"

class ColectieComplex;
typedef Complex(*OperatorVector)(ColectieComplex*, string);

class ColectieComplex 
{
private:
	map<string, vector<pair<int, int>>> data;
	string BuildVectorName();
public:
	ColectieComplex();
	ColectieComplex(string fname);
	~ColectieComplex();

	void PrintAll();
	Complex OperatieVector(string nume_vector, OperatorVector callback);
	void PrintSameSize(int size);
	void GenerateRandomFile(string fname);
	vector<Complex> SearchVector(string name);

	static Complex SumaVector(ColectieComplex* ref, string name);
	static Complex ProdusVector(ColectieComplex* ref, string name);
};

