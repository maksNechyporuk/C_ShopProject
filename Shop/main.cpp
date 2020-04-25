#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Header.h"
#include "Description.h"
#include "Product.h"
using namespace std;
int menu(string menus[], int size);

int main()
{
	//string name = "good";
	//Description des[] = { {Description("CPU","3,4")},{Description("GPU","8GB")} };
	//Product PC = Product("My PC", 20000, 1, des);


	CONSOLE_INFO();
	Size_Console(45, 35);
	string menu_items[] = { "CPU","GPU","HDD","SSD" };
	int answer = menu(menu_items, 4);
	switch (answer)
	{
	case 0: cout << "1" << endl; break;
	case 1: cout << "2" << endl; break;
	case 2: cout << "3" << endl; break;
	case 3: cout << "4" << endl; return 0;
	}
	system("pause");
	return 0;
}

int menu(string menu_items[], int size) {
	int key = 0;
	int code;
	do {
		system("cls");
		SetPos(4, 0);
		cout << "***************************************\n";
		SetPos(4, 1);

		cout << "*                SHOP                 *\n";
		SetPos(4, 2);

		cout << "***************************************\n";
		key = (key + size) % size;
		for (int i = 0; i < size; i++)
		{
			SetPos(20, 5 + i);
			if (key == i)
			{

				cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}

		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}