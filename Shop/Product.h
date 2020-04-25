#pragma once
#include <string>
#include<iostream>
#include "Description.h"
using namespace std;
class Product
{
protected:
	string Name;
	double Price;
	int Count;
	Description* Descriptions;
public:
	Product(string Name, double Price, int Count/*, Description Descriptions[]*/);
};

