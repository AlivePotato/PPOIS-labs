﻿#include "Info.h"
using namespace std;

void Ocean_master::Beginning(int whale_amount, int shark_amount, int herring_amount, int plankton_amount)
{
	Create_vector(whale_amount, shark_amount, herring_amount, plankton_amount);
	First_location('W', whales);
	First_location('S', sharks);
	First_location('H', herrings);
	First_location('P', planktons);
	UpdateMap();
	Show();
}

void Ocean_master::Create_vector(int whale_amount, int shark_amount, int herring_amount, int plankton_amount)
{
	for (int i = 1; i <= whale_amount; i++)
	{
		if (i % 2 != 0)
		{
			Whale fish_whale_obj("Male");
			fish_whale_obj.set_id(whale_number);
			whales.push_back(fish_whale_obj);
		}
		else
		{
			Whale fish_whale_obj("Female");
			fish_whale_obj.set_id(whale_number);
			whales.push_back(fish_whale_obj);
		}
		whale_number++;
	}

	for (int i = 1; i <= shark_amount; i++)
	{
		if (i % 2 != 0)
		{
			Shark fish_shark_obj("Male");
			fish_shark_obj.set_id(shark_number);
			sharks.push_back(fish_shark_obj);
		}
		else
		{
			Shark fish_shark_obj("Female");
			fish_shark_obj.set_id(shark_number);
			sharks.push_back(fish_shark_obj);
		}
		shark_number++;
	}

	for (int i = 1; i <= herring_amount; i++)
	{
		if (i % 2 != 0)
		{
			Herring fish_herring_obj("Male");
			fish_herring_obj.set_id(herring_number);
			herrings.push_back(fish_herring_obj);
		}
		else
		{
			Herring fish_herring_obj("Female");
			fish_herring_obj.set_id(herring_number);
			herrings.push_back(fish_herring_obj);
		}
		herring_number++;
	}

	for (int i = 0; i < plankton_amount; i++)
	{
		Plankton fish_plankton_obj;
		fish_plankton_obj.set_id(plankton_number);
		planktons.push_back(fish_plankton_obj);
		plankton_number++;
	}
}

template<typename T>void  Ocean_master::First_location(char type, vector<T>& fish)
{
	for (int i = 0; i < fish.size(); i++)
	{
		vector<int> coordinates = { -1,-1,-1 };
		if (type == 'PL') Get_coordinates(true, coordinates);
		else Get_coordinates(false, coordinates);
		for (int j = 0; j < 3; j++)
			fish[i].location[j] = coordinates[j];
		ocean_table->put_fish(coordinates[0], coordinates[1], coordinates[2], type);
	}
}

void Ocean_master::Get_coordinates(bool plankton, vector<int>& coordinates)
{
	int width = ocean_table->width, height = ocean_table->height;
	int options = width * height;
	int i = rand() % width;
	int j = rand() % height;
	int k = 0;

	if (ocean_table->area[i][j][k] == ' ')
	{
		coordinates[0] = i; coordinates[1] = j; coordinates[2] = k;
		return;
	}
	while (options > 0)
	{
		for (int t = 0; t < 4; t++)
		{
			if (plankton)
				if (ocean_table->area[i][j][t] == 'P') break;
			if (ocean_table->area[i][j][t] == ' ')
			{
				coordinates[0] = i; coordinates[1] = j; coordinates[2] = t;
				return;
			}
		}
		i = rand() % width;
		j = rand() % height;
		options--;
	}
}

