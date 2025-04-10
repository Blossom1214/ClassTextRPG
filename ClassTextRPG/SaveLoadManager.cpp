#include "SaveLoadManager.h"
#include <fstream>
#include <iostream>
using namespace std;


void SaveLoadManager::SavePlayer(const Player& player)
{
	ofstream outFile("SaveFile/Player.dat", ios::binary); //outfile�� ���̳ʸ�Ÿ������ �����ϰٴ� �ش���ҿ�
	if (outFile.is_open()) 
	{
		string _name = player.GetName(); //�÷��̾��� �̸��� ���� _name�� ����
		size_t _nameLen = _name.length();//�� name�� ���ڿ��� ���̸� �������·� namelen�� ����
		outFile.write(reinterpret_cast<const char*>(&_nameLen), sizeof(size_t)); 
		//_namelen�� size_t�� 64��Ʈ�ü������ 8����Ʈ�� ���������� �������ִ� �ּҿ� ���� ������ �ִ»��� 
		//���� �޸��� ���¸� const char*������ �ٲپ���ϴµ� �̶� ��밡���Ѱ��� reinterpret_cast �޸�Ÿ���� ������ȯ�� ����Ͽ�
		//_nameLen�� �ּ��� ���̸�const char���� �� ���̳ʸ������·� size_t(8����Ʈ)��ŭ ��Եȴ�.
		//�װ� outfile��ġ�� ���� �Ȱ�
		outFile.write(_name.c_str(), _nameLen); //���� �ڵ�� �޸𸮰� �Ҵ�Ǿ��⶧���� �� ũ�⿡�°� name�� c_str(string�� c��Ÿ�Ϸ� �ٲ�(const char*) �ؼ� ���� �־���.
	
		int _hp = player.Gethp();
		int _attack = player.GetAttack();
		int _level = player.GetLevel();
		int _gold = player.Getgold();

		outFile.write(reinterpret_cast<const char*>(&_hp),sizeof(int));
		outFile.write(reinterpret_cast<const char*>(&_attack),sizeof(int));
		outFile.write(reinterpret_cast<const char*>(&_level),sizeof(int));
		outFile.write(reinterpret_cast<const char*>(&_gold),sizeof(int));
	
		const Inventory& _inventory = player.GetInventory();
		size_t _rowCount = _inventory.GetRow();
		size_t _colsCount = _inventory.GetCols();

		outFile.write(reinterpret_cast<const char*>(&_rowCount), sizeof(size_t));
		outFile.write(reinterpret_cast<const char*>(&_colsCount), sizeof(size_t));

		for (const auto& _Row : _inventory.Getgrid())
		{
			for (const auto& _iTem : _Row)
			{

				string _itemName = _iTem.GetName();
				size_t _itemNameLen = _itemName.length();

				outFile.write(reinterpret_cast<const char*>(&_itemNameLen), sizeof(size_t));
				outFile.write(_itemName.c_str(), _itemNameLen);

				int _itemSellMoney = _iTem.GetSellItemMoney();
				outFile.write(reinterpret_cast<const char*>(&_itemSellMoney), sizeof(int));

			}
		}
		outFile.close();
	}
	else
	{
		cout << "������ �� �� �����ϴ�.!!!" << endl;
	}
}
void SaveLoadManager::SaveMonster(const MonsterCage& cage)
{

}
void SaveLoadManager::SaveShop(const Shop& shop)
{

}

void SaveLoadManager::LoadPlayer(Player& player) 
{

}
void SaveLoadManager::LoadMonster(MonsterCage& cage) 
{

}
void SaveLoadManager::LoadShop(Shop& shop)
{

}