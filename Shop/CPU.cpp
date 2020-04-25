#include "CPU.h"
CPU::CPU(string Name,
	double Price,
	int Count,
	string Connector_type,
	int Number_of_Cores,
	int Clock_frequency,
	int Number_threads)
	:Product(Name, Price, Count)
{
	this->Clock_frequency = Clock_frequency;
	this->Connector_type = Connector_type;
	this->Number_of_Cores = Number_of_Cores;
	this->Number_threads = Number_threads;
}