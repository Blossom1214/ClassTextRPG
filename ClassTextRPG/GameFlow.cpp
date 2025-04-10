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
		cout << "====== ���� ���� �޴� ======" << endl;
		cout << "1. �� ���� ����" << endl;
		cout << "2. �ҷ�����" << endl;
		cout << "3. ���� ����" << endl;
		cout << "����: ";
		cin >> _menu;
		cout << endl;
		switch (static_cast<StartSelect>(_menu))
		{
		case StartSelect::_start:
			cout << "�� ���� ����!" << endl;
			system("pause");
			_player = new Player();
			_player->SelectPlayerJob();
			_cage.MonsterCreateRoutine();
			_village.SetObject(&_cage, _player);// ������ ������ �������� ���� �������� ����Ҽ� �ֵ��� ��������
			_village.EnterVillage();

			isGameRunning = false;
			break;


		case StartSelect::_reload:
			cout << "���� �ҷ�����" << endl;
			system("pause");
			isGameRunning = false;
			break;


		case StartSelect::_endGame:
			cout << "������ �����մϴ�!" << endl;
			system("pause");
			isGameRunning = false;
			exit(0);
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�!" << endl;
			system("pause");
			break;
		}
	}

}