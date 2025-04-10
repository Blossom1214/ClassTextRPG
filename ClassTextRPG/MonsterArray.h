#pragma once
#include "Monster.h"
#include <vector>
struct MonsterArray {
	Monster& _randommonster;
	std::vector<Monster>& monster;
	int _RandIdx;
};