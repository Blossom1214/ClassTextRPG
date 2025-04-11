#pragma once
#include "Player.h"
#include "Item.h"
#include <vector>
#include <ctime>
#include <cstdlib>
class Shop
{
private:
	
	std::vector<Item> _SellItemlist; //상점의 아이템 벡터컨테이너
	Item _SellingItem; //팔 아이템
	bool _isInitialized = false;  //상점에 최초로 방문했는지 아닌지에대한 여부
	Player* _player;
public:
	Shop();
private:
	void ShopSettingSellingItem();
public:
	void SetShopPlayer(Player* player);
	void ShowItemlist()const;
	void BuyItem();
	void ShopItemRefill();
	void ShopSelect();
	const std::vector<Item>& GetSellItemlist() const;
	void ShopItemlistClear();
	void AddSellItemlist(Item& item);
	void LoadFinished();
	//상점에서 구현해야할것들
	//팔고 하는것이 기능(아직 미구현)
	//아이템이있다면 팔수있도록하게 만들기 (미구현)




};