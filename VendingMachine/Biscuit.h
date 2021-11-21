#pragma once
#include "Product.h"

typedef Product* ProductPtr;

class Biscuit :
	public Product
{
public:
	Biscuit(string productName, int productQuantity, int productPrice);
	void updateProduct(ProductPtr value);
	~Biscuit();
};

