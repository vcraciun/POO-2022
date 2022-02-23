#include <stdio.h>

struct fruct_vtable {
    const char* (*gust)();
    const char* (*culoare)();
};

struct fruct {
    fruct_vtable methods;
    const char* name;
    double aciditate;
};

const char* dulce () {
    return "dulce";
}

const char* acru() {
    return "acru";
}

const char* iute() {
    return "iute";
}

const char* amar() {
    return "amar";
}
//-----------------------

//-----------------------
const char* galben() {
    return "galben";
}

const char* rosu() {
    return "rosu";
}

const char* verde() {
    return "verde";
}
//-----------------------

void describe(fruct* data) {
    printf("%s are gust \"%s\", culoare \"%s\" si aciditate %.3lf\n", data->name, data->methods.gust(), data->methods.culoare(), data->aciditate);
}

fruct tabel[] = {
    { {&acru, &galben}, "lamaie", 3.3 },
    { {&dulce, &rosu}, "cireasa", 4 },
    { {&iute, &verde}, "ardei", 3 },
    { {&amar, &verde}, "pelin", 8 }
};

int main() {
     for (int i = 0; i < 4; i++)
        describe(&tabel[i]);
    return 0;
}


