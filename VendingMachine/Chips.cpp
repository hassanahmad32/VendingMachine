#include "Chips.h"
#include <iostream>
using namespace std;

Chips::Chips(string productName, int productQuantity, int productPrice):Product()
{
	name = productName;
	category = ProductCategory::SNACKS;
	type = ProductType::CHIPS;
	quantity = productQuantity;
	price = productPrice;
}

void Chips::updateProduct(ProductPtr value)
{
	Chips* chips = dynamic_cast<Chips*>(value);

	if (price != chips->price)
	{
		price = chips->price;
	}
	if (quantity != chips->quantity)
	{
		quantity = chips->quantity;
	}
}

Chips::~Chips()
{
}
