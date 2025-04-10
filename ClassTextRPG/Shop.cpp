#include "Shop.h"
#include "GameObject.h"
#include <iostream>

using namespace std;
Shop::Shop() :_SellItemlist(),_SellingItem(),_player(nullptr)
{
	_SellItemlist.reserve(5); //����Ȯ���� reserve
}

void Shop::ShopSettingSellingItem()
{
    srand(static_cast<unsigned>(time(0))); 

    for (int i = 0; i < 5; ++i)
    {
        int randomNum = rand() % 3;

        Item newItem;

        if (randomNum == 0)
        {
            newItem = _SellingItem.SetName("ȸ������").SetSellItemMoney(100);
        }
        else if (randomNum == 1)
        {
            newItem = _SellingItem.SetName("����").SetSellItemMoney(800);
        }
        else
        {
            newItem = _SellingItem.SetName("��").SetSellItemMoney(600);
        }


        _SellItemlist.push_back(newItem);
    }

}
void Shop::SetShopPlayer(Player* player)
{
    _player = player;
}
void Shop::ShowItemlist()const 
{
    GameObject::PrintMsg("�����ǸŸ���Դϴ�");
    for (int i = 0; i < _SellItemlist.size(); ++i)
    {
        cout << i + 1 << "." << " �������̸�: " << _SellItemlist[i].GetName() << " �Ǹűݾ�: " << _SellItemlist[i].GetSellItemMoney() << endl;
    }
}
void Shop::BuyItem()
{
    int isChoice;
    GameObject::PrintMsg("������ �������� �����ϼ���");
    cout << "1) 2) 3) 4) 5) 6)�������" << endl;
    
    cin >> isChoice;
    isChoice--;
    if (isChoice >= 0 && isChoice <_SellItemlist.size())//��ȣ��������
    {
        Item SelectingItem = _SellItemlist[isChoice];//���� ����ȣ�� �������� ����(�κ��丮�� �ƴ϶� �ٸ� itemŸ���� ������ ����)
        if (_player->Getgold() >= SelectingItem.GetSellItemMoney())//���ſ� ����������!(�÷��̾��� ��差�� ������ �����ٰ��ų�Ŭ��)
        {
            _player->AddItemToInventory(SelectingItem);//�÷��̾� �κ��丮�� �ش簪�� Ǫ����
            _player->Minusgold(SelectingItem.GetSellItemMoney());//�÷��̾ ������ ��忡�� �ش簡������..
            _SellItemlist.erase(_SellItemlist.begin() + isChoice);//���ſ� �����ϸ� �ش� ������ġ�� ����� �ڿ��ִ� ���� ���ܾ���
            cout << SelectingItem.GetName() << " �� �����߽��ϴ�." << endl;
            cout << " ���� ������: " << _player->Getgold() << endl;
        }
        else
        {
            cout << "������ �ݾ��� �����մϴ�." << endl;
            return;
        }

    }
    else if (isChoice == 6)
    {
        cout << "���Ÿ� ����ϼ˽��ϴ�" << endl;
        return;
    }
    else
    {
        cout << "�߸��� ���� �Է��ϼ˽��ϴ�." << endl;
        return;
    }
}
void Shop::ShopSelect() 
{
    bool isShopStay = true;
    while (isShopStay)
    {
        if (_isInitialized == false)
        {
            ShopSettingSellingItem();
            _isInitialized = true;
        }
        GameObject::PrintMsg("������ �����߽��ϴ�.");
        int isSelect;
        bool isShopIn = true;
        while (isShopIn)
        {
            GameObject::PrintMsg("1)���� 2)�Ǹ� 3)�κ��丮 �� ������ Ȯ�� 4)�ڷΰ���");
            cin >> isSelect;

            switch (isSelect)
            {
            case 1:
                ShowItemlist();
                BuyItem();
                isShopIn = true;
                break;
            case 2:
                cout << "�̱����Ǿ��ֽ��ϴ� ������ ���ư��ϴ�" << endl;
                return;
            case 3:
                cout << "�κ��丮�� �������� Ȯ���մϴ�." << endl;
                _player->ShowInventorys();
                cout << "�÷��̾�� ����: " << _player->Getgold() << " ������ �Դϴ�." << endl;
                isShopIn = true;
                break;
            case 4:
                cout << "������ ���ư��ϴ�!" << endl;
                isShopIn =false;
                isShopStay = false;
                break; 
            default:
                cout << "�߸��� �Է��Դϴ� �ٽ��Է����ּ���" << endl;
                isShopIn = true;
                break;
            }
        }
    }
}
