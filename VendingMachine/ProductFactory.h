#pragma once
#include "Enums.h"
#include "Product.h"
#include <string>
using namespace std;

#ifndef PRODUCT_FACTORY_H
#define PRODUCT_FACTORY_H
typedef Product* ProductPtr;

// Factory class to implement factory method to create products
class ProductFactory
{
	ProductFactory();
public:
	static ProductPtr createProduct(ProductType productType, int quantity, int price, string name = "\0");
	~ProductFactory();
};
#endif
