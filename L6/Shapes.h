#pragma once

#include "Common.h"

class Obiect
{
protected:
	int x;
	int y;
	int w;
	int h;
	int color;
	string name;
	vector<Obiect*> childs;
	bool visible;
public:
	virtual void Display() = 0;
	virtual void Add(Obiect* child) = 0;
	virtual void Remove(Obiect* child) = 0;
};

class Panel : public Obiect
{
public:
	Panel(string nume, int xx, int yy, int ww, int hh, int color, bool visible);
	~Panel();

	virtual void Display() = 0;
	virtual void Add(Obiect* child) = 0;
	virtual void Remove(Obiect* child) = 0;
	virtual void Hide() = 0;
	virtual void Reveal() = 0;
};

class Label: public Obiect
{
public:
	Label(string nume, int xx, int yy, int ww, int hh, int color, bool visible);
	~Label();

	virtual void Display() = 0;
	virtual void Add(Obiect* child) = 0;
	virtual void Remove(Obiect* child) = 0;
	virtual void Hide();
	virtual void Reveal();
};

class Button : public Obiect
{
public:
	Button(string nume, int xx, int yy, int ww, int hh, int color, bool visible);
	~Button();

	virtual void Display() = 0;
	virtual void Add(Obiect* child) = 0;
	virtual void Remove(Obiect* child) = 0;
	virtual void Hide();
	virtual void Reveal();
};
