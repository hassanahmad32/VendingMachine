#pragma once
#include "Product.h"
typedef Product* ProductPtr;
class Juice :
	public Product
{
public:
	Juice(string juiceName, int juiceQuantity, int juicePrice);
	void updateProduct(ProductPtr value);
	virtual ~Juice();
};

