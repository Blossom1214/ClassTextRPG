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
		GameObject::PrintMsg("상대할 몬스터의 정보는");
		monster.InfoPrint();
		cout << "기대 획득 골드량은: " << monster.Getlevel() * 10;

		bool isCheckFight = true;
		while (isCheckFight)
		{
			cout << "\n플레이어의 차례입니다!" << endl;
			cout << "1. 공격" << endl;
			cout << "2. 포션 사용 (아직 미구현)" << endl;
			cout << "3. 도망가기 50%의 확률" << endl;
			cout << "선택: ";
			int pChoice;
			cin >> pChoice;

			switch (pChoice)
			{
			case 1:
				monster.SetHp(monster.GetHp() - player.GetAttack());
				cout << "플레이어가 몬스터를 공격합니다!" << endl;
				cout << "몬스터 체력: " << monster.GetHp() << endl;

				if (monster.GetHp() <= 0)
				{
					monster.SetHp(0);
					player.Addgold(monster.Getlevel() * 10); // 보상 골드 획득로직
					GameObject::PrintMsg("몬스터를 처치했습니다!");
					cout << monster.Getlevel() * 10 << " 에 해당하는 골드를 획득했습니다";
					system("pause");

					monsterInfo.monster.erase(monsterInfo.monster.begin() + monsterInfo._RandIdx);

					char choice;
					GameObject::PrintMsg("다음몬스터와 싸우겠습니까? Y/N");
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
						cout << "잘못 입력했습니다 자동으로 뒤로갑니다!" << endl;
						_reFight = false;
						isCheckFight = false;
						isFighting = false;
						break;
					}
						//몬스터가 죽었음으로 해당 배열의 칸의 정보를 제거해야함
						//즉 플레이어가 승리한상황임 보상과 함께 더싸울건지 마을로 되돌아갈껀지에대해 필요함	
					continue;
				}
				player.SetHp(player.GetHp() -= monster.GetAttack());
				cout << "몬스터가 플레이어를 공격합니다!" << endl;
				cout << "플레이어 체력: " << player.GetHp() << endl;
				if (player.GetHp() <= 0)
				{
					player.SetHp(0);
					GameObject::PrintMsg("플레이어가 쓰러졌습니다...");
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
					GameObject::PrintMsg("도망에 성공하셧습니다!");
					_reFight = false;
					isCheckFight = false;
					isFighting = false;
					break;
				}
				else
				{
					GameObject::PrintMsg("몬스터가 플레이어를 도망가지 못하게 막습니다!");
					player.SetHp(player.GetHp() -= monster.GetAttack());
					cout << "몬스터가 플레이어를 공격합니다!" << endl;
					cout << "플레이어 체력: " << player.GetHp() << endl;
					if (player.GetHp() <= 0)
					{
						player.SetHp(0);
						GameObject::PrintMsg("플레이어가 쓰러졌습니다...");
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
				cout << "잘못된 입력입니다!" << endl;
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
