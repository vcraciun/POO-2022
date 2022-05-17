void Display(vector<int> data)
{
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, 0x07, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    
    SetConsoleTextAttribute(console, 0x0E); 

    int index = 0;
    int last = 0;
    for (auto it : data)
    {       
        if (!index || last == it)
        {
            SetConsoleCursorPosition(console, { (short)index, (short)(25 - it) });
            printf("%c", 178);
        }
        else
        {
            if (it > last)
            {
                for (int i = last + 1; i <= it; i++)
                {
                    SetConsoleCursorPosition(console, { (short)index, (short)(25 - i) });
                    printf("%c", 178);
                }
            }
            else
            {
                for (int i = it + 1; i <= last; i++)
                {
                    SetConsoleCursorPosition(console, { (short)index, (short)(25 - i) });
                    printf("%c", 178);
                }
            }
        }
        last = it;
        index++;
    }

    SetConsoleCursorPosition(console, { 0, 30 });
}

