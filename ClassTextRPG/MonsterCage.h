#pragma once
#include "Monster.h"
#include <vector>
class MonsterCage // 몬스터 케이지 클래스
{
private:
	std::vector<Monster>_Cage[3];
public:
	void MonsterCreateRoutine();
	std::vector<Monster>& GetMonster(int grade);
};