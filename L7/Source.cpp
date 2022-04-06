#include "Dictionar.h"

int main() {
    //------------------------- short Demo Dictionar pe baza de template -------------------
    Dictionar<string, int> d(0);
    int q;
    d["abc"] = 100;
    try {
        q = d["abc"];
        cout << q << endl;
        q = d["xyz"];
        cout << q << endl;
    }
    catch (exception& e) {
        std::cout << e.what() << std::endl;
    }
    //----------------------------------------------------------------------------------------



    //------------------------ short demo utilizare random + masurare performanta + STL map ------------
    LARGE_INTEGER start, stop, frecventa;
    double timp;
    QueryPerformanceFrequency(&frecventa);
    QueryPerformanceCounter(&start);
    map<int, char> dictionar;
    int total = 0;
    while (dictionar.size() < 1000000)
    {
        int key = (int)__rdtsc();
        char val = (char)__rdtsc();;
        dictionar[key] = val;
    }
    QueryPerformanceCounter(&stop);
    timp = (double)(stop.QuadPart - start.QuadPart) / frecventa.QuadPart;
    cout << "Executia a durat: [" << timp << "] secunde" << endl;
    //----------------------------------------------------------------------------------------


    //completati problema astfel incat la final sa vedem o diferenta de performanta intre operatiile cautare/inserare dictionar
    //intre map si colectia definita de voi
    //dat fiind ca Dictionarul este template-izat, folositi 2 situatii diferite pentru tipurile de date key/val
}

