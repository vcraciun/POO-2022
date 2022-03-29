#include "Shapes.h"

Panel::Panel(string nume, int xx, int yy, int ww, int hh, int col, bool vis)
{
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	name = nume;
	color = col;
	visible = vis;
	childs.clear();
}

Panel::~Panel()
{
	for (auto it : childs)
		delete it;
	childs.clear();
}

void Panel::Display()
{	

}

void Panel::Hide()
{
	visible = false;
}

void Panel::Reveal()
{
	visible = true;
}

void Panel::Add(Obiect* child)
{
	childs.push_back(child);
}

void Panel::Remove(Obiect* child)
{
	auto result = find(childs.begin(), childs.end(), child);
	if (result != childs.end())
		childs.erase(result);
}


