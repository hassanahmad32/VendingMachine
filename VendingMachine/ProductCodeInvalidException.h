#pragma once
#include <exception>
using namespace std;

class ProductCodeInvalidException :
	public exception
{
public:
	ProductCodeInvalidException();
	virtual char const * what() const
	{
		return "Invalid Product code. Please enter correct code";
	}
	virtual ~ProductCodeInvalidException();
};

