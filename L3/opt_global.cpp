#include <stdio.h>

int f0(int a) { return 451 + a; }
int f1(int a) { return 329 - a; }
int f2(int a) { return a * 10; }
int f3(int a) { return a + a; }
int f4(int a) { return a - 55; }
int f5(int a) { return a / 2; }
int f6(int a) { return a * 7; }
int f7(int a) { return a * a; }
int f8(int a) { return 100 / a; }
int f9(int a) { return 777 - a; }

typedef int (*func)(int, int);
int _mul(int a, int b) { return a * b; }
int _add(int a, int b) { return a + b; }
int _sub(int a, int b) { return a - b; }
int _div(int a, int b) { return a / b; }

void Update(int result, int& first, int* second, int i)
{
    switch (i)
    {
    case 0: first = result; second[0] = result; break;
    case 1: first = 777; second[0] = 3 + result; break;
    case 2: first = 329; second[0] = result - 1; break;
    case 3: first = result * 2; second[0] = 2; break;
    case 4: first = result; second[0] = result; break;
    case 5: first = 451; second[0] = result / 2; break;
    case 6: first = result; second[0] = 10; break;
    case 7: first = 100; second[0] = result; break;
    case 8: first = result * result; second[0] = 55; break;
    case 9: first = result + result; second[0] = 7; break;
    }
}

void optimizare_globala()
{
    int result = 0;
    int first, second;

    result = f7(30);
    result = f9(3 + result);
    result = f1(result - 1);
    result = f5(result * 2);
    result = f3(result);
    result = f0(result / 2);
    result = f2(result);
    result = f8(result);
    result = f4(result * result);
    result = f6(result + result);
    printf("result = %d\n", result);

    //-------------------------------------
    //minimizati codul de mai sus, folosind o forma de programare functionala

    //-------------------------------------
    //minimizati codul de mai sus folosind array-uri
}

