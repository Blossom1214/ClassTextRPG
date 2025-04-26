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
	virtual void InfoPrint() = 0; //순수가상함수선언 //추상클래스선언
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