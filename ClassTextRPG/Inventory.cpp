#include "Inventory.h"
#include <iostream>
using namespace std;


void Inventory::AddItem(const Item& _Newitem)
{
	static int i = 0;
	if (i == _ROW - 1 && _grid[i].size() == static_cast<unsigned long long>(_COLS))
	{
		cout << "�κ��丮 ������ ��á���ϴ�" << endl;
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
		cout << "�κ��丮�� ����ֽ��ϴ�!" << endl;
		cout << "============================" << endl;
	}
	else
	{
		//for(vector<string>::iterator it=_Item.begin();it !=_Item.end();++it) == : ��� �����ϸ�ȴ�
		//���������̳ʾȿ��ִ� ��ҵ��� �ϳ��� �Ű������� ��´�./���ͻӸ��ƴ϶� ��������̳��� for�� ���� ��ݿ� ���ȴ�.
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