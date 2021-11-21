#pragma once
#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H
#include <iostream>
#include <vector>
#include <map>
#include "Product.h"
#include "Enums.h"
#include "CurrencyUtil.h"

using namespace std;

typedef Product* ProductPtr;

// Singleton class

class VendingMachine
{
	static VendingMachine* instance;
	// Saving products details according to Product Category list
	vector<ProductPtr>* beverages;
	vector<ProductPtr>* fruits;
	vector<ProductPtr>* snacks;
	int balance;

	// Setting security access like admin or user
	SecurityAccessLevel securityAccessLevel;
	CurrencyUtil* currencyUtil;

	// Unique product Id associated with each object
	static int productId;
	// Create mapping for product ID, product name, product type
	map<int, string> productIdNameMap;
	map<ProductType, vector<int>> productTypeIdMap;

	vector<ProductPtr>* getProducts(ProductCategory productCateogory);
	VendingMachine();
	~VendingMachine();
public:
	// Singleton object return method
	static VendingMachine* getVendingMachine();
	
	inline void setSecurityAccessLevel(SecurityAccessLevel level)
	{
		securityAccessLevel = level;
	}

	inline SecurityAccessLevel getSecurityAccessLevel()
	{
		return securityAccessLevel;
	}
	// Admin level operations
	void addProduct(ProductPtr &product);
	void removeProduct(ProductCategory category, ProductType type, int productId);

	// User and Admin level operations
	int getProductPrice(ProductCategory &category, ProductType &type, int productId);
	bool purchaseProduct(const ProductCategory &category, const ProductType &type, int productId);
	void addMoney(int currencyValue);
	
	string getTextProductIdByProductType(ProductType productType);
	ProductPtr getProduct(ProductCategory &category, ProductType &type, int productId);

	// Initial load of the product data like DB operation
	void loadProducts();
};
#endif
