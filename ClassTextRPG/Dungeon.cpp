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
		cout << "던전의 난이도를 선택해주세요!" << endl;
		cout << "1.초급" << endl;
		cout << "2.중급" << endl;
		cout << "3.고급" << endl;
		cout << "4.뒤로가기" << endl;

		int SelectDifficult;
		cin >> SelectDifficult;

		switch (static_cast<DungeonDifficult>(SelectDifficult))
		{
		case DungeonDifficult::_Esay:
		{
			GameObject::PrintMsg("초급던전를 선택했습니다.!");
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
					GameObject::PrintMsg("초급던전의 모든 몬스터를 처치했습니다!");
					break;
				}
			}
			break;
		}
		case DungeonDifficult::_Normal:
		{
			GameObject::PrintMsg("중급던전를 선택했습니다.!");
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
					GameObject::PrintMsg("중급던전의 모든 몬스터를 처치했습니다!");
					break;
				}
			}
			break;
		}
		case DungeonDifficult::_Hard:
		{
			
			GameObject::PrintMsg("고급던전를 선택했습니다.!");
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
					GameObject::PrintMsg("고급던전의 모든 몬스터를 처치했습니다!");
					break;
				}
			}
			break;
		}
		case DungeonDifficult::_back:
			cout << "뒤로가기를 눌렀습니다" << endl;
			system("pause");
			isDungeonPlaying = false;
			break;
		default:
			GameObject::PrintMsg("잘못된 입력입니다. 다시 선택해주세요!");
			system("pause");
			break;

		}


	}


}

void Dungeon::setCage(MonsterCage* cage) //케이지의 값을 받아오는 함수
{
	_cage = cage;
}
void Dungeon::setPlayer(Player* player)
{
	_player = player;
}
MonsterArray Dungeon::DifficultRandomMonster(int SD) //다시한번더 공부할것! 
{
	static vector<Monster> empty;
	static Monster dummyMonster;
	if (!_cage)
	{
		GameObject::PrintMsg("케이지가 비어있습니다!");
		return MonsterArray{ dummyMonster, empty, -1 };
	}

	vector<Monster>& monsters = _cage->GetMonster(SD);

	if (monsters.empty())
	{
		GameObject::PrintMsg("이 레벨에는 몬스터가 없습니다");
		return MonsterArray{ dummyMonster, empty, -1 };
	}

	int randIdx = rand() % monsters.size();
	Monster _randommonster = monsters[randIdx];

	GameObject::PrintMsg("랜덤 몬스터 소환!");

	return MonsterArray{ monsters[randIdx], monsters, randIdx };
}