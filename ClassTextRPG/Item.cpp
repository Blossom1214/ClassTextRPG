#include "Item.h"

using namespace std;

Item::Item():_Item("empty"),_SellMoney()
{

}
string Item::GetName()const
{
	return _Item;
}
int& Item::GetSellItemMoney()
{
	return _SellMoney;
}
void Item::SetName(string name)
{
	_Item = name;
}
void Item::SetSellItemMoney(int money)
{
	_SellMoney = money;
}