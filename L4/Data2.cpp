#include "Header.h"

Data2::Data2()
{
	Log::GetInstance()->LogLine("Data2::Data2()\n");
	nota = 0;
	nume = 0;
}

Data2::Data2(int n, char* num)
{
	Log::GetInstance()->LogLine("Data2::Data2(n, num)\n");
	nota = n;	
	nume = num;
}

Data2::~Data2()
{
	Log::GetInstance()->LogLine("Data2::~Data2()\n");
}

char* Data2::GetName()
{
	Log::GetInstance()->LogLine("Data2::~GetName()\n");
	return nume;
}
