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

int Monster::Grade() //��ü�� �����ɶ� hp�͵���� ������ �ش� ��ü�� ����� �����ϴ�  �Լ�
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
	cout << " �̸�: " << _name << endl;
	cout << " Hp: " << _hp << endl;
	cout << " ���ݷ�: " << _attack << endl;
	cout << " ����: " << _level << endl;
	cout << " ��� " << _grade << endl;
}
