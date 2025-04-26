#include "Monster.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Monster::Monster() : Creature("", 0, 0, 0)
{

	_name = "";
	_hp = rand() % 100 + 1;
	_attack = rand() % 50 + 1;
	_level = (_hp + _attack) % 10 + 1;
	_grade = Grade();
}

int Monster::Grade() //객체가 생성될때 hp와등등을 가지고 해당 객체의 등급을 결정하는  함수
{
	unsigned int result = _hp + _attack + _level;
	if (50 >= result) {
		return 1;
	}
	else if (100 >= result)
	{
		return 2;
	}
	else {
		return 3;
	}

}
void Monster::InfoPrint()
{
	cout << " 이름: " << _name << endl;
	cout << " Hp: " << _hp << endl;
	cout << " 공격력: " << _attack << endl;
	cout << " 레벨: " << _level << endl;
	cout << " 등급 " << _grade << endl;
}
