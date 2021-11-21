#pragma once
#include <exception>
using namespace std;
class ProductNotFoundException :
	public exception
{
public:
	ProductNotFoundException();
	virtual char const * what() const
	{
		return "Product Not found in the available product";
	}
	virtual ~ProductNotFoundException();
};

