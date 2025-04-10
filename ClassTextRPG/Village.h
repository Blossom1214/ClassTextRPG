#pragma once
#include "Dungeon.h"
#include "Shop.h"
class Village //마을 관련 클래스
{
private:
	enum villageSection
	{
		_Dungeon = 1,
		_Shop,
		_refinery,
		_Save,
		_GameEnd
	};
	Dungeon _Dungeon1;
	Shop _Shop1;
public:
	void EnterVillage();
	void SetObject(MonsterCage* cage, Player* player);
};