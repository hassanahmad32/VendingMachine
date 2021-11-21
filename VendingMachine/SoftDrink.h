#pragma once
#include "Product.h"

typedef Product* ProductPtr;

class SoftDrink :
	public Product
{
public:
	SoftDrink(string productName, int productQuantity, int productPrice);
	void updateProduct(ProductPtr value);
	virtual ~SoftDrink();
};

