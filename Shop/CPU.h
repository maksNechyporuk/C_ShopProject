#pragma once
#include "Product.h"
class CPU : public Product
{

public:
	CPU(string Name,
		double Price,
		int Count,
		string Connector_type,
		int Number_of_Cores,
		int Clock_frequency,
		int Number_threads);
private:
	string Connector_type;
	int Number_of_Cores;
	int Clock_frequency;
	int Number_threads;
};

