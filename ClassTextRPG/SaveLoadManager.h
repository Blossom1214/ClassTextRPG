#pragma once
#include "Player.h"
#include "MonsterCage.h"
#include "Shop.h"
class SaveLoadManager
{
public:
	static void SavePlayer(const Player&player);
	static void SaveMonster(const MonsterCage&cage);
	static void SaveShop(const Shop &shop);

	static void LoadPlayer(Player &player);
	static void LoadMonster(MonsterCage &cage);
	static void LoadShop(Shop &shop);

};