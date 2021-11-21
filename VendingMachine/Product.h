#pragma once
#include <string>
#include "Enums.h"
using namespace std;

#ifndef PRODUCT_H

// Abstract class to have the highest level class for Product level inheritance
class Product
{
protected:
	string name;
	ProductCategory category;
	ProductType type;
	int quantity;
	int price;
public:
	virtual void updateProduct(Product* value) = 0;
	
	inline ProductType getType()
	{
		return type;
	}

	inline ProductCategory getCategory()
	{
		return category;
	}

	inline int getPrice()
	{
		return price;
	}

	inline bool isQuantityAvailable()
	{
		return quantity > 0;
	}
	inline string getName()
	{
		return name;
	}
	inline void updateProductQuantity()
	{
		quantity = quantity - 1;
	}
	virtual ~Product();
};
#define PRODUCT_H
#endif // !PRODUCT_H


