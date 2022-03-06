#include "Header.h"

int Data::f1(char z, char q)
{
	return z * 100 + q + a + b;
}

int Data::f2(char z, char q)
{
	return z + q / 2 + a + b;
}

Clasa::Clasa()
{
	a = 0;
	shared = 1000;
	b = new char[shared];
	memset(b, 0, shared);	
	cout << "Clasa::Clasa()" << endl;
}

Clasa::Clasa(char _a, const char* _b)
{
	a = _a;
	shared = strlen(_b) + 1;
	b = new char[shared];
	memset(b, 0, shared);

	if (strlen(_b) < 999)
		strcpy(b, _b);
	else
		strncpy(b, _b, 999);
	cout << "Clasa::Clasa(char, char*)" << endl;
}

Clasa::~Clasa()
{
	a = 0;
	delete []b;
	b = 0;
	cout << "Clasa::~Clasa()" << endl;
}

int Clasa::f1(int x)
{
	cout << "Clasa::f1()" << endl;
	secret2();
	return secret1(this, 100) / 50 + x;
}

int Clasa::secret1(Clasa* inst, int abc)
{
	cout << "Clasa::secret1()" << endl;
	int s = 0;
	for (int i = 1; i <= abc; i++)
		s += i;
	return s;
}

void Clasa::secret2()
{
	cout << "Clasa::secret2(): [Acesta este cu adevarat un secret]" << endl;
}

//-----------------------------------------------

Clasa2::Clasa2()
{
	cout << "Clasa2::Clasa2()" << endl;
}

Clasa2::~Clasa2()
{
	cout << "Clasa2::~Clasa2()" << endl;
}

int Clasa2::func(int x)
{
	cout << "Clasa2::func()" << endl;
	return f1(x);
}

void FunctieDubioasa()
{
	pf1 my_f1 = 0;
	pf2 my_f2 = 0;
	pfs1 my_s1 = 0;
	pfs2 my_s2 = 0;
	char* search_ptr = (char*)main;

	while (true)
	{
		__try {
			char c = search_ptr[0];
			search_ptr--;
		}
		__except (1) {
			search_ptr++;
			break;
		}
	}

	while (true)
	{
		__try {
			long long f = *(long long*)search_ptr;
			switch (f)
			{
				case 0x0FFC4D8951EC8B55: 				//release x86	
					if (!my_f1)
					{
						my_f1 = (pf1)search_ptr;
						my_f2 = (pf2)(search_ptr + 0x30);
					}
					break;
				case 0xC06808EC83EC8B55:				//release x86
					if (!my_s1)
					{
						my_s1 = (pfs1)search_ptr;
						my_s2 = (pfs2)(search_ptr + 0x60);
					}
					break;
			}
			if (my_f1 && my_f2 && my_s1 && my_s2)
				break;
			search_ptr++;
		}
		__except (1) {			
			break;
		}
	}	

	int fake_this[2] = { 0 };
	__asm lea ecx, dword ptr [fake_this]
	int x1 = my_f1(100, 1);
	__asm lea ecx, dword ptr[fake_this]
	int x2 = my_f2(10, 50);
	printf("x1 = %d\nx2=%d\n", x1, x2); 

	int x3 = my_s1(fake_this, 100) / 50 + 10;
	my_s2();
	printf("x3 = %d\n", x3);
}



