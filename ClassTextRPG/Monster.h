#pragma once
#include "Creature.h"
#include <string>
class Monster : public Creature //���� ��üŬ����
{
public:
	int _grade;
public:
	Monster();
public:
	int Grade(); //��ü�� �����ɶ� hp�͵���� ������ �ش� ��ü�� ����� �����ϴ�  �Լ�
	void InfoPrint() override;
};