#pragma once
#include <exception>
using namespace std;
class CategoryTypeMismatchException :
	public exception
{
public:
	CategoryTypeMismatchException();
	virtual char const * what() const
	{
		return "Invalid combination of Product Category and Product Type";
	}
	virtual ~CategoryTypeMismatchException();
};

