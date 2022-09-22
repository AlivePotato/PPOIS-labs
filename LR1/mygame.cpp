///\file mygame.cpp
/// \brief ���������� ������� ������� Puzzle � Menu


/** @defgroup mygame mygame.cpp
 * ������� ������� � ����
 * @{
 */
#include "mygame.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <algorithm>

Puzzle::Puzzle()
{
	list_filling();
	do
	{
		shuffling();
	} while (!is_it_solvable());
	board_filling();
	x_location();
}

//vector<string> Puzzle::getList() { return list; }
//
//vector<vector<string>> Puzzle::getBoard() { return board; }

void Puzzle::shuffling()
{
	random_shuffle(begin(list), end(list));
}

bool Puzzle::is_it_solvable()
{
	int e;
	int res = 0;
	for (int i = 0; i < list_size; i++)
	{
		if (list[i] == 0)
			e = i / board_size + 1;
	}
	for (int i = 0; i < list_size - 1; i++)
	{
		for (int j = i + 1; j < list_size; j++)
		{
			if (list[j] < list[i] && list[j] != 0)
				res++;
		}
	}
	res += e;
	return (res % 2 == 0) ? true : false;
}

bool Puzzle::checker()
{
	return (game_board == solved_puzzle) ? true : false;
}

void Puzzle::list_filling()
{
	for (int i = 0; i < list_size; i++)
	{
		list.push_back(i);
	}
}

void Puzzle::board_filling()
{
	int k = 0;
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			game_board[i][j] = list[k];
			k++;
		}
	}
}


void Puzzle::x_location()
{
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (game_board[i][j] == 0)
			{
				X_x = i; X_y = j;
			}
		}
	}
}

void Puzzle::move()
{
	char ch = 0;
	ch = _getch();
	switch (ch)
	{
	case 'W':
	case 'w':
		if (X_x != 3)
		{
			swap(game_board[X_x][X_y], game_board[X_x + 1][X_y]);
			X_x += 1;
		}
		break;
	case 'A':
	case 'a':
		if (X_y != 3)
		{
			swap(game_board[X_x][X_y], game_board[X_x][X_y + 1]);
			X_y += 1;
		}
		break;
	case 's':
	case 'S':
		if (X_x != 0)
		{
			swap(game_board[X_x][X_y], game_board[X_x - 1][X_y]);
			X_x -= 1;
		}
		break;
	case 'D':
	case 'd':
		if (X_y != 0)
		{
			swap(game_board[X_x][X_y], game_board[X_x][X_y - 1]);
			X_y -= 1;
		}
		break;
	}
}


ostream& operator << (ostream& s, Puzzle& p) {

	for (int i = 0; i < p.board_size; i++)
	{
		for (int j = 0; j < p.board_size; j++)
		{
			if (p.game_board[i][j] == 0)
				s << " " << '\t';
			else
				s << p.game_board[i][j] << '\t';
		}
		s << '\v';
	}
	return s;
}

int& Puzzle::operator[](const int n)
{
	if (n < 0 || n >= list_size)
		throw exception();
	return list[n];
}

void Menu::end_of_the_game()
{
	cout << "�����������, �� ������� �����������!!!" << endl << endl << endl << endl;
	cout << " ������� �������, ����� ����� � ����" << endl << "q - ����� �� ����������" << endl;
	int x = _getch();
	if (x == 'q')
		exit(0);
}

Puzzle::~Puzzle() {}

void Menu::setCh(int ch)
{
	this->ch = ch;
}

void Menu::start_menu()
{
	int ch;
	cout << "1. ��������� ����" << endl
		<< "2. ������� ����" << endl
		<< "3. �����" << endl;
	cin >> ch;
	setCh(ch);
	switch (ch)
	{
	case 1:
		system("cls");
		break;
	case 2:
		system("cls");
		conditions_of_the_game();
		break;
	case 3:
		system("cls");
		exit(0);
	default:
		break;
	}
}

void Menu::conditions_of_the_game()
{
	cout << "�������� - ���� �� ������������� � ���� �����������.��� ������ ����� ��������, � ������� ������ ���������� �������,����� ������� ��������� 4 ������ ��������, �� ���� 4�4." << endl <<
		"� ������ ���� ������� 15 ���������� �����.� ������� �������� ���� ������ ����� ��� ���� �����." << endl <<
		"������ ���� - �������������� ����� �� �������.������ ���� ����� ���������, ��������� �������� �� 1 �� 15 ���� �� ������." << endl << endl << endl;
	cout << "������� ����� �������, ����� ����� � ����" << endl;
	int x = _getch();
	system("cls");
	start_menu();
}