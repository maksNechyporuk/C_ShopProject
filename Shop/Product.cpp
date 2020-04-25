#include "Product.h"
Product::Product(string Name, double Price, int Count/*, Description Descriptions[]*/)
{
	this->Name = Name;
	this->Price = Price;
	this->Count = Count;
	/*this->Descriptions = Descriptions;
	for (int i = 0; i < 2; i++)
	{
		cout << (this->Descriptions[i].GetName()) << "-" << this->Descriptions[i].GetValue() << endl;
	}*/
}