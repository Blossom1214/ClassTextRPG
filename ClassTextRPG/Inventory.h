#pragma once
#include <vector>
#include "Item.h"

class Inventory //2���� ���ͷ� ������
{
private:
	std::vector<std::vector<Item>> _grid; //itemŸ���� 2���� ���Ͱ� ������..
	static const int _ROW = 5;
	static const int _COLS = 5;
public:
	Inventory(){}
public:
	void AddItem(const Item& _Newitem);
	void ShowInventory()const; //�κ��丮�� �����ִ� �뵵
	const int GetRow()const;
	const int GetCols()const;
	const std::vector<std::vector<Item>> Getgrid()const;
};