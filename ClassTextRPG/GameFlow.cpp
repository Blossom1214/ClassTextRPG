#include "GameFlow.h"
#include "GameObject.h"
#include <iostream>
#include <cstdlib>
using namespace std;
GameFlow::GameFlow() : _menu(0), _player(nullptr), _village()
{

}
GameFlow::~GameFlow()
{
	if (_player)
	{
		delete _player;
	}
}
void GameFlow::SelectStartMenu()
{
	bool  isGameRunning = true;
	while (isGameRunning)
	{
		system("cls");
		cout << "====== 게임 시작 메뉴 ======" << endl;
		cout << "1. 새 게임 시작" << endl;
		cout << "2. 불러오기" << endl;
		cout << "3. 게임 종료" << endl;
		cout << "선택: ";
		cin >> _menu;
		cout << endl;
		switch (static_cast<StartSelect>(_menu))
		{
		case StartSelect::_start:
			cout << "새 게임 시작!" << endl;
			system("pause");
			_player = new Player();
			_player->SelectPlayerJob();
			_cage.MonsterCreateRoutine();
			_village.SetObject(&_cage, _player);// 위에서 생성한 케이지의 값을 던전에서 사용할수 있도록 연결해줌
			_village.EnterVillage();

			isGameRunning = false;
			break;


		case StartSelect::_reload:
			cout << "게임 불러오기" << endl;
			system("pause");
			isGameRunning = false;
			break;


		case StartSelect::_endGame:
			cout << "게임을 종료합니다!" << endl;
			system("pause");
			isGameRunning = false;
			exit(0);
			break;
		default:
			cout << "잘못 입력하셨습니다!" << endl;
			system("pause");
			break;
		}
	}

}