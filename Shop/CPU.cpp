#include "CPU.h"
#include <iostream>
#include <string>

CPU::CPU()
{
	this->Connector_type = "";

	this->Clock_frequency = 0;
	this->Number_of_Cores = 0;
	this->Number_threads = 0;
}
CPU::CPU(string Name,
	double Price,
	int Count,
	string Connector_type,
	int Number_of_Cores,
	double Clock_frequency,
	int Number_threads)
	:Product(Name, Price, Count)
{
	this->Connector_type = Connector_type;

	this->Clock_frequency = Clock_frequency;
	this->Number_of_Cores = Number_of_Cores;
	this->Number_threads = Number_threads;
}
void CPU::Show()
{
	if (this->Count > 0) {
		cout << "*********************************************\n";
		Product::Show();
		cout << "Connector type:" << this->Connector_type << endl << "Number of cores:" << this->Number_of_Cores << "\n";
		cout << "Clock frequency:" << this->Clock_frequency << endl << "Number threads:" << this->Number_threads << endl;
		cout << "*********************************************\n";
	}
}

void CPU::Create()
{
	Product::Create();
	cout << "Connector type:";
	string type;
	cin.get();
	getline(cin, type);
	cout << "Number of Cores:";
	cin >> this->Number_of_Cores;
	cout << "Clock frequency:";
	cin >> this->Clock_frequency;
	cout << "Number threads:";
	cin >> this->Number_threads;
	this->Connector_type = type;
	Show();
}

void CPU::write(ostream& os)
{
	os.write((char*)&Number_of_Cores, sizeof(Number_of_Cores));
	os.write((char*)&Clock_frequency, sizeof(Clock_frequency));
	os.write((char*)&Number_threads, sizeof(Number_threads));
	Product::write(os);
	size_t len = Connector_type.length() + 1;
	os.write((char*)&len, sizeof(len));
	os.write((char*)Connector_type.c_str(), len);
}

void CPU::read(istream& in)
{
	Product::read(in);

	in.read((char*)&Number_of_Cores, sizeof(Number_of_Cores));
	in.read((char*)&Clock_frequency, sizeof(Clock_frequency));
	in.read((char*)&Number_threads, sizeof(Number_threads));

	size_t len;
	in.read((char*)&len, sizeof(len));
	char* buf = new char[len];
	in.read(buf, len);
	Connector_type = buf;
	delete[]buf;
}
