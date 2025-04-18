#pragma once
#include <vector>
#include "Item.h"

class Inventory //2차원 백터로 만들어보자
{
private:
	std::vector<std::vector<Item>> _grid; //item타입의 2차원 벡터가 생성됨..
	static const int _ROW = 5;
	static const int _COLS = 5;
public:
	Inventory(){}
public:
	void AddItem(const Item& _Newitem);
	void ShowInventory()const; //인벤토리를 보여주는 용도
	const int GetRow()const;
	const int GetCols()const;
	const std::vector<std::vector<Item>> Getgrid()const;
	void SetItem(int row, int cols, const Item& item);
	void Resize(size_t row, size_t col);
};