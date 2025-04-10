#pragma once
#include "Player.h"
#include "Item.h"
#include <vector>
#include <ctime>
#include <cstdlib>
class Shop
{
private:
	
	std::vector<Item> _SellItemlist; //������ ������ ���������̳�
	Item _SellingItem; //�� ������
	bool _isInitialized = false;  //������ ���ʷ� �湮�ߴ��� �ƴ��������� ����
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
	
	//�������� �����ؾ��Ұ͵�
	//������ ���
	//�Ȱ� �ϴ°��� ���
	//���� �κ��丮���� ���
	//�����ݾ׵� ��������
	//���̾��ٸ� ���źҰ�(����ó��)
	//���������ִٸ� �ȼ��ֵ����ϰ� �����
	//�ϴ� ���ű�� ������ ����
	//�������� ä��� �ڵ�




};