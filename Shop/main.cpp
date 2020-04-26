#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Header.h"
#include "Description.h"
#include "Product.h"
#include "CPU.h"
using namespace std;
int CPU_size = 2;
int menu(string menus[], int size);
template<typename T>
int menu(T* product, int size);
void CPUMenu();
template<typename T>
int GetSize(T items[]);
template<typename T>
void Buy(T& item);
int main()
{
	CONSOLE_INFO();
	Size_Console(45, 35);
	bool work = true;
	do {
		string menu_items[] = { "CPU","GPU","HDD","SSD","EXIT" };
		int answer = menu(menu_items, 5);
		switch (answer)
		{
		case 0: {
			CPUMenu();
		}
		case 1: cout << "2" << endl; break;
		case 2: cout << "3" << endl; break;
		case 3: cout << "4" << endl; break;
		case 4: work = false; break;

		}
	} while (work);
	system("pause");
	return 0;
}
template<typename T>
void Buy(T& item) {
	item.Buy();
}
template<typename T>
int GetSize(T items[]) {
	int size = (sizeof((*items))) / (sizeof(items[0]));
	return size;
}
void CPUMenu()
{
	CPU* CPUs = new CPU[CPU_size]{ CPU("AMD Ryzen 5",5600,2,"Socket AM4",6,3.6,12),
			CPU("Intel Core i5-8600K",9760,5,"Socket 1151",6,3.6,6) };
	bool work = true;
	do {
		string menu_items[] = { "Buy","Create","BACK" };
		int answer = menu(menu_items, 3);
		switch (answer)
		{
		case 0: {
			int key = menu(CPUs, CPU_size);
			Buy(CPUs[key]);
		}
		case 1: cout << "2" << endl; break;
		case 3: cout << "4" << endl; break;
		case 2: work = false; break;

		}
	} while (work);

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