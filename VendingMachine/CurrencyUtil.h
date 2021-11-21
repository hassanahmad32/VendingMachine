#pragma once
#define COINS_OPTIONS_LENGTH 4
class CurrencyUtil
{
	int currencyOptions[COINS_OPTIONS_LENGTH] = {1, 5, 10, 20};
public:
	CurrencyUtil();
	bool returnBalance(int amount);
	~CurrencyUtil();
};

