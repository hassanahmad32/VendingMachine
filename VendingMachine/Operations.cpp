#include "Operations.h"
#include "Message.h"
#include "ProductFactory.h"
#include "VendingMachine.h"
#include "ProductCodeInvalidException.h"
#include "CategoryTypeMismatchException.h"

#define INPUT_LENGTH 3
Operations::Operations()
{

}

bool Operations::performOperationFlow(int operation)
{
	try
	{
		bool isOperationWorkflowDone = true;
		switch (operation)
		{
		case AllowedOperations::DisplayProductPrice:
			// Display Product price workflow
			displayProductPriceWorkflow();
			break;
		case AllowedOperations::PurchaseProduct:
			purchaseProductWorkflow();
			break;
		case AllowedOperations::AddMoney:
			addMoneyWorkflow();
			break;
		case AllowedOperations::AddProduct:
			addProductWorkflow();
			break;
		case AllowedOperations::UpdateProduct:
			// Update product workflow
			updateProductWorkflow();
			break;
		case AllowedOperations::DeleteProduct:
			removeProductWorkflow();
			break;
		default:
			isOperationWorkflowDone = false;
			break;
		}
		return isOperationWorkflowDone;
	}
	catch (exception* &e)
	{
		// Exception handling
		cout << e->what() << endl;
		delete e;
		return false;
	}
}

bool Operations::isAllowedOperation(int operationId)
{
	VendingMachine* vm = VendingMachine::getVendingMachine();
	bool isAllowed = false;

	if ((vm->getSecurityAccessLevel() == SecurityAccessLevel::ADMIN) &&
		(operationId == AllowedOperations::DisplayProductPrice ||
		 operationId == AllowedOperations::PurchaseProduct ||
		 operationId == AllowedOperations::AddMoney ||
		 operationId == AllowedOperations::AddProduct ||
		 operationId == AllowedOperations::UpdateProduct ||
		 operationId == AllowedOperations::DeleteProduct))
	{
		isAllowed = true;
	}
	else if ((vm->getSecurityAccessLevel() == SecurityAccessLevel::USER) &&
			(operationId == AllowedOperations::DisplayProductPrice ||
			 operationId == AllowedOperations::PurchaseProduct ||
			 operationId == AllowedOperations::AddMoney))
	{
		isAllowed = true;
	}
	return isAllowed;
}

void Operations::displayProductPriceWorkflow()
{
	VendingMachine* vm = VendingMachine::getVendingMachine();
	Message* message = Message::getMessageInstance();
	message->displayAllProducts();
	cout << "Enter Product Code : ";
	string productCode;
	cin >> productCode;
	ProductCategory productCategory = ProductCategory::UNDEFINED_CAT;
	ProductType productType = ProductType::UNDEFINED_TYPE;
	int productId = 0;
	if (parseProductCode(productCode, productCategory, productType, productId) && isCategoryTypeAllowed(productCategory, productType))
	{
		int price = vm->getProductPrice(productCategory, productType, productId);
		cout << "Product Price is " << price << endl;
	}
	return;
}

void Operations::purchaseProductWorkflow()
{
	VendingMachine* vm = VendingMachine::getVendingMachine();
	Message* message = Message::getMessageInstance();
	message->displayAllProducts();
	cout << "Enter Product code to purchase: ";
	string productCode;
	cin >> productCode;
	ProductCategory productCategory = ProductCategory::UNDEFINED_CAT;
	ProductType productType = ProductType::UNDEFINED_TYPE;
	int productId = 0;
	if (parseProductCode(productCode, productCategory, productType, productId) && isCategoryTypeAllowed(productCategory, productType))
	{
		if (vm->purchaseProduct(productCategory, productType, productId))
		{
			cout << "Product Successfully Purchased. Thank You" << endl;
		}
	}
	return;
}

void Operations::addMoneyWorkflow()
{
	cout << "Enter value of the Money: ";
	int moneyValue;
	cin >> moneyValue;

	VendingMachine* vm = VendingMachine::getVendingMachine();
	vm->addMoney(moneyValue);
}

