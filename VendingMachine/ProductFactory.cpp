#include "ProductFactory.h"
#include "Juice.h"
#include "SoftDrink.h"
#include "Apple.h"
#include "Banana.h"
#include "Biscuit.h"
#include "Chips.h"

ProductFactory::ProductFactory()
{
}

ProductPtr ProductFactory::createProduct(ProductType productType, int quantity, int price, string name)
{
	ProductPtr product = nullptr;

	switch (productType)
	{
	case ProductType::JUICE:
		product = new Juice(name, quantity, price);
		break;
	case ProductType::SOFT_DRINK:
		product = new SoftDrink(name, quantity, price);
		break;
	case ProductType::APPLE:
		product = new Apple(quantity, price);
		break;
	case ProductType::BANANA:
		product = new Banana(quantity, price);
		break;
	case ProductType::BISCUIT:
		product = new Biscuit(name, quantity, price);
		break;
	case ProductType::CHIPS:
		product = new Chips(name, quantity, price);
		break;
	default:
		break;
	}
	return product;
}

ProductFactory::~ProductFactory()
{
}
