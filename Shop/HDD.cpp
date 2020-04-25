#include "HDD.h"

HDD::HDD(string Name,
	double Price,
	int Count,
	string Drive_capacity,
	string Form_factor,
	string Spindle_speed
) :Product(Name, Price, Count)
{
	this->Drive_capacity = Drive_capacity;
	this->Form_factor = Form_factor;
	this->Spindle_speed = Spindle_speed;
}