void Operations::addProductWorkflow()
{
	cout << "Available Product category and Type curently supported are as below :" << endl;
	Message* message = Message::getMessageInstance();
	message->displayProductTypes();
	int productCategory;
	cout << "Enter Product category : ";
	cin >> productCategory;

	if (productCategory > ProductCategory::SNACKS)
	{
		cout << "Unsupported product category" << endl;
		return;
	}
	cout << "Enter Product Type: ";
	int productType;
	cin >> productType;
	if (productType > ProductType::CHIPS || !isCategoryTypeAllowed(static_cast<ProductCategory>(productCategory), static_cast<ProductType>(productType)))
	{
		cout << "Unsupported product Type" << endl;
		return;
	}
	cout << "Enter Product Name: ";
	string productName;
	cin >> productName;

	cout << "Enter Product Quantity: ";
	int productQuantity;
	cin >> productQuantity;
	
	cout << "Enter Product Price: ";
	int productPrice;
	cin >> productPrice;
	
	ProductPtr product = ProductFactory::createProduct(static_cast<ProductType>(productType), productQuantity, productPrice, productName);
	VendingMachine* vm = VendingMachine::getVendingMachine();
	vm->addProduct(product);
	return;
}

void Operations::updateProductWorkflow()
{
	VendingMachine* vm = VendingMachine::getVendingMachine();
	Message* message = Message::getMessageInstance();
	message->displayAllProducts();
	cout << "Enter Product code to update: ";
	string productCode;
	cin >> productCode;
	ProductCategory productCategory = ProductCategory::UNDEFINED_CAT;
	ProductType productType = ProductType::UNDEFINED_TYPE;
	int productId = 0;
	if (parseProductCode(productCode, productCategory, productType, productId) && isCategoryTypeAllowed(productCategory, productType))
	{
		ProductPtr product = vm->getProduct(productCategory, productType, productId);
		if (product != nullptr)
		{
			cout << "Please enter new quantity : ";
			int newQuantity;
			cin >> newQuantity;

			cout << "Please enter new Price : ";
			int newPrice;
			cin >> newPrice;

			ProductPtr updatedProductDetails = ProductFactory::createProduct(productType, newQuantity, newPrice, "dummy");
			product->updateProduct(updatedProductDetails);
			delete updatedProductDetails;
		}
	}
	return;
}

void Operations::removeProductWorkflow()
{
	VendingMachine* vm = VendingMachine::getVendingMachine();
	Message* message = Message::getMessageInstance();
	message->displayAllProducts();
	cout << "Enter Product code to delete: ";
	string productCode;
	cin >> productCode;
	ProductCategory productCategory = ProductCategory::UNDEFINED_CAT;
	ProductType productType = ProductType::UNDEFINED_TYPE;
	int productId = 0;
	if (parseProductCode(productCode, productCategory, productType, productId) && isCategoryTypeAllowed(productCategory, productType))
	{
		vm->removeProduct(productCategory, productType, productId);
	}
}

bool Operations::parseProductCode(string productCode, ProductCategory& productCategory, ProductType& productType, int& productId)
{
	try
	{
		vector<int> inputs;
		stringstream s_stream(productCode);
		while (s_stream.good())
		{
			string substr;
			getline(s_stream, substr, ',');
			inputs.push_back(stoi(substr));
		}
		if (inputs.size() != INPUT_LENGTH)
		{
			throw new ProductCodeInvalidException();
		}
		
		productCategory = static_cast<ProductCategory>(inputs.at(0));
		productType = static_cast<ProductType>(inputs.at(1));
		productId = inputs.at(2);
		
		return true;
	}
	catch (exception* &e)
	{
		throw e;
	}
}

bool Operations::isCategoryTypeAllowed(ProductCategory productCategory, ProductType productType)
{
	try
	{
		bool isAllowed = false;
		if (((productCategory == ProductCategory::BEVERAGES) &&
			(productType == ProductType::SOFT_DRINK || productType == ProductType::JUICE)) ||
			((productCategory == ProductCategory::FRUITS) &&
			(productType == ProductType::APPLE || productType == ProductType::BANANA)) ||
				((productCategory == ProductCategory::SNACKS) &&
			(productType == ProductType::BISCUIT || productType == ProductType::CHIPS)))
		{
			isAllowed = true;
		}

		if (false == isAllowed)
		{
			throw new CategoryTypeMismatchException();
		}
		return isAllowed;
	}
	catch (exception* &e)
	{
		throw e;
	}
	
}

Operations::~Operations()
{
}
