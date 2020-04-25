#include "SSD.h"

SSD::SSD(string Name,
	double Price,
	int Count,
	string Drive_capacity,
	int Read_speed,
	int Write_speed
) :Product(Name, Price, Count)
{
	this->Drive_capacity = Drive_capacity;
	this->Read_speed = Read_speed;
	this->Write_speed = Write_speed;
}