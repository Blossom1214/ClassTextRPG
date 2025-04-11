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
	ofstream outFile("SaveFile/Monster.dat", ios::binary);
	if (outFile.is_open())
	{
		for (int _grade = 1; _grade <= 3; ++_grade)
		{
			const vector<Monster>& monsters = cage.GetMonsters(_grade);//등급별로 몬스터의 정보를담을 읽기전용변수생성 //행을쓴것

			size_t MonsterCount = monsters.size();
			outFile.write(reinterpret_cast<const char*>(&MonsterCount), sizeof(size_t)); //등급별 몬스터의 수를 저장하는 바이너리형태의 메모리공간을 씀

			for (const Monster& monster : monsters) //범위 지정 반복문 monsters의 크기만큼 반복하게 설정되어있음
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
		cout << "파일을 열 수 없습니다.!!!" << endl;
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
		cout << "파일을 열 수 없습니다.!!!" << endl;
		return;
	}
	size_t _nameLen = 0;
	inFile.read(reinterpret_cast<char*>(&_nameLen), sizeof(size_t));//파일안의 문자열 즉 이름을  char*형식으로 메모리형변환을 통해서  이름의 길이를 바이너리 형태로 읽음 size_t만큼

	string _name;
	_name.resize(_nameLen); //string컨테이너의 크기 즉 문자열배열의 크기를 namelen 문자열을 읽을 메모리만큼 resize하게됨
	inFile.read(&_name[0], _nameLen);//문자열의 첫번째주소부터 namelen의 크기만큼 반복해서 읽어와라.

	int hp = 0, attack = 0, level = 0, gold = 0; //가지고올때의 초기값을 설정 즉 해당스탯을 초기화해주어야함
	inFile.read(reinterpret_cast<char*>(&hp), sizeof(int)); //읽을꺼에요 근데 내가 읽는건 바이너리네? 그럼 주소도 바이너리 형태로 바꿔주고 그걸 int사이즈만큼 할당해줘야하네?
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
				_Monstername.resize(_monsterNameLen); //string컨테이너의 크기 즉 문자열배열의 크기를 namelen 문자열을 읽을 메모리만큼 resize하게됨
				inFile.read(&_Monstername[0], _monsterNameLen);//문자열의 첫번째주소부터 namelen의 크기만큼 반복해서 읽어와라.


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
		cout << "파일을 열 수 없습니다.!!!" << endl;
	}

	
}
void SaveLoadManager::LoadShop(Shop& shop)
{

}