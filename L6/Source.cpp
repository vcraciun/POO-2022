#include "Derivari.h"
#include "Shapes.h"

int main()
{
	//A a;
	B b(11);
	C c(20);
	D d(33);

	b.Change(7);
	c.Change(17);
	d.Change(71);

	b.Print();
	c.Print();
	d.Print();

	b.Specific();
	c.Specific();
	d.Specific();

	d.B::A::Change(17);
	d.C::A::Change(99);

	static_cast<A&>(b).Specific();
	((A&)b).Specific();

	//creare obiecte
	Obiect* f = new Panel("Main - Window", 10, 5, 80, 20, 0x70, true);
	Obiect* p1 = new Panel("Panel-1", 3, 2, 40, 12, 0xe8, true);
	Obiect* p2 = new Panel("Panel-2", 48, 3, 25, 15, 0x6f, true);
	Obiect* p3 = new Panel("Panel-1-1", 23, 2, 15, 8, 0x8f, true);
	Obiect* l1 = new Label("Label Text  1", 4, 4, 0x4f, true);
	Obiect* b1 = new Button("OK", 3, 3, 10, 0x1f, true);
	Obiect* b2 = new Button("Cancel", 3, 5, 10, 0x1f, true);
	Obiect* b3 = new Button("Ignore", 3, 7, 10, 0x1f, true);
	Obiect* b4 = new Button("Submit", 3, 2, 8, 0x1f, true);
	Obiect* l2 = new Label("Element", 2, 4, 0x1e, true);
	Obiect* b5 = new Button("Open", 3, 10, 10, 0xaf, true);
	Obiect* b6 = new Button("Exit", 3, 12, 10, 0xcf, true);
	
	//rezolvare dependinte
	f->Add(p1);
	f->Add(p2);
	p1->Add(p3);
	p1->Add(b1);
	p1->Add(b2);
	p1->Add(b3);
	p2->Add(l1);
	p2->Add(b5);
	p2->Add(b6);
	p3->Add(b4);
	p3->Add(l2);

	//afisare Obiect radacina
	f->Display();

	//modificare vizibilitate
	Sleep(2000);
	p2->Hide();
	f->Display();

	Sleep(2000);
	p3->Hide();
	f->Display();

	Sleep(2000);
	b2->Hide();
	f->Display();

	Sleep(2000);
	p2->Reveal();
	p3->Reveal();
	b2->Reveal();
	f->Display();

	delete f;

	return 0;
}

