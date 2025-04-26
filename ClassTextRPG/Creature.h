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
	virtual void InfoPrint() = 0; //���������Լ����� //�߻�Ŭ��������
	int& GetHp();
	void AddHp(int hp);
	int& Getlevel();
	void SetName(const std::string& name);
	void SetHp(int hp);
	void SetAttack(int attack);
	void SetLevel(int level);

	std::string GetName()const;
	int Gethp()const;
	int GetAttack() const;
	int GetLevel()const;

};