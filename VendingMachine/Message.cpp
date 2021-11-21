#include "Message.h"
#include <iostream>
#include "VendingMachine.h"

using namespace std;

Message* Message::instance = nullptr;

Message* Message::getMessageInstance()
{
	if (instance == nullptr)
	{
		instance = new Message();
	}
	return instance;
}

Message::Message()
{
	fillCategoryMap();
	fillProductTypeMap();
}

void Message::fillCategoryMap()
{
	productCategoryTextMap[ProductCategory::BEVERAGES] = " Beverages(1)";
	productCategoryTextMap[ProductCategory::FRUITS] = " Fruits(2)";
	productCategoryTextMap[ProductCategory::SNACKS] = " Snacks(3)";
}

void Message::fillProductTypeMap()
{
	productTypeTextMap[ProductType::SOFT_DRINK] = "Soft Drink(3)";
	productTypeTextMap[ProductType::APPLE] = "Apple(1)";
	productTypeTextMap[ProductType::BANANA] = "Banana(2)";
	productTypeTextMap[ProductType::JUICE] = "Juice(4)";
	productTypeTextMap[ProductType::BISCUIT] = "Biscuit(5)";
	productTypeTextMap[ProductType::CHIPS] = "Chips(6)";
}

void Message::printUserSelectionMessage(SecurityAccessLevel level)
{
	if (level == SecurityAccessLevel::ADMIN)
	{
		cout << "Dear Admin, you are allowed below operations to perform" << endl;
		cout << "DisplayProductPrice(1), PurchaseProduct(2), AddMoney(3), AddProduct(4), UpdateProduct(5), DeleteProduct(6). Enter (0) to exit" << endl;
	}
	else
	{
		cout << "Dear User, you are allowed below operations to perform" << endl;
		cout << "DisplayProductPrice(1), PurchaseProduct(2), AddMoney(3). Enter (0) to exit" << endl;
	}
}

void Message::printProductIds(ProductCategory productCategory)
{
	VendingMachine* vm = VendingMachine::getVendingMachine();
	if (productCategory == ProductCategory::BEVERAGES)
	{
		string beveragesCategory;
		beveragesCategory += ("Category = " + productCategoryTextMap[ProductCategory::BEVERAGES] + "\n");
		beveragesCategory += ("ProductType = " + productTypeTextMap[ProductType::SOFT_DRINK] + ", Product(ProductId) = ");
		string products = vm->getTextProductIdByProductType(ProductType::SOFT_DRINK);
		if (products == "")
		{
			beveragesCategory += "No Available Products";
		}
		beveragesCategory += products + "\n";
		beveragesCategory += ("ProductType = " + productTypeTextMap[ProductType::JUICE] + ", Products = ");
		products = "";
		products = vm->getTextProductIdByProductType(ProductType::JUICE);
		if (products == "")
		{
			beveragesCategory += "No Available Products";
		}
		beveragesCategory += products;
		cout << beveragesCategory << endl;
		cout << "---------------------------------------------------------------------------" << endl;
	}
	else if (productCategory == ProductCategory::FRUITS)
	{
		string beveragesCategory;
		beveragesCategory += ("Category = " + productCategoryTextMap[ProductCategory::FRUITS] + "\n");
		beveragesCategory += ("ProductType = " + productTypeTextMap[ProductType::APPLE] + ", Product(ProductId) = ");
		string products = vm->getTextProductIdByProductType(ProductType::APPLE);
		if (products == "")
		{
			beveragesCategory += "No Available Products";
		}
		beveragesCategory += products + "\n";
		beveragesCategory += ("ProductType = " + productTypeTextMap[ProductType::BANANA] + ", Products = ");
		products = "";
		products = vm->getTextProductIdByProductType(ProductType::BANANA);
		if (products == "")
		{
			beveragesCategory += "No Available Products";
		}
		beveragesCategory += products;
		cout << beveragesCategory << endl;
		cout << "---------------------------------------------------------------------------" << endl;
	}
	else if (productCategory == ProductCategory::SNACKS)
	{
		string beveragesCategory;
		beveragesCategory += ("Category = " + productCategoryTextMap[ProductCategory::SNACKS] + "\n");
		beveragesCategory += ("ProductType = " + productTypeTextMap[ProductType::BISCUIT] + ", Product(ProductId) = ");
		string products = vm->getTextProductIdByProductType(ProductType::BISCUIT);
		if (products == "")
		{
			beveragesCategory += "No Available Products";
		}
		beveragesCategory += products + "\n";
		beveragesCategory += ("ProductType = " + productTypeTextMap[ProductType::CHIPS] + ", Products = ");
		products = "";
		products = vm->getTextProductIdByProductType(ProductType::CHIPS);
		if (products == "")
		{
			beveragesCategory += "No Available Products";
		}
		beveragesCategory += products;
		cout << beveragesCategory << endl;
		cout << "---------------------------------------------------------------------------" << endl;
	}
}

void Message::displayAllProducts()
{
	cout << "Please select the Valid Product Category, Type and productId from below Information" << endl;
	cout << "For Example. Choose product. Enter 1,3,4 - where 1 - Category, 3 - Type, last 4 - product" << endl;
	printProductIds(ProductCategory::BEVERAGES);
	printProductIds(ProductCategory::FRUITS);
	printProductIds(ProductCategory::SNACKS);
}

void Message::displayProductTypes()
{
	string productCategory;
	productCategory += ("Category = " + productCategoryTextMap[ProductCategory::BEVERAGES] + "\n");
	productCategory += ("ProductType = " + productTypeTextMap[ProductType::SOFT_DRINK] + ", " + productTypeTextMap[ProductType::JUICE]);
	cout << productCategory << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	productCategory = "";
	productCategory += ("Category = " + productCategoryTextMap[ProductCategory::FRUITS] + "\n");
	productCategory += ("ProductType = " + productTypeTextMap[ProductType::APPLE] + ", " + productTypeTextMap[ProductType::BANANA]);
	cout << productCategory << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	productCategory = "";
	productCategory += ("Category = " + productCategoryTextMap[ProductCategory::SNACKS] + "\n");
	productCategory += ("ProductType = " + productTypeTextMap[ProductType::BISCUIT] + ", " + productTypeTextMap[ProductType::CHIPS]);
	cout << productCategory << endl;
	cout << "---------------------------------------------------------------------------" << endl;
}
Message::~Message()
{
}
