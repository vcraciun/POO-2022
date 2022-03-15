#include "Header.h"

Baza::Baza()
{
	Log::GetInstance()->LogLine("Baza::Baza()\n");
	x = 100;
}

Baza::~Baza()
{
	Log::GetInstance()->LogLine("Baza::~Baza()\n");
	x = 0;
}

void Baza::Calcul()
{
	Log::GetInstance()->LogLine("Baza::Calcul()\n");
	x = x * 10;
}

int Baza::Get()
{
	Log::GetInstance()->LogLine("Baza::Get()\n");
	return x;
}

//--------------------------------

Derivat::Derivat()
{
	Log::GetInstance()->LogLine("Derivat::Derivat()\n");
	y = 15;
}

Derivat::~Derivat()
{
	Log::GetInstance()->LogLine("Derivat::~Derivat()\n");
	y = 0;
}

void Derivat::Calcul()
{
	Log::GetInstance()->LogLine("Derivat::Calcul()\n");
	y = y + 50;
}

int Derivat::Get()
{
	Log::GetInstance()->LogLine("Derivat::Get()\n");
	return y;
}
