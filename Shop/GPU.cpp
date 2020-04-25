#include "GPU.h"
GPU::GPU(string Name,
	double Price,
	int Count,
	string Graphics_chip,
	int Memory,
	int Memory_Bus_Width,
	int Memory_type,
	string Supplementary_Nutrition)
	:Product(Name, Price, Count)
{
	this->Graphics_chip = Graphics_chip;
	this->Memory = Memory;
	this->Memory_Bus_Width = Memory_Bus_Width;
	this->Memory_type = Memory_type;
	this->Supplementary_Nutrition = Supplementary_Nutrition;
}