void Ocean_master::Move()
{
	system("cls");
	int p_count = planktons.size(), h_count = herrings.size(), w_count = whales.size(), s_count = sharks.size();

	for (int i = 0; i < p_count; i++)
		Fish_move(&planktons[i], true);
	for (int i = 0; i < p_count; i++)
	{
		bool success = false;
		Plankton_replicate(&planktons[i], success);
		if (!success) planktons[i].set_hp(planktons[i].get_m_hp());
	}
	for (int i = p_count - 1; i >= 0; i--)
		Death(&planktons[i], i, planktons, true);

	for (int i = 0; i < h_count; i++)
		Fish_move(&herrings[i], false);
	for (int i = 0; i < h_count; i++)
		Herring_eat(&herrings[i]);
	for (int i = 0; i < h_count; i++)
		Predator_replicate(&herrings[i], herrings, herring_number);
	for (int i = h_count - 1; i >= 0; i--)
		Death(&herrings[i], i, herrings, false);

	for (int i = 0; i < s_count; i++)
		Fish_move(&sharks[i], false);
	for (int i = 0; i < s_count; i++)
		Shark_eat(&sharks[i]);
	for (int i = 0; i < s_count; i++)
		Predator_replicate(&sharks[i], sharks, shark_number);
	for (int i = s_count - 1; i >= 0; --i)
		Death(&sharks[i], i, sharks, false);

	for (int i = 0; i < w_count; i++)
		Fish_move(&whales[i], false);
	for (int i = 0; i < w_count; i++)
		Whale_eat(&whales[i]);
	for (int i = 0; i < w_count; i++)
		Predator_replicate(&whales[i], whales, whale_number);
	for (int i = w_count - 1; i >= 0; --i)
		Death(&whales[i], i, whales, false);

	UpdateMap();
	Show();
}

void Ocean_master::UpdateMap()
{
	for (int i = 0; i < ocean_table->width; i++)
		for (int j = 0; j < ocean_table->height; j++)
			for (int k = 0; k < 4; k++)
				ocean_table->area[i][j][k] = ' ';

	for (int i = 0; i < planktons.size(); i++)
		ocean_table->area[planktons[i].location[0]][planktons[i].location[1]][planktons[i].location[2]] = 'P';
	for (int i = 0; i < herrings.size(); i++)
		ocean_table->area[herrings[i].location[0]][herrings[i].location[1]][herrings[i].location[2]] = 'H';
	for (int i = 0; i < whales.size(); i++)
		ocean_table->area[whales[i].location[0]][whales[i].location[1]][whales[i].location[2]] = 'W';
	for (int i = 0; i < sharks.size(); i++)
		ocean_table->area[sharks[i].location[0]][sharks[i].location[1]][sharks[i].location[2]] = 'S';
}

void Ocean_master::Show()
{
	for (int i = 0; i < ocean_table->width; i++)
		cout << "------";
	cout << "-" << endl;
	for (int i = 0; i < ocean_table->height; i++)
	{
		cout << "|";
		for (int j = 0; j < ocean_table->width; j++)
			cout << " " << ocean_table->area[j][i][0] << " " << ocean_table->area[j][i][1] << " |";
		cout << endl << "|";
		for (int j = 0; j < ocean_table->width; j++)
			cout << " " << ocean_table->area[j][i][2] << " " << ocean_table->area[j][i][3] << " |";
		cout << endl << "-";
		for (int j = 0; j < ocean_table->width; j++)
			cout << "------";
		cout << endl;
	}
}

int Ocean_master::empty_place(int x, int y, bool plankton)
{
	if ((x < 0) || (y < 0) || (x >= ocean_table->width) || (y >= ocean_table->height))
		return -1;//âûõîä çà ãðàíèöû ïîëÿ
	if (plankton)
	{
		for (int i = 0; i < planktons.size(); i++)
		{
			if ((planktons[i].location[0] == x) && (planktons[i].location[1] == y))
				return -2; //åñòü ïëàíêòîí
		}
	}
	for (int i = 0; i < 4; i++)
		if (ocean_table->area[x][y][i] == ' ')
			return i;// åñòü ìåñòî
	return -1;//íåò ìåñòà
}


