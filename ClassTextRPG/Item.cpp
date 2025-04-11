#include "Item.h"

using namespace std;

Item::Item():_Item("empty"),_SellMoney()
{

}
Item::Item(const string& name, int sellPrice) : _Item("empty"),_SellMoney()
{
}
string Item::GetName()const
{
	return _Item;
}
int Item::GetSellItemMoney()const
{
	return _SellMoney;
}
Item& Item::SetName(string name)
{
	_Item = name;
	return *this;
}
Item& Item::SetSellItemMoney(int money)
{
	_SellMoney = money;
	return *this;
}