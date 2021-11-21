#pragma once
#include "Enums.h"
#include <map>
using namespace std;
#ifndef MESSAGE_H
#define MESSAGE_H
class Message
{
	// static object
	static Message* instance;
	map<ProductCategory, string> productCategoryTextMap;
	map<ProductType, string> productTypeTextMap;
	void fillCategoryMap();
	void fillProductTypeMap();
	Message();
	~Message();
public:
	static Message* getMessageInstance();
	void printUserSelectionMessage(SecurityAccessLevel level);
	void displayAllProducts();
	void printProductIds(ProductCategory productCategory);
	void displayProductTypes();
	
};
#endif
