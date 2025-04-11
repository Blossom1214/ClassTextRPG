#pragma once
#include "GameObject.h"
#include "Creature.h"
#include "Inventory.h"
#include <string>
class Player :public Creature //플레이어 클래스 플레이어의 관련된 정보들
{
private:
	int _type;
	int _gold;
	Inventory _playerInventory;
	enum class Jobtype
	{
		PT_War = 1,
		PT_Mage,
		PT_Archer
	};
public:
	Player();
public:
	void SelectPlayerJob();
	int& GetGold();
	void Addgold(int addgold);
	void Minusgold(int minusgold);
	void InfoPrint() override;
	void AddItemToInventory(const Item& iTem);
	void ShowInventorys()const;
	int Getgold()const;
	const Inventory& GetInventory() const;
	void Setgold(int gold);
	void SetItem(int row, int col, const Item& item);
};