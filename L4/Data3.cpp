#include "Header.h"

Data3::Data3()
{
	Log::GetInstance()->LogLine("Data3::Data3()\n");
	vector = 0;
	pos = 0;
}

Data3::Data3(const Data3& other)
{
	Log::GetInstance()->LogLine("Data3::Data3(const Data3&)\n");
	this->vector = other.vector;
	this->pos = other.pos;
}

Data3::Data3(int size)
{
	Log::GetInstance()->LogLine("Data3::Data3(int)\n");
	vector = new int[size];
	memset(vector, 0, size * sizeof(int));
	pos = 0;
}

Data3::~Data3()
{
	Log::GetInstance()->LogLine("Data3::~Data3()\n");
	delete[]vector;
	vector = 0;
	pos = 0;
}

Data3& Data3::operator[](int index)
{
	Log::GetInstance()->LogLine("Data3::operator[]()\n");
	pos = index;
	return *this;
}

Data3& Data3::operator=(int element)
{
	Log::GetInstance()->LogLine("Data3::operator=()\n");
	vector[pos] = element;
	return *this;
}

int Data3::GetCrtValue()
{
	Log::GetInstance()->LogLine("Data3::GetCrtValue()\n");
	return vector[pos];
}
