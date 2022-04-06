#pragma once

#include "Common.h"

#define MAX_SIZE 1

//clasele tenplate-izate se implementeaza in header

template <class T, class U>
class Dictionar 
{
private:
	//aici definim propria colectie cu care simulam dictionarul
	//tipul cheilor va fi T, iar tipul valorilor va fi U
	//exemplu: 
	T keys[MAX_SIZE];
	U vals[MAX_SIZE];
	int last;					//index ultima valoare inserata
	IndexOutOfBounds ioob;		//exceptie
	U defa;						//valoarea default pentru a putea insera elemente vide, cand cheia nu exista

public:
	Dictionar(U def_val) 
	{ 
		defa = def_val;
		last = 0; 
		for (int i = 0; i < MAX_SIZE; i++)
			vals[i] = defa;
	}
	~Dictionar() {}
	Dictionar(Dictionar& other) {}

	U& operator[](T key)
	{
		int i;		
		for (i = 0; i < last; i++)		//cautam cheia
			if (keys[i] == key)
				return vals[i];			//gasit -> returnam adresa valorii
		if (last >= MAX_SIZE)			//index inafara maximelor -> exceptie
			throw ioob;
		keys[last] = key;				//negasit -> insertie cheie/valoare
		vals[last] = defa;
		return vals[last++];
	}
};

