#include "Village.h"
#include "Player.h"
#include "GameObject.h"
#include <iostream>
using namespace std;
void Village::EnterVillage()
{
	bool InVillage = true;
	while (InVillage)
	{
		system("cls");
		GameObject::PrintMsg("마을에 입장했습니다. 어디로 가시겠습니까?");
		cout << "1. 던전 입장" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 강화소" << endl;
		cout << "4. 인벤토리확인" << endl;
		cout << "5. 저장" << endl;
		cout << "6. 게임종료" << endl;
		cout << "선택: ";
		int Select;
		cin >> Select;
		switch (static_cast<villageSection>(Select))
		{
		case villageSection::_Dungeon:
			cout << "던전에 입장합니다" << endl;
			system("pause");
			_Dungeon1.DunGeonSelect();
			break;
		case villageSection::_Shop:
			cout << "상점에 들어갑니다(구현중)" << endl;
			_Shop1.ShopSelect();
			system("pause");
			break;
		case villageSection::_refinery:
			cout << "강화소에 들어갑니다(현재 미구현)" << endl;
			system("pause");
			break;
		case villageSection::_InventoryCheck:
			cout << "현재 플레이어의 인벤토리를 확인합니다.(현재 미구현)" << endl;
			system("pause");
			break;
		case villageSection::_Save:
			cout << "진행 상황을 저장합니다(구현중)" << endl;
			Save();
			system("pause");
			break;
		case villageSection::_GameEnd:
			cout << "게임을 종료합니다." << endl;
			system("pause");
			InVillage = false;
			break;
		default:
			cout << "잘못된 입력입니다" << endl;
			system("pause");
			break;
		}
	}
}
void Village::SetObject(MonsterCage* cage, Player* player)
{
	_Cage = cage;
	_player = player;

	_Dungeon1.setCage(cage);
	_Dungeon1.setPlayer(player);
	_Shop1.SetShopPlayer(player);
}
void Village::Save()const
{
	SaveLoadManager Manager;
	if(_player)
	Manager.SavePlayer(*_player);
	if(_Cage)
	Manager.SaveMonster(*_Cage);
	Manager.SaveShop(_Shop1);
}
void Village::Load()
{
	SaveLoadManager Manager;
	if (_player)
		Manager.LoadPlayer(*_player);
	if (_Cage)
		Manager.LoadMonster(*_Cage);
	Manager.LoadShop(_Shop1);
}
Shop& Village::GetShop()
{ 
	return _Shop1; 
}