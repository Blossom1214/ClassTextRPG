#include "MonsterCage.h"
#include <cstdlib>
#include <ctime>
using namespace std;
void MonsterCage::MonsterCreateRoutine()
{
	int totalCountMonster = 0;
	while (totalCountMonster < 15) // 15¹ø ¹Ýº¹
	{
		Monster monster;
		int grade = monster._grade;
		if (grade >= 1 && grade <= 3)
		{
			if (_Cage[grade - 1].size() < 5)
			{
				_Cage[grade - 1].push_back(monster);
				totalCountMonster++;

			}
		}
	}
}
vector<Monster>& MonsterCage::GetMonster(int grade)
{
	return _Cage[grade - 1];
}
const vector<Monster>& MonsterCage::GetMonsters(int grade) const 
{
	return _Cage[grade - 1];
}
void MonsterCage::AddMonsters(int grade, const Monster& monster)
{
	if (grade >= 1 && grade <= 3)
	{
		_Cage[grade - 1].push_back(monster);
	}
}
