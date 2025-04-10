#include "Shop.h"

using namespace std;
Shop::Shop() :_SellItemlist(),_SellingItem()
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
           


        }


        _SellItemlist.push_back(newItem);
    }

}