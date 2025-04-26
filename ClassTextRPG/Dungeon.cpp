#include "Dungeon.h"
#include "GameObject.h"
#include "MonsterCage.h"
#include <iostream>
#include <vector>
using namespace std;
Dungeon::Dungeon() : _player(nullptr), _cage(nullptr), _Fight() {}
void Dungeon::DunGeonSelect()
{

	bool isDungeonPlaying = true;
	while (isDungeonPlaying)
	{
		system("cls");
		cout << "������ ���̵��� �������ּ���!" << endl;
		cout << "1.�ʱ�" << endl;
		cout << "2.�߱�" << endl;
		cout << "3.���" << endl;
		cout << "4.�ڷΰ���" << endl;

		int SelectDifficult;
		cin >> SelectDifficult;

		switch (static_cast<DungeonDifficult>(SelectDifficult))
		{
		case DungeonDifficult::_Esay:
		{
			GameObject::PrintMsg("�ʱ޴����� �����߽��ϴ�.!");
			_Fight._reFight = true;
			while (_Fight.ShouldContinue())
			{
				MonsterArray arr = DifficultRandomMonster(SelectDifficult);
				if (arr._RandIdx != -1)
				{
					_Fight.IsFight(*_player, arr);
				}
				else
				{
					GameObject::PrintMsg("�ʱ޴����� ��� ���͸� óġ�߽��ϴ�!");
					break;
				}
			}
			break;
		}
		case DungeonDifficult::_Normal:
		{
			GameObject::PrintMsg("�߱޴����� �����߽��ϴ�.!");
			_Fight._reFight = true;
			while (_Fight.ShouldContinue())
			{
				MonsterArray arr = DifficultRandomMonster(SelectDifficult);
				if (arr._RandIdx != -1)
				{
					_Fight.IsFight(*_player, arr);
				}
				else
				{
					GameObject::PrintMsg("�߱޴����� ��� ���͸� óġ�߽��ϴ�!");
					break;
				}
			}
			break;
		}
		case DungeonDifficult::_Hard:
		{
			
			GameObject::PrintMsg("��޴����� �����߽��ϴ�.!");
			_Fight._reFight = true;
			while (_Fight.ShouldContinue())
			{
				MonsterArray arr = DifficultRandomMonster(SelectDifficult);
				if (arr._RandIdx != -1)
				{
					_Fight.IsFight(*_player, arr);
				}
				else
				{
					GameObject::PrintMsg("��޴����� ��� ���͸� óġ�߽��ϴ�!");
					break;
				}
			}
			break;
		}
		case DungeonDifficult::_back:
			cout << "�ڷΰ��⸦ �������ϴ�" << endl;
			system("pause");
			isDungeonPlaying = false;
			break;
		default:
			GameObject::PrintMsg("�߸��� �Է��Դϴ�. �ٽ� �������ּ���!");
			system("pause");
			break;

		}


	}


}

void Dungeon::setCage(MonsterCage* cage) //�������� ���� �޾ƿ��� �Լ�
{
	_cage = cage;
}
void Dungeon::setPlayer(Player* player)
{
	_player = player;
}
MonsterArray Dungeon::DifficultRandomMonster(int SD) //�ٽ��ѹ��� �����Ұ�! 
{
	static vector<Monster> empty;
	static Monster dummyMonster;
	if (!_cage)
	{
		GameObject::PrintMsg("�������� ����ֽ��ϴ�!");
		return MonsterArray{ dummyMonster, empty, -1 };
	}

	vector<Monster>& monsters = _cage->GetMonster(SD);

	if (monsters.empty())
	{
		GameObject::PrintMsg("�� �������� ���Ͱ� �����ϴ�");
		return MonsterArray{ dummyMonster, empty, -1 };
	}

	int randIdx = rand() % monsters.size();
	Monster _randommonster = monsters[randIdx];

	GameObject::PrintMsg("���� ���� ��ȯ!");

	return MonsterArray{ monsters[randIdx], monsters, randIdx };
}