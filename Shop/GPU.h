#pragma once
#include "Product.h"
class GPU :
	public Product
{
private:
	string Graphics_chip;
	int Memory;
	int Memory_Bus_Width;//Разрядность шины памяти
	string Memory_type;
	string Supplementary_Nutrition;//Дополнительное питание

public:
	GPU(string Name,
		double Price,
		int Count,
		string Graphics_chip,
		int Memory,
		int Memory_Bus_Width,
		int Memory_type,
		string Supplementary_Nutrition);

};

