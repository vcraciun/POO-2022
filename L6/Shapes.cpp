#include "Shapes.h"

void Obiect::Remove(Obiect* child)
{
	auto result = find(childs.begin(), childs.end(), child);
	if (result != childs.end())
		childs.erase(result);
}
//----------------------------------------------------------------------

Panel::Panel(string nume, short xx, short yy, short ww, short hh, int col, bool vis)
{
	coord = { xx, yy, ww, hh };
	name = nume;
	color = col;
	visible = vis;
	parent = { 0 };
	childs.clear();
}

Panel::~Panel()
{
	for (auto it : childs)
		delete it;
	childs.clear();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
}

void Panel::Display()
{
	char buffer[1000] = { 0 };

	if (!visible)
		return;

	short xx = coord.x + 1;
	short yy = coord.y + 1;
	short ww = coord.w;
	short hh = coord.h;

	memset(buffer, ' ', ww);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (short i = 0; i < hh; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx ,yy + i });
		printf("%s", buffer);
	}
	short len = (short)name.size();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww / 2 - len / 2,yy });
	printf("%s", name.c_str());

	//top left
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + 1,yy });
	for (int i = 0; i < ww / 2 - len / 2 - 2; i++)
		printf("%c", 205);
	printf("%c", 185);
	//top right
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww / 2 + len / 2 + 1,yy });
	printf("%c", 204);
	for (int i = 0; i < ww / 2 - len / 2 - 2; i++)
		printf("%c", 205);
	//bottom
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + 1,yy + hh - 1 });
	for (int i = 0; i < ww - 2; i++)
		printf("%c", 205);
	//left
	for (short i = 1; i < hh - 1; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx,yy + i });
		printf("%c", 186);
	}
	//right
	for (short i = 1; i < hh - 1; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww - 1,yy + i });
		printf("%c", 186);
	}

	//corners
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx,yy });
	printf("%c", 201);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww - 1,yy });
	printf("%c", 187);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx,yy + hh - 1 });
	printf("%c", 200);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww - 1,yy + hh - 1 });
	printf("%c", 188);


	for (auto it : childs)
		it->Display();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
}
//----------------------------------------------------------------------

Label::Label(string nume, short xx, short yy, int col, bool vis)
{
	coord = { xx, yy, (short)(nume.size() + 4), 3};
	name = nume;
	color = col;
	visible = vis;
	childs.clear();
}

Label::~Label()
{
	for (auto it : childs)
		delete it;
	childs.clear();
}

void Label::Display()
{
	char buffer[1000] = { 0 };

	if (!visible)
		return;

	short xx = coord.x + 1;
	short yy = coord.y + 1;
	short ww = coord.w;
	short hh = coord.h;

	memset(buffer, ' ', ww);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	
	for (short i = 0; i < 3; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx, yy + i});
		printf("%s", buffer);
	}

	short len = (short)name.size();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww / 2 - len / 2,yy + 1 });
	printf("%s", name.c_str());

	//top
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + 1,yy });
	for (int i = 0; i < ww - 2; i++)
		printf("%c", 196);
	//bottom
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + 1,yy + hh - 1 });
	for (int i = 0; i < ww - 2; i++)
		printf("%c", 196);

	//margins
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx,yy + 1 });
	printf("%c", 179);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww - 1, yy + 1 });
	printf("%c", 179);

	//corners
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx,yy });
	printf("%c", 218);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww - 1,yy });
	printf("%c", 191);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx,yy + hh - 1 });
	printf("%c", 192);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww - 1,yy + hh - 1 });
	printf("%c", 217);

	for (auto it : childs)
		it->Display();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
}
//----------------------------------------------------------------

Button::Button(string nume, short xx, short yy, short ww, int col, bool vis)
{
	coord = { xx, yy, ww, 3 };
	name = nume;
	color = col;
	visible = vis;
	childs.clear();
}

Button::~Button()
{
	for (auto it : childs)
		delete it;
	childs.clear();
}

void Button::Display()
{
	char buffer[1000] = { 0 };

	if (!visible)
		return;

	short xx = coord.x + 1;
	short yy = coord.y + 1;
	short ww = coord.w;
	short hh = coord.h;

	memset(buffer, ' ', ww);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx, yy });
	printf("%s", buffer);

	short len = (short)name.size();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww / 2 - len / 2,yy });
	printf("%s", name.c_str());

	//shadow
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), parent->color & 0xF0);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + 1, yy + 1 });
	for (short i = 0; i < ww; i++)
		printf("%c", 223);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { xx + ww, yy });
	printf("%c", 220);

	for (auto it : childs)
		it->Display();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
}