void  Ocean_master::Place_planktons_child(int new_x, int new_y, bool& success)
{

	int index_plankton = empty_place(new_x, new_y, 1);
	if (index_plankton >= 0)
	{
		Plankton planktonchik;
		planktonchik.location[0] = new_x;
		planktonchik.location[1] = new_y;
		planktonchik.location[2] = index_plankton;
		planktonchik.set_id(plankton_number);
		plankton_number++;
		planktons.push_back(planktonchik);
		ocean_table->area[planktonchik.location[0]][planktonchik.location[1]][planktonchik.location[2]] = 'P';
		success = true;
		return;
	}
	if (index_plankton == -2)
	{
		for (int i = 0; i < planktons.size(); i++)
			if ((planktons[i].location[0] == new_x) && (planktons[i].location[1] == new_y))
				planktons[i].set_hp(planktons[i].get_m_hp());
		success = true;
		return;
	}
}

void Ocean_master::Plankton_replicate(Plankton* plankton, bool& success)
{
	int x = plankton->location[0], y = plankton->location[1];
	for (int direction = 0; direction < 4; direction++)
	{
		switch (direction)
		{
		case(0): //âåðõ
		{Place_planktons_child(x, y - 1, success);
		if (success) return; }
		break;
		case(1): //íèç
		{Place_planktons_child(x, y + 1, success);
		if (success) return; }
		break;
		case(2): //ëåâî
		{Place_planktons_child(x - 1, y, success);
		if (success) return; }
		break;
		case(3): //ïðàâî
		{Place_planktons_child(x + 1, y, success);
		if (success)return; }
		break;
		}
	}
}

template<typename T> void Ocean_master::Death(T* org, int index, vector<T>& fish, bool plankton)
{
	org->set_age(org->get_age() + 1);
	int damage_hp = round(org->get_hp() * 0.1);
	org->set_hp(org->get_hp() - damage_hp);
	if (!plankton)
		org->set_food(org->get_food() - 1);
	if ((org->get_hp() <= 0) || (org->get_food() <= 0) || (org->get_age() == org->get_m_age()))
	{
		ocean_table->area[org->location[0]][org->location[1]][org->location[2]] = ' ';
		fish.erase(fish.begin() + index);
	}
}

template<typename T> void Ocean_master::Fish_move(T* org, bool plankton)
{
	int x = org->location[0], y = org->location[1];
	Moving(org, x, y, plankton);
	ocean_table->area[org->location[0]][org->location[1]][org->location[2]] = org->get_type();
}

template<typename T> void  Ocean_master::Moving(T* org, int x, int y, bool plankton)
{
	while (1)
	{

		int direction = rand() % 4;
		int m = rand() % org->get_moves() + 1;
		if ((empty_place(x, y - m, plankton) < 0) && (empty_place(x, y + m, plankton) < 0) && (empty_place(x - m, y, plankton) < 0) && (empty_place(x + m, y, plankton) < 0)) { break; }
		switch (direction)
		{
		case(0): //âåðõ
		{
			int  i = empty_place(x, y - m, plankton);
			if (i >= 0)
			{
				org->location[1] = (y - m);
				org->location[2] = i;
				return;
			}
		}
		break;
		case(1): //íèç
		{
			int  i = empty_place(x, y + m, plankton);
			if (i >= 0)
			{
				org->location[1] = y + m;
				org->location[2] = i;
				return;
			}
		}
		break;
		case(2): //ëåâî
		{
			int  i = empty_place(x - m, y, plankton);
			if (i >= 0)
			{
				org->location[0] = x - m;
				org->location[2] = i;
				return;
			}
		}
		break;
		case(3): //ïðàâî
		{
			int  i = empty_place(x + m, y, plankton);
			if (i >= 0)
			{
				org->location[0] = (x + m);
				org->location[2] = i;
				return;
			}
		}
		break;
		}
	}
}


