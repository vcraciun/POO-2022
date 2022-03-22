#include "Complex.h"
#include "Colectie.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Parametri insuficienti!!!" << endl;
        return 0;
    }

    if (!strcmp(argv[1], "first"))
    {
        cout << "Objects" << endl;
        Complex x(6, 10);
        Complex y;
        Complex q(1, 1);
        cout << endl << "Expresie" << endl;
        y = x + q;
        y.Print();
        y = x * q;
        y.Print();
        y += {12, 20};
        y += 10;
        y += x;
        y = y - q;
        y.Print();
    }
    else 
        if (!strcmp(argv[1], "second"))
        {
            ColectieComplex col;
            col.GenerateRandomFile("fisier.bin");
        }
        else
            if (!strcmp(argv[1], "third"))
            {
                ColectieComplex col("fisier.bin");
                col.PrintAll();
                col.PrintSameSize(6);
                vector<Complex> vect = col.SearchVector("maqjrs");
                for (auto it : vect)
                    it.Print();
                Complex suma = col.OperatieVector("maqjrs", ColectieComplex::SumaVector);
                Complex produs = col.OperatieVector("maqjrs", ColectieComplex::ProdusVector);
                suma.Print();
                produs.Print();
            }

    return 0;
}

