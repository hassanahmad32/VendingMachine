#include "Biscuit.h"



Biscuit::Biscuit(string productName, int productQuantity, int productPrice):Product()
{
	name = productName;
	category = ProductCategory::SNACKS;
	type = ProductType::BISCUIT;
	quantity = productQuantity;
	price = productPrice;
}

void Biscuit::updateProduct(ProductPtr value)
{
	Biscuit* biscuit = dynamic_cast<Biscuit*>(value);

	if (price != biscuit->price)
	{
		price = biscuit->price;
	}
	if (quantity != biscuit->quantity)
	{
		quantity = biscuit->quantity;
	}
}

Biscuit::~Biscuit()
{
}