template<typename T> void Ocean_master::Predator_replicate(T* predator, vector<T>& predators, int& fish_number)
{
	if (predator->get_hp() <= 0)
		return;
	char type = predator->get_type();
	int x = predator->location[0], y = predator->location[1], z;

	for (int i = 0; i < predators.size(); i++)
	{
		if ((predators[i].location[0] == x) && (predators[i].location[1] == y) && (predators[i].get_hp() > 0))
		{
			if (predator->get_is_male() == predators[i].get_is_male())
				return;
			z = empty_place(x, y, 0);
			if (z == -1)
				return;
			else
			{
				if (type == 'S')
				{
					Shark child("Random");
					child.set_id(shark_number);
					shark_number++;
					child.location[0] = x;
					child.location[1] = y;
					child.location[2] = z;
					ocean_table->area[child.location[0]][child.location[1]][child.location[2]] = type;
					sharks.push_back(child);
				}
				if (type == 'W')
				{
					Whale child("Random");
					child.set_id(whale_number);
					whale_number++;
					child.location[0] = x;
					child.location[1] = y;
					child.location[2] = z;
					ocean_table->area[child.location[0]][child.location[1]][child.location[2]] = type;
					whales.push_back(child);
				}
				if (type == 'H')
				{
					Herring child("Random");
					child.set_id(herring_number);
					herring_number++;
					child.location[0] = x;
					child.location[1] = y;
					child.location[2] = z;
					ocean_table->area[child.location[0]][child.location[1]][child.location[2]] = type;
					herrings.push_back(child);
				}
			}
		}
	}
}

void Ocean_master::Herring_eat(Herring* herring)
{
	int x = herring->location[0], y = herring->location[1];
	for (int i = 0; i < planktons.size(); i++)
	{
		if (herring->get_food() == herring->get_m_food())
			return;
		if ((planktons[i].location[0] == x) && (planktons[i].location[1] == y))
		{
			herring->set_food(herring->get_m_food());
			if (herring->get_hp() + planktons[i].get_hp() >= herring->get_m_hp())
				herring->set_hp(herring->get_m_hp());
			else herring->set_hp(herring->get_hp() + planktons[i].get_hp());
			ocean_table->area[planktons[i].location[0]][planktons[i].location[1]][planktons[i].location[2]] = ' ';
			planktons.erase(planktons.begin() + i);
		}
	}
}

void Ocean_master::Whale_eat(Whale* whale)
{
	int x = whale->location[0], y = whale->location[1];

	for (int i = 0; i < planktons.size(); i++)
	{
		if (whale->get_food() == whale->get_m_food())
			return;
		if ((planktons[i].location[0] == x) && (planktons[i].location[1] == y))
		{
			whale->set_food(whale->get_m_food());
			if (whale->get_hp() + planktons[i].get_hp() >= whale->get_m_hp())
				whale->set_hp(whale->get_m_hp());
			else whale->set_hp(whale->get_hp() + planktons[i].get_hp());
			ocean_table->area[planktons[i].location[0]][planktons[i].location[1]][planktons[i].location[2]] = ' ';
			planktons.erase(planktons.begin() + i);
		}
	}

	for (int i = 0; i < herrings.size(); i++)
	{
		if (whale->get_food() == whale->get_m_food())
			return;
		if ((herrings[i].location[0] == x) && (herrings[i].location[1] == y))
		{
			whale->set_food(whale->get_m_food());
			if (whale->get_hp() + herrings[i].get_hp() >= whale->get_m_hp())
				whale->set_hp(whale->get_m_hp());
			else whale->set_hp(whale->get_hp() + herrings[i].get_hp());
			ocean_table->area[herrings[i].location[0]][herrings[i].location[1]][herrings[i].location[2]] = ' ';
			herrings.erase(herrings.begin() + i);
		}
	}
}

void Ocean_master::Shark_eat(Shark* shark)
{
	int x = shark->location[0], y = shark->location[1];
	for (int i = 0; i < herrings.size(); i++)
	{
		if (shark->get_food() == shark->get_m_food())
			return;
		if ((herrings[i].location[0] == x) && (herrings[i].location[1] == y))
		{
			shark->set_food(shark->get_m_food());
			if (shark->get_hp() + herrings[i].get_hp() >= shark->get_m_hp())
				shark->set_hp(shark->get_m_hp());
			else shark->set_hp(shark->get_hp() + herrings[i].get_hp());
			ocean_table->area[herrings[i].location[0]][herrings[i].location[1]][herrings[i].location[2]] = ' ';
			herrings.erase(herrings.begin() + i);
		}
	}
}
