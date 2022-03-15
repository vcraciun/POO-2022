#include "Header.h"

void functie_pentru_Data2(Data2** d2)
{
	char nume[] = "Alexandru cel Mare";
	d2[0] = new Data2(8, nume);
}

Data2 functie2_pentru_Data2()
{
	char student[] = "Octavian";
	Data2 d2 = { 10, student };
	return d2;
}

int functie_oarecare()
{
	int x[4] = { 0 };
	for (int i = 0; i < 100; i++)
		x[i % 4] += 1 << i;
	return x[0] + x[1] + x[2] + x[3];
}

int main()
{
	Log* instance = Log::GetInstance();

	//--------------------------------------------
	instance->LogLine("Primul Exemplu:\n");
	char student[] = "Mircea";
	int fake_inst[2] = { 6, (int)student };
	Data0 y = { 6, student };
	Data1 x = { 6, student };

	//--------------------------------------------
	instance->LogLine("Al 2-lea Exemplu:\n");
	Data2* d = 0;
	functie_pentru_Data2(&d);
	int t = functie_oarecare();
	instance->LogLine("t = %d\n", t);
	instance->LogLine("name = %s\n", d->GetName());
	delete d;	
	Data2 d2 = functie2_pentru_Data2();
	t = functie_oarecare();
	instance->LogLine("t = %d\n", t);
	instance->LogLine("name = %s\n", d2.GetName());

	//--------------------------------------------
	instance->LogLine("Al 3-lea Exemplu:\n");
	Data3 d3(10);
	d3[0] = 15;
	d3[1] = 100;
	d3[2] = 10;
	d3[9] = 41;
	Data3 d4 = d3[2];
	instance->LogLine("crt value = %d\n", d4.GetCrtValue());

	//---------------------------------------------
	instance->LogLine("Al 4-lea Exemplu:\n");
	Manual<int> m1;
	m1.Set(100);
	instance->LogLine("m1=%d\n", m1.Get());
	Manual<char> m2;
	m2.Set('A');
	instance->LogLine("m2=%c\n", m2.Get());
	Manual<double> m3;
	m3.Set(41.67544);
	instance->LogLine("m3=%.3lf\n", m3.Get());
	Manual<string> m4;
	m4.Set("Hello POO");
	instance->LogLine("m4=%s\n", m4.Get().c_str());
	Manual<int>* mm = 0;
	mm = (Manual<int>*)malloc(sizeof(Manual<int>));	
	mm->Set(333);
	instance->LogLine("mm=%d\n", mm->Get());
	free(mm);

	//--------------------------------------------
	Derivat der;
	der.Calcul();
	instance->LogLine("calcul = %d\n", der.Get());

	Baza* baz = new Derivat();
	baz->Calcul();
	instance->LogLine("calcul derivat = %d\n", baz->Get());
	delete baz;


	//---------------------------------------------
	//Log::DestroyInstance();

	return 0;
}