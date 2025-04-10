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
	int& GetSellItemMoney();
	void SetName(std::string name);
	void SetSellItemMoney(int money);
};