#pragma once
#include <string>
class Creature //���͹� �������� ������ Ŭ�������� �ο��ϴ� �߻�Ŭ����
{
protected:
	std::string _name;
	int _hp;
	int _attack;
	int _level;
public:
	Creature(std::string name, int hp, int attack, int level);
	virtual ~Creature();
public:
	virtual void InfoPrint() = 0; // �߻�Ŭ���� ����
	int& GetHp();
	void SetHp(int hp);
	void AddHp(int hp);
	int GetAttack() const;
	int& Getlevel();

};