#include "Colectie.h"

ColectieComplex::ColectieComplex()
{
	cout << "ColectieComplex::ColectieComplex()" << endl;
	data.clear();
}

ColectieComplex::ColectieComplex(string fname)
{
	ifstream fin(fname);
	int nr_vectors;
	fin >> nr_vectors;
	for (int i = 0; i < nr_vectors; i++)
	{
		string name_vector;
		fin >> name_vector;
		int elemente;
		fin >> elemente;
		for (int j = 0; j < elemente; j++)
		{
			int re;
			int im;
			fin >> re;
			fin >> im;
			data[name_vector].push_back({re, im});
		}
	}
	fin.close();
}

ColectieComplex::~ColectieComplex()
{
	cout << "ColectieComplex::ColectieComplex()" << endl;
	data.clear();
}

void ColectieComplex::PrintAll()
{
	for (auto it : data)
	{
		cout << it.first << ": ";
		for (auto it2 : it.second)
			cout << "(" << it2.first << "," << it2.second << ") ";
		cout << endl;
	}
}

Complex ColectieComplex::OperatieVector(string nume_vector, OperatorVector callback)
{
	if (data.find(nume_vector) != data.end())
		return callback(this, nume_vector);
	cout << "Vectorul nu exista!!!" << endl;
}

void ColectieComplex::PrintSameSize(int size)
{
	for (auto it : data)
	{
		if (it.second.size() == size)
			cout << it.first << endl;
	}
}

string ColectieComplex::BuildVectorName()
{
	string result = "";
	int count = rand() % 8 + 5;
	for (int i = 0; i < count; i++)
		result += 'a' + rand() % 26;
	return result;
}

void ColectieComplex::GenerateRandomFile(string fname)
{
	ofstream fout(fname);
	set<string> unique_names;
	string name_vector;
	srand(time(0));

	int nr_vectors = rand() % 20 + 5;
	fout << nr_vectors << endl;
	for (int i = 0; i < nr_vectors; i++)
	{
		do {
			name_vector = BuildVectorName();
		} while (unique_names.find(name_vector) != unique_names.end());
		unique_names.insert(name_vector);
		fout << name_vector << " ";
		int elemente = rand() % 10 + 2;
		fout << elemente << " ";
		for (int j = 0; j < elemente; j++)
		{
			int re = rand() % 50;
			int im = rand() % 50;
			fout << re << " " << im << " ";
		}
		fout << endl;
	}
	fout.close();
}

vector<Complex> ColectieComplex::SearchVector(string name)
{
	vector<Complex> result;

	if (data.find(name) != data.end())
	{
		for (auto it : data[name])
			result.push_back(Complex(it.first, it.second));
	}

	return result;
}

