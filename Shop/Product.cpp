#include "Product.h"
Product::Product()
{
	this->Name = "";
	this->Price = 0;
	this->Count = 0;
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

void Product::write(ostream& os)
{
	os.write((char*)&Price, sizeof(Price));
	os.write((char*)&Count, sizeof(Count));
	size_t len = Name.length() + 1;
	os.write((char*)&len, sizeof(len));
	os.write((char*)Name.c_str(), len);
}

void Product::read(istream& in)
{
	in.read((char*)&Price, sizeof(Price));
	in.read((char*)&Count, sizeof(Count));
	size_t len;
	in.read((char*)&len, sizeof(len));
	char* buf = new char[len];
	in.read(buf, len);
	Name = buf;
	delete[]buf;
}
