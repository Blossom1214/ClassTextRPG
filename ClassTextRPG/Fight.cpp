#include "Fight.h"
#include <iostream>
using namespace std;

Fight::Fight() : _reFight(true) {}
void Fight::IsFight(Player& player, MonsterArray& monsterInfo)
{
	bool isFighting = true;
	_reFight = true;
	while (isFighting)
	{
		system("cls");
		Monster& monster = monsterInfo._randommonster;
		GameObject::PrintMsg("����� ������ ������");
		monster.InfoPrint();
		cout << "��� ȹ�� ��差��: " << monster.Getlevel() * 10;

		bool isCheckFight = true;
		while (isCheckFight)
		{
			cout << "\n�÷��̾��� �����Դϴ�!" << endl;
			cout << "1. ����" << endl;
			cout << "2. ���� ��� (���� �̱���)" << endl;
			cout << "3. �������� 50%�� Ȯ��" << endl;
			cout << "����: ";
			int pChoice;
			cin >> pChoice;

			switch (pChoice)
			{
			case 1:
				monster.SetHp(monster.GetHp() - player.GetAttack());
				cout << "�÷��̾ ���͸� �����մϴ�!" << endl;
				cout << "���� ü��: " << monster.GetHp() << endl;

				if (monster.GetHp() <= 0)
				{
					monster.SetHp(0);
					player.Addgold(monster.Getlevel() * 10); // ���� ��� ȹ�����
					GameObject::PrintMsg("���͸� óġ�߽��ϴ�!");
					cout << monster.Getlevel() * 10 << " �� �ش��ϴ� ��带 ȹ���߽��ϴ�";
					system("pause");

					monsterInfo.monster.erase(monsterInfo.monster.begin() + monsterInfo._RandIdx);

					char choice;
					GameObject::PrintMsg("�������Ϳ� �ο�ڽ��ϱ�? Y/N");
					cin >> choice;

					if (choice == 'y' || choice == 'Y')
					{
						_reFight = true;
						isCheckFight = false;
						isFighting = false;
						break;
					}
					else if (choice == 'n' || choice == 'N')
					{
						_reFight = false;
						isCheckFight = false;
						isFighting = false;
						break;
					}
					else
					{
						cout << "�߸� �Է��߽��ϴ� �ڵ����� �ڷΰ��ϴ�!" << endl;
						_reFight = false;
						isCheckFight = false;
						isFighting = false;
						break;
					}
						//���Ͱ� �׾������� �ش� �迭�� ĭ�� ������ �����ؾ���
						//�� �÷��̾ �¸��ѻ�Ȳ�� ����� �Բ� ���ο���� ������ �ǵ��ư����������� �ʿ���	
					continue;
				}
				player.SetHp(player.GetHp() -= monster.GetAttack());
				cout << "���Ͱ� �÷��̾ �����մϴ�!" << endl;
				cout << "�÷��̾� ü��: " << player.GetHp() << endl;
				if (player.GetHp() <= 0)
				{
					player.SetHp(0);
					GameObject::PrintMsg("�÷��̾ ���������ϴ�...");
					system("pause");
					_reFight = false;
					isCheckFight = false;
					isFighting = false;
					break;
				}
				break;
			case 2:
				break;
			case 3:
			{
				int RunningChance = rand() % 100;
				if (RunningChance < 50)
				{
					GameObject::PrintMsg("������ �����ϼ˽��ϴ�!");
					_reFight = false;
					isCheckFight = false;
					isFighting = false;
					break;
				}
				else
				{
					GameObject::PrintMsg("���Ͱ� �÷��̾ �������� ���ϰ� �����ϴ�!");
					player.SetHp(player.GetHp() -= monster.GetAttack());
					cout << "���Ͱ� �÷��̾ �����մϴ�!" << endl;
					cout << "�÷��̾� ü��: " << player.GetHp() << endl;
					if (player.GetHp() <= 0)
					{
						player.SetHp(0);
						GameObject::PrintMsg("�÷��̾ ���������ϴ�...");
						system("pause");
						_reFight = false;
						isCheckFight = false;
						isFighting = false;
						break;
					}
				}
				system("pause");
				break;
			}
			default:
				cout << "�߸��� �Է��Դϴ�!" << endl;
				system("pause");
				break;
			}
			
		}
		
	}

}
bool Fight::ShouldContinue() const
{
	return _reFight;
}
