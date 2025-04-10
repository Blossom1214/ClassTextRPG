#include "Player.h"
#include <iostream>
using namespace std;
Player::Player() : Creature(" ", 0, 0, 0), _type(0), _gold(0),_playerInventory()
{
}
void Player::SelectPlayerJob()
{
	bool isChoice = true;
	while (isChoice)	
	{
		system("cls");
		cout << "������ ������ �ּ���!" << endl;
		GameObject::PrintMsg("1)���� 2)������ 3)�ü�");
		cin >> _type;
		switch (static_cast<Jobtype>(_type))
		{
		case Jobtype::PT_War:
			this->_hp = 100;
			this->_attack = 10;
			this->_name = "����";
			this->_level = 1;
			isChoice = false;
			break;
		case Jobtype::PT_Mage:
			this->_hp = 80;
			this->_attack = 20;
			this->_name = "������";
			this->_level = 1;
			isChoice = false;
			break;
		case Jobtype::PT_Archer:
			this->_hp = 60;
			this->_attack = 30;
			this->_name = "�ü�";
			this->_level = 1;
			isChoice = false;
			break;
		default:
			GameObject::PrintMsg("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.");
			system("pause");
			break;
		}
	}
	InfoPrint();
	cout << "\n������ �����մϴ�!" << endl;
	system("pause");
}
int& Player::Getgold()
{
	return _gold;
}
void Player::Addgold(int addgold)
{
	_gold += addgold;
}
void Player::Minusgold(int minusgold)
{
	_gold -= minusgold;
}
void Player::InfoPrint()
{

	cout << "������: " << _name << " ü����: " << _hp << " ���ݷ���: " << _attack << " ������: " << _level;
}
void Player::AddItemToInventory(const Item& item)
{
	_playerInventory.AddItem(item);
}
void Player::ShowInventorys()const
{
	_playerInventory.ShowInventory();
}
