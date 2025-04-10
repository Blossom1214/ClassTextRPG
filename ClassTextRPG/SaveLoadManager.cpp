#include "SaveLoadManager.h"
#include <fstream>
#include <iostream>
using namespace std;


void SaveLoadManager::SavePlayer(const Player& player)
{
	ofstream outFile("SaveFile/Player.dat", ios::binary); //outfile을 바이너리타입으로 쓰기하겟다 해당장소에
	if (outFile.is_open()) 
	{
		string _name = player.GetName(); //플레이어의 이름을 담을 _name을 담음
		size_t _nameLen = _name.length();//그 name의 문자열의 길이를 정수형태로 namelen에 담음
		outFile.write(reinterpret_cast<const char*>(&_nameLen), sizeof(size_t)); 
		//_namelen은 size_t즉 64비트운영체제에서 8바이트로 정수형값을 담을수있는 주소와 값을 가지고 있는상태 
		//따라서 메모리의 형태를 const char*형으로 바꾸어야하는데 이때 사용가능한것이 reinterpret_cast 메모리타입형 강제변환을 사용하여
		//_nameLen의 주소의 길이를const char형태 즉 바이너리의형태로 size_t(8바이트)만큼 담게된다.
		//그걸 outfile위치에 쓰게 된것
		outFile.write(_name.c_str(), _nameLen); //위의 코드로 메모리가 할당되었기때문에 그 크기에맞게 name을 c_str(string을 c스타일로 바꿈(const char*) 해서 집어 넣었다.
	
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
		cout << "파일을 열 수 없습니다.!!!" << endl;
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