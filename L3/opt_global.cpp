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

