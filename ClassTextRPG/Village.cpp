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
		GameObject::PrintMsg("������ �����߽��ϴ�. ���� ���ðڽ��ϱ�?");
		cout << "1. ���� ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��ȭ��" << endl;
		cout << "4. �κ��丮Ȯ��" << endl;
		cout << "5. ����" << endl;
		cout << "6. ��������" << endl;
		cout << "����: ";
		int Select;
		cin >> Select;
		switch (static_cast<villageSection>(Select))
		{
		case villageSection::_Dungeon:
			cout << "������ �����մϴ�" << endl;
			system("pause");
			_Dungeon1.DunGeonSelect();
			break;
		case villageSection::_Shop:
			cout << "������ ���ϴ�(������)" << endl;
			_Shop1.ShopSelect();
			system("pause");
			break;
		case villageSection::_refinery:
			cout << "��ȭ�ҿ� ���ϴ�(���� �̱���)" << endl;
			system("pause");
			break;
		case villageSection::_InventoryCheck:
			cout << "���� �÷��̾��� �κ��丮�� Ȯ���մϴ�.(���� �̱���)" << endl;
			system("pause");
			break;
		case villageSection::_Save:
			cout << "���� ��Ȳ�� �����մϴ�(������)" << endl;
			Save();
			system("pause");
			break;
		case villageSection::_GameEnd:
			cout << "������ �����մϴ�." << endl;
			system("pause");
			InVillage = false;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�" << endl;
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