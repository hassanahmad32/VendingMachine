#include "Apple.h"



Apple::Apple(int productQuantity, int productPrice) :Product()
{
	name = "Apple";
	category = ProductCategory::FRUITS;
	type = ProductType::APPLE;
	quantity = productQuantity;
	price = productPrice;
}

void Apple::updateProduct(ProductPtr value)
{
	Apple* apple = dynamic_cast<Apple*>(value);
	if (price != apple->price)
	{
		price = apple->price;
	}
	if (quantity != apple->quantity)
	{
		quantity = apple->quantity;
	}
}

Apple::~Apple()
{
}
