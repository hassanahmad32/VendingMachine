#include "SoftDrink.h"

SoftDrink::SoftDrink(string productName, int productQuantity, int productPrice):Product()
{
	name = productName;
	category = ProductCategory::BEVERAGES;
	type = ProductType::SOFT_DRINK;
	quantity = productQuantity;
	price = productPrice;
}

void SoftDrink::updateProduct(ProductPtr value)
{
	SoftDrink* softDrink = dynamic_cast<SoftDrink*>(value);
	
	if (price != softDrink->price)
	{
		price = softDrink->price;
	}
	if (quantity != softDrink->quantity)
	{
		quantity = softDrink->quantity;
	}
}


SoftDrink::~SoftDrink()
{
}
