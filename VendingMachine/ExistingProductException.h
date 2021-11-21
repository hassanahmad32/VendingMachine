#pragma once
#include <iostream>
#include <exception>
using namespace std;
class ExistingProductException :
	public exception
{
public:
	ExistingProductException();
	virtual char const * what() const 
	{ 
		return "Already existing product exception"; 
	}
	virtual ~ExistingProductException();
};

