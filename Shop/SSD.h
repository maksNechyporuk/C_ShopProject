#pragma once
#include "Product.h"
class SSD :
	public Product
{
private:
	string	Drive_capacity;//Емкость накопителя
	int Read_speed;
	int Write_speed;
public:
	SSD(string Name,
		double Price,
		int Count,
		string Drive_capacity,
		int Read_speed,
		int Write_speed);
};

