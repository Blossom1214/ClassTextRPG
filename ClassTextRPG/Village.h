#pragma once
#include "Dungeon.h"
#include "Shop.h"
#include "SaveLoadManager.h"
#include "Player.h"
class Village //���� ���� Ŭ����
{
private:
	enum villageSection
	{
		_Dungeon = 1,
		_Shop,
		_refinery,
		_InventoryCheck,
		_Save,
		_GameEnd
	};
	Dungeon _Dungeon1;
	Shop _Shop1;
	Player* _player;
	MonsterCage* _Cage;
public:
	void EnterVillage();
	void SetObject(MonsterCage* cage, Player* player);
	void Save()const;
};