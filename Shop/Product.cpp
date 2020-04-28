#include "Product.h"
Product::Product()
{
}
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
void Product::Show()
{
	cout << "Name:" << this->Name << endl << "Price:" << this->Price << endl << "Count:" << this->Count << endl;
}

void Product::Buy()
{
	if (this->Count > 0)
	{
		this->Count -= 1;
	}
}

void Product::Create()
{
	cout << "Name:";
	getline(std::cin, this->Name);
	cout << "Price:";
	cin >> this->Price;
	cout << "Count:";
	cin >> this->Count;
}

