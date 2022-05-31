
enum tipuri {
    PATRAT,
    CERC,
    DREPTUNGHI
};
vector<int> params = {
    5, 8, 65536 * 3 + 11, 
    9,21, 65536 * 15+ 40,
   31,44, 65536 * 7 + 17,
   16,29, 65536 * 9 + 22,
   12,19, 65536 * 8 + 4,
    7,18, 65536 * 21+12,
   24,24, 65536 * 19+16,
   51,14, 65536 * 32+23,
   39,22, 65536 * 72+49,
   44,64, 65536 * 55+10  
};

int main(void)
{
    ShapeFactory factory;
    Colectie shapes;
    
    for (int i = 0; i < params.size(); i++)
        shapes.Add(factory.CreateShape(i % 3, params[i]));
    
    for (auto it : shapes)
        cout << it->GetName() << " Perimetru:" << it->Perimetru() << " Arie: " << it->Aria() << endl;

    vector<Shape*> patrate = shapes.Filter(PATRAT);
    for (auto it : patrate)
        cout << it->GetName() << endl;
    
    return 0;
}

