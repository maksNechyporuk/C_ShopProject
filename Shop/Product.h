#pragma once
#include <string>
#include<iostream>
using namespace std;
class Product
{
protected:
	string Name;
	double Price;
	int Count;
public:
	Product();
	Product(string Name, double Price, int Count/*, Description Descriptions[]*/);
	virtual void Show();
	void Buy();
	virtual void Create();
};

