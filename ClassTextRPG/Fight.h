#pragma once
#include "Player.h"
#include "MonsterArray.h"
#include "GameObject.h"
class Fight
{
public:
	bool _reFight;

public:
	Fight();
public:
	void IsFight(Player& player, MonsterArray& monsterInfo);
	bool ShouldContinue() const;
};