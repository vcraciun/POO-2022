#include "Derivari.h"
#include "Shapes.h"

int main()
{
	//A a;
	B b(11);
	C c(20);
	D d(33);

	b.Chenge(7);
	c.Chenge(17);
	d.Chenge(71);

	int bb = b.Get();
	int cc = c.Get();
	int dd = d.Get();

	cout << bb << " " << cc << " " << dd << endl;

	b.Specific();
	c.Specific();
	d.Specific();

	return 0;
}

