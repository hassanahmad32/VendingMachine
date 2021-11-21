#pragma once
#include "Product.h"

typedef Product* ProductPtr;

class Apple:
	public Product
{
public:
	Apple(int productQuantity, int productPrice);
	void updateProduct(ProductPtr value);
	~Apple();
};

