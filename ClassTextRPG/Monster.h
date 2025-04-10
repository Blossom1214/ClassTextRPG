#pragma once
#include "Creature.h"
#include <string>
class Monster : public Creature //몬스터 객체클래스
{
public:
	int _grade;
public:
	Monster();
public:
	int Grade(); //객체가 생성될때 hp와등등을 가지고 해당 객체의 등급을 결정하는  함수
	void InfoPrint() override;
};