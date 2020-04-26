#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Header.h"
#include "Description.h"
#include "Product.h"
#include "CPU.h"
using namespace std;
int menu(string menus[], int size);
template<typename T>
int menu(T* product, int size);
int main()
{

	//for (int i = 0; i < 2; i++)
	//{
	//	CPUs[i].Show();
	//} 
	//string name = "good";
	//Description des[] = { {Description("CPU","3,4")},{Description("GPU","8GB")} };
	//Product PC = Product("My PC", 20000, 1, des);

	CONSOLE_INFO();
	Size_Console(45, 35);
	string menu_items[] = { "CPU","GPU","HDD","SSD" };
	int answer = menu(menu_items, 4);
	switch (answer)
	{
	case 0: {
		CPU* CPUs = new CPU[2]{ CPU("AMD Ryzen 5",5600,2,"Socket AM4",6,3.6,12),
			CPU("Intel Core i5-8600K",9760,5,"Socket 1151",6,3.6,6) };
		menu(CPUs, 2);
	}
	case 1: cout << "2" << endl; break;
	case 2: cout << "3" << endl; break;
	case 3: cout << "4" << endl; return 0;
	}
	system("pause");
	return 0;
}
template<typename T>
int menu(T* product, int size)
{
	int key = 0;
	int code;
	do {
		system("cls");

		key = (key + size) % size;

		for (int i = 0; i < size; i++)
		{
			if (key == i)
			{

				SetColor(6);  product[i].Show(); SetColor(3); SetColor(15);
			}
			else
			{
				product[i].Show();
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