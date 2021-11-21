#pragma once
#include "Product.h"

typedef Product* ProductPtr;

class Banana :
	public Product
{
public:
	Banana(int productQuantity, int productPrice);
	void updateProduct(ProductPtr value);
	~Banana();
};

