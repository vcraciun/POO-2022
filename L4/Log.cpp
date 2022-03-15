#include "Header.h"

Log* Log::instance = 0;

Log::Log(const char* defa)
{
	cout << "Log::Log()" << endl;
	fname = new char[strlen(defa) + 1];
	strcpy(fname, defa);
	unlink(fname);
}

Log::~Log()
{
	cout << "Log::~Log()" << endl;
	delete[] fname;
	fname = 0;
}

Log* Log::GetInstance(const char* def_name)
{
	if (!instance)
		instance = new Log(def_name);
	return instance;
}

void Log::DestroyInstance()
{
	delete instance;
	instance = 0;
}

void Log::LogLine(const char* data, ...)
{
	char dest[1024];
	va_list argptr;
	va_start(argptr, data);
	vsprintf(dest, data, argptr);
	va_end(argptr);
	fstream fout;
	fout.open(fname, fstream::out | fstream::app);
	fout << dest;
	fout.close();
}

