#pragma once
#include "Product.h"
class CPU : public Product
{

public:
	CPU();
	CPU(string Name,
		double Price,
		int Count,
		string Connector_type,
		int Number_of_Cores,
		double Clock_frequency,
		int Number_threads);
	void Show() override;
	void Create() override;
protected:
	string Connector_type;
	int Number_of_Cores;
	double Clock_frequency;
	int Number_threads;
};

