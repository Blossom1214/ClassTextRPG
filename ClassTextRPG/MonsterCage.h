#pragma once
#include "Monster.h"
#include <vector>
class MonsterCage // ���� ������ Ŭ����
{
private:
	std::vector<Monster>_Cage[3];
public:
	void MonsterCreateRoutine();
	std::vector<Monster>& GetMonster(int grade);
};