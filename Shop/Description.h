#pragma once
#include <string>
using namespace std;
class Description
{
private:
	string Name;
	string Value;


public:
	string GetName()
	{
		return this->Name;
	}

	string GetValue()
	{
		return this->Value;
	}
	Description()
	{

	}

	Description(string Name, string Value)
	{
		this->Name = Name;
		this->Value = Value;


	}
};

