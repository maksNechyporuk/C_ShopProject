#pragma once
#include <string>
#include<iostream>
#include "Description.h"
using namespace std;
class Product
{
protected:
	string Name;
	double Price;
	int Count;
	Description* Descriptions;
public:
	Product(string Name, double Price, int Count, Description Descriptions[])
	{
		this->Name = Name;
		this->Price = Price;
		this->Count = Count;
		this->Descriptions = Descriptions;
		for (int i = 0; i < 2; i++)
		{
			cout << (this->Descriptions[i].GetName()) << "-" << this->Descriptions[i].GetValue() << endl;
		}
	}
};

