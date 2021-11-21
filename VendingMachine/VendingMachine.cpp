#include "VendingMachine.h"
#include <iterator>
#include "ProductFactory.h"
#include "ExistingProductException.h"
#include "ProductNotFoundException.h"
#include "ProductOutOfStockException.h"
#include "InsufficientBalanceException.h"

VendingMachine* VendingMachine::instance = nullptr;
int VendingMachine::productId = 0;
VendingMachine::VendingMachine()
{
	securityAccessLevel = SecurityAccessLevel::DEFAULT;
	beverages = new vector<Product*>(0);
	fruits = new vector<Product*>(0);
	snacks = new vector<Product*>(0);
	balance = 0;
	currencyUtil = new CurrencyUtil();
}

vector<ProductPtr>* VendingMachine::getProducts(ProductCategory productCategory)
{
	vector<ProductPtr>* products = nullptr;
	if (productCategory == ProductCategory::BEVERAGES)
		products = beverages;
	else if (productCategory == ProductCategory::FRUITS)
		products = fruits;
	else if (productCategory == ProductCategory::SNACKS)
		products = snacks;
	return products;
}

VendingMachine* VendingMachine::getVendingMachine()
{
	if (instance == nullptr)
	{
		instance = new VendingMachine();
	}
	return instance;
}

void VendingMachine::addProduct(ProductPtr &inputProduct)
{
	try 
	{
		ProductCategory productCategory = inputProduct->getCategory();
		vector<ProductPtr>* products = getProducts(productCategory);

		if (products == nullptr)
		{
			return;
		}

		for (auto product : *products)
		{
			if (product->getType() == inputProduct->getType() && product->getName() == inputProduct->getName())
			{
				throw new ExistingProductException();
			}
		}
		productId++;
		// Fill the map for ProductID to product Name
		productIdNameMap[productId] = inputProduct->getName();
		// Fill the map for Product Type to ProductID
		vector<int> productIds = productTypeIdMap[inputProduct->getType()];
		productIds.push_back(productId);
		productTypeIdMap[inputProduct->getType()] = productIds;
		products->push_back(inputProduct);
	}
	catch (exception* &e)
	{
		throw e;
	}
}

void VendingMachine::removeProduct(ProductCategory category,ProductType type, int productId)
{
	vector<ProductPtr>* products = getProducts(category);

	if (products == nullptr)
		return;

	for (vector<ProductPtr>::iterator itr = products->begin() ; itr != products->end(); itr++)
	{
		ProductPtr product = *itr;
		if (product->getType() == type)
		{
			products->erase(itr);
			delete product;
			break;
		}
	}
}

int VendingMachine::getProductPrice(ProductCategory &productCategory, ProductType &type, int productId)
{
	try
	{
		vector<ProductPtr>* products = getProducts(productCategory);
		if (products == nullptr)
			return 0;
		bool productFound = false;
		int price = 0;
		for (auto product : *products)
		{
			string productName = productIdNameMap[productId];
			if (product->getType() == type && product->getName() == productName)
			{
				productFound = true;
				price = product->getPrice();
				break;
			}
		}
		if (false == productFound)
		{
			throw new ProductNotFoundException();
		}
		return price;
	}
	catch (exception* &e)
	{
		throw e;
	}
}

bool VendingMachine::purchaseProduct(const ProductCategory &category, const ProductType &type, int productId)
{
	try
	{
		vector<ProductPtr>* products = getProducts(category);
		if (products == nullptr)
			return false;

		ProductPtr foundProduct = nullptr;
		for (auto product : *products)
		{
			string productName = productIdNameMap[productId];
			if (product->getType() == type && product->getName() == productName)
			{
				foundProduct = product;
				break;
			}
		}
		if (nullptr == foundProduct)
		{
			throw new ProductNotFoundException();
		}
		if (false == foundProduct->isQuantityAvailable())
		{
			throw new ProductOutOfStockException();
		}
		if (foundProduct->getPrice() > balance)
		{
			throw new InsufficientBalanceException();
		}

		cout << "Product Purchased Successfully" << endl;

		if (currencyUtil->returnBalance(balance - foundProduct->getPrice()) == true)
		{
			balance = 0;
		}
		foundProduct->updateProductQuantity();
		return true;
	}
	catch (exception* &e)
	{
		throw e;
	}
}

void VendingMachine::addMoney(int currencyValue)
{
	balance += currencyValue;
}

// Return the Product List as string
string VendingMachine::getTextProductIdByProductType(ProductType productType)
{
	vector<int> productIds = productTypeIdMap[productType];
	string result;
	for (auto productId : productIds)
	{
		result += productIdNameMap[productId] + "(" + to_string(productId) + "), ";
	}
	return result;
}

ProductPtr VendingMachine::getProduct(ProductCategory &category, ProductType &type, int productId)
{
	vector<ProductPtr>* products = getProducts(category);
	ProductPtr resultProduct = nullptr;
	for (auto product : *products)
	{
		string productName = productIdNameMap[productId];
		if (product->getType() == type && product->getName() == productName)
		{
			resultProduct = product;
			break;
		}
	}
	return resultProduct;
}

// Initial load of the data like DB operation
void VendingMachine::loadProducts()
{
	//Fruits
	ProductPtr product = ProductFactory::createProduct(ProductType::APPLE, 10, 12);
	addProduct(product);
	product = ProductFactory::createProduct(ProductType::BANANA, 15, 11);
	addProduct(product);
	// Beverages
	product = ProductFactory::createProduct(ProductType::SOFT_DRINK, 20, 20, "Coke");
	addProduct(product);
	product = ProductFactory::createProduct(ProductType::SOFT_DRINK, 15, 15, "ThumsUp");
	addProduct(product);
	product = ProductFactory::createProduct(ProductType::JUICE, 30, 23, "Tropicana");
	addProduct(product);
	product = ProductFactory::createProduct(ProductType::JUICE, 35, 18, "Real");
	addProduct(product);

	// Snacks
	product = ProductFactory::createProduct(ProductType::BISCUIT, 40, 10, "ParleG");
	addProduct(product);
	product = ProductFactory::createProduct(ProductType::BISCUIT, 25, 15, "MarieGold");
	addProduct(product);
	product = ProductFactory::createProduct(ProductType::CHIPS, 20, 13, "Lays");
	addProduct(product);
	product = ProductFactory::createProduct(ProductType::CHIPS, 30, 10, "UncleChips");
	addProduct(product);
}

VendingMachine::~VendingMachine()
{
}
