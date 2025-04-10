#pragma once
#include "Village.h"
#include "Player.h"
#include "MonsterCage.h"
class GameFlow //게임 시작관련 클래스
{
private:
	int _menu;
	Player* _player;
	Village _village;
	MonsterCage _cage;
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