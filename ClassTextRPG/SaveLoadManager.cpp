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
	ofstream outFile("SaveFile/Monster.dat", ios::binary);
	if (outFile.is_open())
	{
		for (int _grade = 1; _grade <= 3; ++_grade)
		{
			const vector<Monster>& monsters = cage.GetMonsters(_grade);//��޺��� ������ ���������� �б����뺯������ //��������

			size_t MonsterCount = monsters.size();
			outFile.write(reinterpret_cast<const char*>(&MonsterCount), sizeof(size_t)); //��޺� ������ ���� �����ϴ� ���̳ʸ������� �޸𸮰����� ��

			for (const Monster& monster : monsters) //���� ���� �ݺ��� monsters�� ũ�⸸ŭ �ݺ��ϰ� �����Ǿ�����
			{
				string _monsterName = monster.GetName();
				size_t _monsterNameLen = _monsterName.length();

				int hp = monster.Gethp();
				int attack = monster.GetAttack();
				int level = monster.GetLevel();


				outFile.write(reinterpret_cast<const char*>(&_monsterNameLen), sizeof(size_t));
				outFile.write(_monsterName.c_str(), _monsterNameLen);

				outFile.write(reinterpret_cast<const char*>(&hp), sizeof(int));
				outFile.write(reinterpret_cast<const char*>(&attack), sizeof(int));
				outFile.write(reinterpret_cast<const char*>(&level), sizeof(int));



			}



		}
		outFile.close();


	}
	else
	{
		cout << "������ �� �� �����ϴ�.!!!" << endl;
	}


}
void SaveLoadManager::SaveShop(const Shop& shop)
{

}

void SaveLoadManager::LoadPlayer(Player& player)
{
	ifstream inFile("SaveFile/Player.dat", ios::binary);
	if (!inFile.is_open())
	{
		cout << "������ �� �� �����ϴ�.!!!" << endl;
		return;
	}
	size_t _nameLen = 0;
	inFile.read(reinterpret_cast<char*>(&_nameLen), sizeof(size_t));//���Ͼ��� ���ڿ� �� �̸���  char*�������� �޸�����ȯ�� ���ؼ�  �̸��� ���̸� ���̳ʸ� ���·� ���� size_t��ŭ

	string _name;
	_name.resize(_nameLen); //string�����̳��� ũ�� �� ���ڿ��迭�� ũ�⸦ namelen ���ڿ��� ���� �޸𸮸�ŭ resize�ϰԵ�
	inFile.read(&_name[0], _nameLen);//���ڿ��� ù��°�ּҺ��� namelen�� ũ�⸸ŭ �ݺ��ؼ� �о�Ͷ�.

	int hp = 0, attack = 0, level = 0, gold = 0; //������ö��� �ʱⰪ�� ���� �� �ش罺���� �ʱ�ȭ���־����
	inFile.read(reinterpret_cast<char*>(&hp), sizeof(int)); //���������� �ٵ� ���� �д°� ���̳ʸ���? �׷� �ּҵ� ���̳ʸ� ���·� �ٲ��ְ� �װ� int�����ŭ �Ҵ�������ϳ�?
	inFile.read(reinterpret_cast<char*>(&attack), sizeof(int));
	inFile.read(reinterpret_cast<char*>(&level), sizeof(int));
	inFile.read(reinterpret_cast<char*>(&gold), sizeof(int));

	player.SetName(_name);
	player.SetHp(hp);
	player.SetAttack(attack);
	player.SetLevel(level);
	player.Setgold(gold);

	size_t RowCount = 0;
	size_t ColsCount = 0;
	inFile.read(reinterpret_cast<char*>(&RowCount), sizeof(size_t));
	inFile.read(reinterpret_cast<char*>(&ColsCount), sizeof(size_t));

	for (size_t i = 0; i < RowCount; ++i)
	{
		for (size_t j = 0; j < ColsCount; ++j)
		{
			size_t _itemNameLen = 0;
			inFile.read(reinterpret_cast<char*>(&_itemNameLen), sizeof(size_t));

			string _itemName;
			_itemName.resize(_itemNameLen); 
			inFile.read(&_itemName[0], _itemNameLen);
					
			int _itemSellMoney = 0;
			inFile.read(reinterpret_cast<char*>(&_itemSellMoney), sizeof(int));

			Item newItem;
			newItem.SetName(_itemName).SetSellItemMoney(_itemSellMoney);
		
			player.SetItem((int)i,(int) j, newItem);
			
		}	
	}
	inFile.close();
}
void SaveLoadManager::LoadMonster(MonsterCage& cage) 
{

	ifstream inFile("SaveFile/Monster.dat", ios::binary);
	if (inFile.is_open())
	{
		for (int _grade = 1; _grade <= 3; ++_grade)
		{

			size_t MonsterCount = 0;
			inFile.read(reinterpret_cast<char*>(&MonsterCount), sizeof(size_t)); 

			for (size_t i =0;i<MonsterCount;++i) 
			{
				size_t _monsterNameLen = 0;
				inFile.read(reinterpret_cast<char*>(&_monsterNameLen), sizeof(size_t));

				string _Monstername;
				_Monstername.resize(_monsterNameLen); //string�����̳��� ũ�� �� ���ڿ��迭�� ũ�⸦ namelen ���ڿ��� ���� �޸𸮸�ŭ resize�ϰԵ�
				inFile.read(&_Monstername[0], _monsterNameLen);//���ڿ��� ù��°�ּҺ��� namelen�� ũ�⸸ŭ �ݺ��ؼ� �о�Ͷ�.


				int hp = 0, attack = 0, level = 0;
				inFile.read(reinterpret_cast<char*>(&hp), sizeof(int)); 
				inFile.read(reinterpret_cast<char*>(&attack), sizeof(int));
				inFile.read(reinterpret_cast<char*>(&level), sizeof(int));
			
			
				Monster monster;
					   
				monster.SetName(_Monstername);
				monster.SetHp(hp);
				monster.SetAttack(attack);
				monster.SetLevel(level);
				
				cage.AddMonsters(_grade, monster);
			}



		}
		inFile.close();


	}
	else
	{
		cout << "������ �� �� �����ϴ�.!!!" << endl;
	}

	
}
void SaveLoadManager::LoadShop(Shop& shop)
{

}