#pragma once
#include <exception>
using namespace std;
class ProductOutOfStockException :
	public exception
{
public:
	ProductOutOfStockException();
	virtual char const * what() const
	{
		return "Product Out of stock";
	}
	virtual ~ProductOutOfStockException();
};

