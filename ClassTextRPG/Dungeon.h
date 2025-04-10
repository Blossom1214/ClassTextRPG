#pragma once
#include "Player.h"
#include "MonsterCage.h"
#include "Fight.h"
class Dungeon //던전 입장시!
{
private:
	Player* _player;
	MonsterCage* _cage;
	Fight _Fight;
	enum class DungeonDifficult
	{
		_Esay = 1,
		_Normal,
		_Hard,
		_back
	};
public:
	Dungeon();
public:
	void DunGeonSelect();
	void setCage(MonsterCage* cage);
	void setPlayer(Player* player);
	MonsterArray DifficultRandomMonster(int SD);
};