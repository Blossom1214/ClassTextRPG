#pragma once
#include "Village.h"
#include "MonsterCage.h"
#include "SaveLoadManager.h"
class Player;
class GameFlow //���� ���۰��� Ŭ����
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