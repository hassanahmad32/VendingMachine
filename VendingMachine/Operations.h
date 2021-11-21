#pragma once
#include "Enums.h"
#include <string>
#include <sstream>
using namespace std;

class Operations
{
	// Operation workflows
	void displayProductPriceWorkflow();
	void purchaseProductWorkflow();
	void addMoneyWorkflow();
	void addProductWorkflow();
	void updateProductWorkflow();
	void removeProductWorkflow();

	// Helper methods
	bool parseProductCode(string inputProduct, ProductCategory& productCategory, ProductType& productType, int& productId);
	bool isCategoryTypeAllowed(ProductCategory productCategory, ProductType productType);
public:
	Operations();
	bool performOperationFlow(int operation);
	bool isAllowedOperation(int operationId);
	~Operations();
};

