#include <iostream>
#include <string>
#include "VendingMachine.h"
#include "Biscuit.h"
#include "Enums.h"
#include "Message.h"
#include "Operations.h"

using namespace std;
typedef Product* ProductPtr;
// This is main driver function for Vending machine system
int main(int argc, string argv[])
{
	VendingMachine* vm = VendingMachine::getVendingMachine();

	// Filling the data structure just like from database
	vm->loadProducts();

	// Check the valid user permission and level
	bool isValidUser = false;
	int adminOrUser;
	while (!isValidUser)
	{
		cout << "Are you Admin or End User. Please enter 1 for Admin and 2 for EndUser and press enter : ";
		cin >> adminOrUser;
		if (adminOrUser == 1)
		{
			vm->setSecurityAccessLevel(SecurityAccessLevel::ADMIN);
			isValidUser = true;
		}
		else if (adminOrUser == 2)
		{
			vm->setSecurityAccessLevel(SecurityAccessLevel::USER);
			isValidUser = true;
		}
		else
		{
			cout << "Invalid entry. Please retry as per below message" << endl;
		}
	}

	bool stopRequest = false;
	while (!stopRequest)
	{
		Message * message = Message::getMessageInstance();
		if (adminOrUser == 1)
		{
			message->printUserSelectionMessage(SecurityAccessLevel::ADMIN);
		}
		else
		{
			message->printUserSelectionMessage(SecurityAccessLevel::USER);
		}

		// Chooses options for operation
		int inputOperationId;
		cin >> inputOperationId;
		if (inputOperationId == 0)
		{
			stopRequest = true;
			continue;
		}
		Operations* operationsUtil = new Operations();
		if (!operationsUtil->isAllowedOperation(inputOperationId))
		{
			cout << "Invalid operation." << endl;
			continue;
		}

		if (operationsUtil->performOperationFlow(inputOperationId))
		{
			cout << "Request completed successfully" << endl;
		}
		delete operationsUtil;
		system("pause");
	}
	
	return 0;
}
