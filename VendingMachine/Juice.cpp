#include "Juice.h"



Juice::Juice(string juiceName, int juiceQuantity, int juicePrice):Product()
{
	name = juiceName;
	category = ProductCategory::BEVERAGES;
	type = ProductType::JUICE;
	quantity = juiceQuantity;
	price = juicePrice;

}

void Juice::updateProduct(ProductPtr value)
{
	Juice* juice = dynamic_cast<Juice*>(value);
	
	if (price != juice->price)
	{
		price = juice->price;
	}
	if (quantity != juice->quantity)
	{
		quantity = juice->quantity;
	}
}

Juice::~Juice()
{
}
