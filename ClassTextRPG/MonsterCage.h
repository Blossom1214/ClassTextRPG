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
	const std::vector<Monster>& GetMonsters(int grade)const; //인벤토리에 몬스터의 등급을 측정해서 넣기위한 함수로 완전 읽기전용으로 만듬
	void AddMonsters(int grade, const Monster& monster);
};