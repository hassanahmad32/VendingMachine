#include "CurrencyUtil.h"
#include <iostream>
using namespace std;

CurrencyUtil::CurrencyUtil()
{

}

bool CurrencyUtil::returnBalance(int amount)
{
	int coinsCount[COINS_OPTIONS_LENGTH] = { 0,0,0,0 };
	int index = COINS_OPTIONS_LENGTH - 1;
	int totalCoinsCount = 0;
	while (index >= 0)
	{
		int count = amount / currencyOptions[index];
		coinsCount[index] = count;
		amount = amount % currencyOptions[index];
		totalCoinsCount += count;
		index--;
	}

	if (totalCoinsCount != 0)
	{
		cout << "Returing the balance amount" << endl;
		for (int index = 0; index < COINS_OPTIONS_LENGTH; index++)
		{
			if (coinsCount[index] != 0)
			{
				cout << currencyOptions[index] << " Value coins count = " << coinsCount[index] << endl;
			}
		}
	}
	return true;
}


CurrencyUtil::~CurrencyUtil()
{
}
