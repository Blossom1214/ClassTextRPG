#include "Shop.h"
#include "GameObject.h"
#include <iostream>

using namespace std;
Shop::Shop() :_SellItemlist(),_SellingItem(),_player(nullptr)
{
	_SellItemlist.reserve(5); //공간확보는 reserve
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
            newItem = _SellingItem.SetName("회복포션").SetSellItemMoney(100);
        }
        else if (randomNum == 1)
        {
            newItem = _SellingItem.SetName("무기").SetSellItemMoney(800);
        }
        else
        {
            newItem = _SellingItem.SetName("방어구").SetSellItemMoney(600);
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
    GameObject::PrintMsg("상점판매목록입니다");
    for (int i = 0; i < _SellItemlist.size(); ++i)
    {
        cout << i + 1 << "." << " 아이템이름: " << _SellItemlist[i].GetName() << " 판매금액: " << _SellItemlist[i].GetSellItemMoney() << endl;
    }
}
void Shop::BuyItem()
{
    int isChoice;
    GameObject::PrintMsg("구매할 아이템을 선택하세요");
    cout << "1) 2) 3) 4) 5) 6)구매취소" << endl;
    
    cin >> isChoice;
    isChoice--;
    if (isChoice >= 0 && isChoice <_SellItemlist.size())//번호선택조건
    {
        Item SelectingItem = _SellItemlist[isChoice];//내가 고른번호의 아이템을 담음(인벤토리가 아니라 다른 item타입의 변수에 담음)
        if (_player->Getgold() >= SelectingItem.GetSellItemMoney())//구매에 성공했을때!(플레이어의 골드량이 물건의 값보다같거나클때)
        {
            _player->AddItemToInventory(SelectingItem);//플레이어 인벤토리에 해당값을 푸시함
            _player->Minusgold(SelectingItem.GetSellItemMoney());//플레이어가 소유한 골드에서 해당가격을뺌..
            _SellItemlist.erase(_SellItemlist.begin() + isChoice);//구매에 성공하면 해당 벡터위치를 지우고 뒤에있던 값을 땡겨야함
            cout << SelectingItem.GetName() << " 을 구매했습니다." << endl;
            cout << " 남은 소지금: " << _player->Getgold() << endl;
        }
        else
        {
            cout << "보유한 금액이 부족합니다." << endl;
            return;
        }

    }
    else if (isChoice == 6)
    {
        cout << "구매를 취소하셧습니다" << endl;
        return;
    }
    else
    {
        cout << "잘못된 값을 입력하셧습니다." << endl;
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
        GameObject::PrintMsg("상점에 입장했습니다.");
        int isSelect;
        bool isShopIn = true;
        while (isShopIn)
        {
            GameObject::PrintMsg("1)구매 2)판매 3)인벤토리 및 소지금 확인 4)뒤로가기");
            cin >> isSelect;

            switch (isSelect)
            {
            case 1:
                ShowItemlist();
                BuyItem();
                isShopIn = true;
                break;
            case 2:
                cout << "미구현되어있습니다 마을로 돌아갑니다" << endl;
                return;
            case 3:
                cout << "인벤토리와 소지금을 확인합니다." << endl;
                _player->ShowInventorys();
                cout << "플레이어는 현재: " << _player->Getgold() << " 보유중 입니다." << endl;
                isShopIn = true;
                break;
            case 4:
                cout << "마을로 돌아갑니다!" << endl;
                isShopIn =false;
                isShopStay = false;
                break; 
            default:
                cout << "잘못된 입력입니다 다시입력해주세요" << endl;
                isShopIn = true;
                break;
            }
        }
    }
}
