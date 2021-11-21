#pragma once
#include "Product.h"
typedef Product* ProductPtr;
class Chips :
	public Product
{
public:
	Chips(string productName, int productQuantity, int productPrice);
	void updateProduct(ProductPtr value);
	~Chips();
};

