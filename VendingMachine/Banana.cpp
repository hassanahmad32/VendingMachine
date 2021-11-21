#include "Banana.h"



Banana::Banana(int productQuantity, int productPrice):Product()
{
	name = "Banana";
	category = ProductCategory::FRUITS;
	type = ProductType::BANANA;
	quantity = productQuantity;
	price = productPrice;
}

void Banana::updateProduct(ProductPtr value)
{
	Banana* banana = dynamic_cast<Banana*>(value);
	if (price != banana->price)
	{
		price = banana->price;
	}
	if (quantity != banana->quantity)
	{
		quantity = banana->quantity;
	}
}


Banana::~Banana()
{
}
