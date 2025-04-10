#include "Inventory.h"
#include <iostream>
using namespace std;


void Inventory::AddItem(const Item& _Newitem)
{
	static int i = 0;
	if (i == _ROW - 1 && _grid[i].size() == static_cast<unsigned long long>(_COLS))
	{
		cout << "인벤토리 공간이 꽉찼습니다" << endl;
		return;
	}
	if (_grid[i].size() < _COLS)
	{
		_grid[i].push_back(_Newitem);
		return;
	}
	else
	{
		i++;
		_grid[i].push_back(_Newitem);
		return;
	}

}
void Inventory::ShowInventory()const
{
	cout << "============================" << endl;
	if (_grid.empty())
	{
		cout << "인벤토리가 비어있습니다!" << endl;
		cout << "============================" << endl;
	}
	else
	{
		//for(vector<string>::iterator it=_Item.begin();it !=_Item.end();++it) == : 라고 생각하면된다
		//벡터컨테이너안에있는 요소들을 하나씩 매개변수에 담는다./벡터뿐만아니라 모든컨테이너의 for문 범위 기반에 사용된다.
		for (const auto& row : _grid)
		{
			for (const auto& item : row)
			{
				cout << "[" << item.GetName() << "] ";
			}
			cout << endl;
		}
		
	}

}
 const int Inventory::GetRow()const
{
	return _ROW;
}
const int Inventory::GetCols()const
{
	return _COLS;
}
const vector<vector<Item>> Inventory::Getgrid()const
{

	return _grid;
}