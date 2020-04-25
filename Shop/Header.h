
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>

using namespace std;


void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}
void SetColor_Background(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { 0, 0, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}void InvisibleÑursor(bool $CCI)
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = $CCI;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
void CONSOLE_INFO()
{
	HANDLE  hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD  size{ 80,25 };
	SetConsoleScreenBufferSize(hout, size);
	CONSOLE_FONT_INFOEX cfi; //https://docs.microsoft.com/en-us/windows/console/console-font-infoex
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	cfi.nFont = 5;
	cfi.dwFontSize.X = 10;
	cfi.dwFontSize.Y = 18;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;//400;
	wcscpy_s(cfi.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(hout, true, &cfi);

	InvisibleÑursor(FALSE);
}

