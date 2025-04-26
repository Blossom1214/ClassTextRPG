#pragma once
#include "Village.h"
#include "MonsterCage.h"
#include "SaveLoadManager.h"
class Player;
class GameFlow //게임 시작관련 클래스
{
private:
	int _menu;
	Player* _player;
	Village _village;
	MonsterCage _cage;
	Shop _Shop1;
	enum class StartSelect : int
	{
		_start = 1,
		_reload = 2,
		_endGame = 3
	};
public:
	GameFlow();
	~GameFlow();
public:
	void SelectStartMenu();
};