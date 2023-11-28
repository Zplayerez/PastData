#include<windows.h>
#include<conio.h>
int main()
{
    char c;
    for (; (c = _getch()) != 'q'; Beep(c * 20, 300));
    return 0;
}