#include "Header.h"

#define FUNCTIE_SECRETA(a,b) ((a<<b) | (a>>(8-b)))

extern void optimizare_locala();
extern void optimizare_globala();
extern void FunctieDubioasa();

void OperatoriBiti()
{
    int a = 121 & 40;
    int b = 33 ^ 91;
    char c = 'A' | ' ';
    int d = ~255 & 255;
    char e = 'a' & ~' ';
    printf("a=%d\nb=%d\nc=%c\nd=%d\ne=%c\n", a, b, c, d, e);

    int x = 1;
    int y = 2;
    if (x & y || !x)
        printf("merge");

    int w = 0;
    for (int i = 0; i < 16; i++)
        w += 1 << i;
    printf("w = %d\n", w);

    unsigned short u = 64809;
    char data[100] = { 0 };
    int start = 98;
    while (u)
    {
        data[start] = (u & 1) | 48;
        u >>= 1;
        start--;
    }
    printf("u = %s\n", data + start + 1);

    int n = FUNCTIE_SECRETA(15, 4);
    int m = ~0 & 0xFF - 15;
    printf("n = %d\nm = %d\n", n, m);
}

void Logics()
{
    int x1 = 100;
    int y1 = 100;
    int x2 = 200;
    int y2 = 200;
    int x3 = 300;
    int y3 = 100;
    int x4 = 400;
    int y4 = 200;

    int xx1 = rand() % 500;
    int yy1 = rand() % 300;

    //1 conditie cu care vrificam daca punctul (xx1, yy1) se afla sau nu in oricare din cele 2 patrulatere
    if (xx1)
        printf("se afla\n");
    else
        printf("nu se afla\n");
}

int main()
{
    Data x = { 0 };
    int f = x.f1(100, 1);
    int g = x.f2(10, 50);
    printf("f=%d\ng=%d\n", f, g);

    OperatoriBiti();
    Logics();
    optimizare_locala();
    optimizare_globala();

    Clasa2 d;
    cout << "secret = " << d.func(10) << endl;

    FunctieDubioasa();

    return 0;
}
