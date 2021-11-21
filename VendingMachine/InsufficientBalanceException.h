#pragma once
#include <exception>
using namespace std;
class InsufficientBalanceException :
	public exception
{
public:
	InsufficientBalanceException();
	virtual char const * what() const
	{
		return "Insufficient Balance. Please add some money first";
	}
	virtual ~InsufficientBalanceException();
};

