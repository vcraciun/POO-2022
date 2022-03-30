#pragma once

#include "Common.h"

struct POS
{
	short x;
	short y;
	short w;
	short h;
};

class Obiect
{
protected:
	POS coord;
	Obiect* parent;
	string name;
	vector<Obiect*> childs;
	bool visible;
public:
	virtual void Display() = 0;
	virtual void Add(Obiect* child) { 
		child->SetParent(this);
		child->coord.x += coord.x;
		child->coord.y += coord.y;
		childs.push_back(child); 
	}
	virtual void Remove(Obiect* child);
	virtual void Hide() { visible = false; }
	virtual void Reveal() { visible = true; }
	virtual void SetParent(Obiect* par) { parent = par; }

	int color;
};

class Panel : public Obiect
{
public:
	Panel(string nume, short xx, short yy, short ww, short hh, int color, bool visible);
	~Panel();

	virtual void Display();
};

class Label: public Obiect
{
public:
	Label(string nume, short xx, short yy, int color, bool visible);
	~Label();

	virtual void Display();
};

class Button : public Obiect
{
public:
	Button(string nume, short xx, short yy, short ww, int color, bool visible);
	~Button();

	virtual void Display();
};
