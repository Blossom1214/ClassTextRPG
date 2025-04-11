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
	const std::vector<Monster>& GetMonsters(int grade)const; //�κ��丮�� ������ ����� �����ؼ� �ֱ����� �Լ��� ���� �б��������� ����
	void AddMonsters(int grade, const Monster& monster);
};