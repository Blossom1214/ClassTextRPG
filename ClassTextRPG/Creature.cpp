#include "Creature.h"
using namespace std;
Creature::Creature(string name, int hp, int attack, int level) :_name(name), _hp(hp), _attack(attack), _level(level)
{
}
Creature::~Creature()
{
}	
int& Creature::GetHp()
{
	return _hp;
}

void Creature::AddHp(int hp)
{
	_hp += hp;
}
int& Creature::Getlevel()
{
	return _level;
}
void Creature::SetName(const string& name)
{
	_name = name;
}

void Creature::SetHp(int hp)
{
	_hp = hp;
}
void Creature::SetAttack(int attack) 
{
	_attack = attack;
}
void Creature::SetLevel(int level)
{
	_level = level;
}

string Creature::GetName()const
{
	return _name;
}
int Creature::Gethp()const 
{
	return _hp;
}
int Creature::GetAttack() const
{
	return _attack;
}
int Creature::GetLevel() const
{
	return _level;
}