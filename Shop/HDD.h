#pragma once
#include "Product.h"
class HDD :
	public Product
{
private:
	string	Drive_capacity;//Емкость накопителя
	string Form_factor;
	string  Spindle_speed;
public:
	HDD(string Name,
		double Price,
		int Count,
		string Drive_capacity,
		string Form_factor,
		string Spindle_speed
	);
};

