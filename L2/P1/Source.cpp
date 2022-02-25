#include <stdio.h>
#include "Header1.h"
#include "Header2.h"
#include <intrin.h>

int main();

void hackprotection()
{
	unsigned char* main_addr = (unsigned char*)&main;
	unsigned long oldp;

	//METHOD 1
	MEMORY_BASIC_INFORMATION pmem;
	for (int i = 0; ; i++)
	{
		__try {
			int my_static_var = *(int*)(main_addr + i);
			if (my_static_var == 1010101)
			{
				VirtualQuery(main_addr + i, &pmem, sizeof(pmem));
				if (pmem.Protect != PAGE_EXECUTE_READ && pmem.Protect != PAGE_EXECUTE_READWRITE)
				{
					VirtualProtect(main_addr + i, sizeof(size_t), PAGE_READWRITE, &oldp);
					*(int*)(main_addr + i) = 100;
					VirtualProtect(main_addr + i, sizeof(size_t), oldp, &oldp);
					printf("HACKED\n");
					break;
				}
			}
		}
		__except(EXCEPTION_EXECUTE_HANDLER) {
			printf("Oooops, am gresit ceva?\n");
		}
	}
}

int myprotectedvar(int p)
{
	static int q = 1010101;
	return p + q;
}

int main()
{
	int a = FunctiePubica1(10, 7);
	int b = FunctiePubica2(10, 7);
	printf("a=%d\nb=%d\n", a, b);
	//-----------------------------------
	int r1 = myprotectedvar(1);
	int r2 = myprotectedvar(1);
	hackprotection();
	int r3 = myprotectedvar(1);
	printf("r1 = %d, r2 = %d, r3 = %d\n", r1, r2, r3);
	if (r3 != r1 && r1 == r2)
		printf("Variabila statica tocmai a fost compromisa :D\n");
	//-----------------------------------
	//char x[2000000];
	//memset(x, 0, 2000000);
	//printf("x=%X", x);
	//-----------------------------------
	char* y = (char*)malloc(2000000);
	memset(y, 1, 2000000);
	int q = *(int*)(y + 10);
	int* t = (int*)(y + 8);
	long long p = *(long long*)t;
	printf("y=%X", y);
	printf("q = %08X, t = %08X, p = %llx\n", q, t, p);
	//-----------------------------------
	__try {
		int x = 0;
		int y = *(int*)x;
		printf("y = %d\n", y);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		printf("Exceptie\n");
	}
	//-----------------------------------
	while (p)
		;

	return 0;
}

