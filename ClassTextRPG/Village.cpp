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
		GameObject::PrintMsg("������ �����߽��ϴ�. ���� ���ðڽ��ϱ�?");
		cout << "1. ���� ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��ȭ��" << endl;
		cout << "4. ����" << endl;
		cout << "5. ��������" << endl;
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
			cout << "������ ���ϴ�(����̱���)" << endl;
			system("pause");
			break;
		case villageSection::_refinery:
			cout << "��ȭ�ҿ� ���ϴ�(���� �̱���)" << endl;
			system("pause");
			break;
		case villageSection::_Save:
			cout << "���� ��Ȳ�� �����մϴ�(���� �̱���)" << endl;
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
void Village::SetCage(MonsterCage* cage, Player* player)
{
	_Dungeon1.setCage(cage);
	_Dungeon1.setPlayer(player);
}
