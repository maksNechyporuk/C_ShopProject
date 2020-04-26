#include "CPU.h"
CPU::CPU()
{
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
	this->Clock_frequency = Clock_frequency;
	this->Connector_type = Connector_type;
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