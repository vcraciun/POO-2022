#include <stdio.h>

typedef void (*func)(int, int);

struct Data1 {
    int a;
    int b;
    void f1() {
        printf("abc");
    }
    int f2(int a, int b) {
        return a + b;
    }
};

struct Data2 {
    int a;
    int b;
};

struct Data3 {
    double f1;
    double f2;
};

struct Data4 {
    char x;
    char y[4];
    short z[2];
};

int main() {
    char* data[5] = { 0 };
    float x = 1.0;
    float p[2] = { 0 };
    unsigned int* q = (unsigned int*)&x;

    printf("%d %d %d %d %d %d %d %d\n", sizeof(Data1), sizeof(Data2), sizeof(Data3), sizeof(Data4), sizeof(func), sizeof(data), sizeof(x), sizeof(p), sizeof(q));
    return 0;
}
