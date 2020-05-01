#include <iostream>
#include <conio.h>
#include<fstream>
#include <windows.h>
#include "Header.h"
#include "Description.h"
#include "Product.h"
#include "CPU.h"
using namespace std;
int CPU_size = 0;
int menu(string menus[], int size);
void EndWork();
void StartWork();
template<typename T>
int menu(T* product, int size);
void CPUMenu();
template<typename T>
int GetSize(T items[]);
template<typename T>
void Buy(T& item);
template<typename T1>
void Create(T1*& items, int& size);
template<typename T>
void ReadItem(T*& items, T*& item, int& size);
CPU* CPUs = new CPU[CPU_size];/*{ CPU("Intel Core i5-8600K", 9760, 5, "Socket 1151", 6, 3.6, 6),
 CPU("AMD Ryzen 5", 5600, 2, "Socket AM4", 6, 3.6, 12) };*/
int main()
{
	CONSOLE_INFO();
	Size_Console(45, 35);
	StartWork();
	/*bool work = true;
	do {
		string menu_items[] = { "CPU","GPU","HDD","SSD","EXIT" };
		int answer = menu(menu_items, 5);
		switch (answer)
		{
		case 0: {
			CPUMenu();
			break;
		}
		case 1: cout << "2" << endl; break;
		case 2: cout << "3" << endl; break;
		case 3: cout << "4" << endl; break;
		case 4: work = false; break;

		}
	} while (work);

	*///EndWork();
	system("pause");

	return 0;
}
template<typename T>
void ReadItem(T*& items, T*& item, int& size)
{
	T* new_items = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		(new_items[i]) = (items[i]);
	}

	new_items[size] = item;
	if (size != 0)
		delete[] items;
	items = new_items;
	size++;
}
void StartWork()
{
	ifstream file;
	file.open("CPU.txt");
	if (!file.is_open())
	{
		cout << "error\n";
	}
	else
	{
		CPU new_cpu;
		while (file.read((char*)&new_cpu, sizeof(CPU)))
		{
			ifstream file1;
			file1.open("CPU.txt");
			CPU new_cpuu;
			new_cpuu.read(file1);
			new_cpuu.Show();
			//ReadItem(CPUs, new_cpu, CPU_size);
		}
	}
	file.close();
}

void EndWork() {
	ofstream file("CPU.txt", ios::binary | ios::app);
	for (int i = 0; i < CPU_size; i++)
		CPUs[i].write(file);
	/*for (int i = 0; i < CPU_size; i++)
	{
		ofstream file;
		file.open("CPU.txt", ofstream::app);
		if (!file.is_open())
		{
			cout << "error\n";
		}
		else
		{
			file.write((char*)&CPUs[i], sizeof(CPU));
		}
		file.close();
	*/

}
template<typename T1>
void Create(T1*& items, int& size)
{
	T1* new_items = new T1[size + 1];
	for (int i = 0; i < size; i++)
	{
		(new_items[i]) = (items[i]);
	}
	T1 new_item;
	new_item.Create();
	new_items[size] = new_item;
	delete[] items;
	items = new_items;
	size++;
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
	bool work = true;
	do {
		string menu_items[] = { "Buy","Create","BACK" };
		int answer = menu(menu_items, 3);
		switch (answer)
		{
		case 0: {
			int key = menu(CPUs, CPU_size);
			Buy(CPUs[key]);
			break;

		}
		case 1: {
			Create(CPUs, CPU_size);
			CPU_size++;
			system("pause");
			break;
		}
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