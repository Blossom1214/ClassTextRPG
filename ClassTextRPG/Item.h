#pragma once
#include <string>

class Item
{
private:
	std::string _Item;
	int _SellMoney;
public:
	Item();
public:
	std::string GetName()const;
	int GetSellItemMoney()const;
	Item& SetName(std::string name);
	Item& SetSellItemMoney(int money);
};