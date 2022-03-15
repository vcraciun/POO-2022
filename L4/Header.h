#pragma once
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <fstream>
using namespace std;

#pragma warning (disable:4996)

#define DEFAULT_LOG "log.txt"

struct Data0 {
	int n;
	char* m;
};

class Data1 {
public:
	int nota;
	char* nume;
	//Data1(int n, char* nn) : nota(n), nume(nn) {}
};

class Data2 {
private:
	int nota;
	char* nume;
public:
	Data2();
	Data2(int n, char* num);
	char* GetName();
	~Data2();
};

class Data3 {
private:
	int* vector;
	int pos;
public:
	Data3();
	Data3(const Data3& other);
	Data3(int size);
	~Data3();
	Data3& operator[](int index);
	Data3& operator=(int element);	
	int GetCrtValue();
};

class Log {
private:
	static Log* instance;
	Log(const char* defa);
	~Log();
	char* fname;
public:
	static Log* GetInstance(const char* def_name = DEFAULT_LOG);
	static void DestroyInstance();
	void LogLine(const char* data, ...);
};

template <class T>
class Manual {
private:
	T data;
	unsigned char* content;
public:
	Manual()
	{
		Log::GetInstance()->LogLine("Manual::Manual()\n");
		content = new unsigned char[sizeof(size_t)];
		memcpy(content, &data, sizeof(size_t));
	}
	~Manual()
	{
		Log::GetInstance()->LogLine("Manual::~Manual()\n");
		delete[] content;
		content = 0;
	}
	void Set(T element) 
	{
		Log::GetInstance()->LogLine("Manual::Set() type: [%s], value:[]\n", typeid(data).name());
		data = element; 
	}
	T Get() 
	{
		Log::GetInstance()->LogLine("Manual::Get()\n");
		return data;
	}
};

class Baza {
	int x = 0;
public:
	Baza();
	~Baza();
	void Calcul();
	int Get();
};

class Derivat : public Baza {
	int y = 0;
public:
	Derivat();
	~Derivat();
	void Calcul();
	int Get();
};

