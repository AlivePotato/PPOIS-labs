#include "Menu.h"

using std::cout;
using std::cin;
using std::string;

Menu::Menu(ModelMap &obj) : map(obj)
{};

void Menu::start()
{
	for (int i = 0; i < map.getTrains().size(); ++i)
	{
		cout << "����� #" << map.getTrains()[i]->getCurrentLocomotive().getLocomotiveNumber() << "\n";
		cout << "���������:\n" << "������� ����: " << map.getTrains()[i]->getCurrentLocomotive().getTractiveForce() << "\n";
		cout << "����� �����: " << map.getTrains()[i]->getCurrentLocomotive().getLifeTime() << "\n";
		cout << "������:\n";
		cout << "���������:\n";
		for (int j = 0; j < map.getTrains()[i]->getCurrentChain().getTrainCarList(1).size(); ++j)
		{
			cout << "���������: " << map.getTrains()[i]->getCurrentChain().getTrainCarList(1)[j]->getCurrentOccupancy() << " Limit: "
				<< map.getTrains()[i]->getCurrentChain().getTrainCarList(1)[j]->getOccupancyLimit()<< "\n";
		}
		cout << "�����:\n";
		for (int j = 0; j < map.getTrains()[i]->getCurrentChain().getTrainCarList(1).size(); ++j)
		{
			cout << "���������: " << map.getTrains()[i]->getCurrentChain().getTrainCarList(0)[j]->getCurrentOccupancy() << " Limit: "
				<< map.getTrains()[i]->getCurrentChain().getTrainCarList(0)[j]->getOccupancyLimit() << "\n";
		}
	}
}
