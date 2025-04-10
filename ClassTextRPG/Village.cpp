#include "Village.h"
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
		cout << "4. 저장" << endl;
		cout << "5. 게임종료" << endl;
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
			cout << "상점에 들어갑니다(현재미구현)" << endl;
			system("pause");
			break;
		case villageSection::_refinery:
			cout << "강화소에 들어갑니다(현재 미구현)" << endl;
			system("pause");
			break;
		case villageSection::_Save:
			cout << "진행 상황을 저장합니다(현재 미구현)" << endl;
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
void Village::SetCage(MonsterCage* cage, Player* player)
{
	_Dungeon1.setCage(cage);
	_Dungeon1.setPlayer(player);
}
