#pragma once

#ifndef ENUMS_H

typedef enum
{
	ADMIN,
	USER,
	DEFAULT
} SecurityAccessLevel;

typedef enum
{
	BEVERAGES = 1,
	FRUITS,
	SNACKS,
	COUNT,
	UNDEFINED_CAT = 9
} ProductCategory;

typedef enum
{
	APPLE = 1,
	BANANA,
	SOFT_DRINK, // = 3
	JUICE,
	BISCUIT, // = 5
	CHIPS,
	UNDEFINED_TYPE = 9
} ProductType;

typedef enum 
{
	DisplayProductPrice = 1,
	PurchaseProduct,
	AddMoney,
	AddProduct,
	UpdateProduct,
	DeleteProduct,
	UndefinedOperation = 9
} AllowedOperations;
#define ENUMS_H
#endif // !ENUMS_H

