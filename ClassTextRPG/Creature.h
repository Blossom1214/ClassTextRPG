#pragma once
#include <string>
class Creature //몬스터및 공용으로 가지는 클래스에게 부여하는 추상클래스
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
	virtual void InfoPrint() = 0; // 추상클래스 선언
	int& GetHp();
	void SetHp(int hp);
	void AddHp(int hp);
	int GetAttack() const;
	int& Getlevel();

};