#pragma once
#include "Dungeon.h"
class Village //���� ���� Ŭ����
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
public:
	void EnterVillage();
	void SetCage(MonsterCage* cage, Player* player);
};