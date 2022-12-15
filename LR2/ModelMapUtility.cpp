#include "ModelMapUtility.h"

ModelMapUtility::ModelMapUtility(ModelMap& obj) : currentMap(obj)
{
	this->findStartPoints();
	this->findRouteDistance();
};

ModelMap ModelMapUtility::getModel()
{
	return currentMap;
}

void ModelMapUtility::findRouteDistance()
{
	std::vector<std::vector<int>> tmpRoutes;
	for (int i = 0; i < currentMap.getTrains().size(); ++i)
		tmpRoutes.push_back(currentMap.getTrains()[i]->getRoute());
	for (int i = 0; i < tmpRoutes.size(); ++i)
		this->findRoutePointToPointDistance(tmpRoutes[i]);
	for (int i = 0; i < tmpRoutes.size(); ++i)
		tmpRoutes[i].erase(tmpRoutes[i].begin());
	routes = tmpRoutes;
}

void ModelMapUtility::findRoutePointToPointDistance(std::vector<int> &tmpRoute)
{
	std::vector<int> tempRoute;
	for (int i1 = 0; i1 < tmpRoute.size() - 1; ++i1)
		for (int h = 0; h < currentMap.getGraph().size(); ++h)
			for (int h1 = 0; h1 < currentMap.getGraph()[h].size() - 2; ++h1)
				if (tmpRoute[i1] == currentMap.getGraph()[h][h1])
					if (tmpRoute[i1 + 1] == currentMap.getGraph()[h][h1 + 1])
						tempRoute.push_back(currentMap.getGraph()[h][2]);
	routePointToPointDistance.push_back(tempRoute);

}

void ModelMapUtility::findStartPoints()
{
	positionTracking.resize(currentMap.getTrains().size());
	for (int i = 0; i < currentMap.getTrains().size(); ++i)
	{
		positionTracking[i] = currentMap.getTrains()[i]->getRoute()[0];
		currentMap.getTrains()[i]->setCurrentPosition(positionTracking[i]);
	}
}

void ModelMapUtility::createNewRoutes()
{
	for (int i = 0; i < currentMap.getTrains().size(); ++i)
	{
		int length = 0;
		int temp=0;
		std::vector<int> route;
		this->showGraph();
		this->showObjTrainInfo(i);
		cout << "������� ����� ��������: ";
		std::cin >> length;
		for (int j = 0; j < length; ++j)
		{
			std::cin >> temp;
			route.push_back(temp);
		}
		currentMap.getTrains()[i]->setRoute(route);
		this->showObjTrainInfo(i);
		route.clear();
	}
	this->findStartPoints();
	this->findRouteDistance();
	return;
}

void ModelMapUtility::showGraph()
{
	for (int i = 0; i < this->getModel().getGraph().size(); ++i)
	{
		for (int j = 0; j < this->getModel().getGraph()[i].size(); ++j)
			cout << this->getModel().getGraph()[i][j] << "  ";
		cout << '\n';
	}
}

void ModelMapUtility::showTrainsInfo()
{
	for (int i = 0; i < currentMap.getTrains().size(); ++i)
	{
		this->showObjTrainInfo(i);
	}
}

void ModelMapUtility::showObjTrainInfo(int TrainIndex)
{
	cout << "\t\t\t����� #" << currentMap.getTrains()[TrainIndex]->getCurrentLocomotive().getLocomotiveNumber() << "\n";
	cout << "{\n";
	if (currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarChainType() == 1)
		cout << "��� ������: ��������\n";
	else if (currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarChainType() == 2)
		cout << "��� ������: ������������\n";
	else
		cout << "��� ������: ���������\n";
	cout << "���������:\n" <<"\t{\n" 
		<< "\t\t������� ����: " << currentMap.getTrains()[TrainIndex]->getCurrentLocomotive().getTractiveForce() << "\n";
	cout << "\t\t���� ������: " << currentMap.getTrains()[TrainIndex]->getCurrentLocomotive().getLifeTime() << "\n";
	cout << "\t}\n";
	cout << "������� �������: " << currentMap.getTrains()[TrainIndex]->getCurrentPosition() << "\n";
	cout << "������� ���: " << currentMap.getTrains()[TrainIndex]->getCurrentWeight() << "\n";
	cout << "������� ��������: " << currentMap.getTrains()[TrainIndex]->getTrainSpeed() << "\n";
	cout << "����: ";
	for (int j = 0; j < currentMap.getTrains()[TrainIndex]->getRoute().size(); ++j)
		if (j == currentMap.getTrains()[TrainIndex]->getRoute().size() - 1)
			cout << currentMap.getTrains()[TrainIndex]->getRoute()[j];
		else
			cout << currentMap.getTrains()[TrainIndex]->getRoute()[j] << " -> ";
	cout << "\n}";
	cout << "\n";
}

void ModelMapUtility::showTrainChainsInfo()
{
	cout <<"\n" << "���������� �������:\n";
	
	for (int i = 0; i < currentMap.getTrains().size(); ++i)
	{
		this->showObjTrainChainInfo(i);
	}
}

void ModelMapUtility::showObjTrainChainInfo(int TrainIndex)
{
	if (currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarChainType() == 3) {

			cout << "\t\t\t����� #" << currentMap.getTrains()[TrainIndex]->getCurrentLocomotive().getLocomotiveNumber() << "\n";
			cout << "������������ ������: " << "\n";
			for (int j = 0; j < currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(1).size(); ++j)
			{
				cout << j + 1 << ". " << "�������������: " << currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(1)[j]->getCurrentOccupancy() << " Limit: "
					<< currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(1)[j]->getOccupancyLimit() << "\n";
			}
			cout << "�������� ������:\n";
			for (int j = 0; j < currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(0).size(); ++j)
			{
				cout << j + 1 << ". " << "�������������: " << currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(0)[j]->getCurrentOccupancy() << " Limit: "
					<< currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(0)[j]->getOccupancyLimit() << "\n";
			}
		}
		else if (currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarChainType() == 2)
		{
			cout << "\t\t\t����� #" << currentMap.getTrains()[TrainIndex]->getCurrentLocomotive().getLocomotiveNumber() << "\n";
			cout << "������������ ������: " << "\n";
			for (int j = 0; j < currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(1).size(); ++j)
			{
				cout << j + 1 << ". " << "������� �������������: " << currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(1)[j]->getCurrentOccupancy() << " Limit: "
					<< currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(1)[j]->getOccupancyLimit() << "\n";
			}

		}
		else
		{
			cout << "\t\t\t����� #" << currentMap.getTrains()[TrainIndex]->getCurrentLocomotive().getLocomotiveNumber() << "\n";
			cout << "�������� ������\n";
			for (int j = 0; j < currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(0).size(); ++j)
			{
				cout << j + 1 << ". " << "������� ������������� " << currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(0)[j]->getCurrentOccupancy() << " Limit: "
					<< currentMap.getTrains()[TrainIndex]->getCurrentChain().getTrainCarList(0)[j]->getOccupancyLimit() << "\n";
			}
		}
}

void ModelMapUtility::showRailwayStationInfo(int RSNumber)
{
	for (int i = 0; i < currentMap.getStations().size(); ++i)
	{
		if (currentMap.getStations()[i]->getRailwayStationNumber() == RSNumber)
		{
			cout << "\t\ ������� #" << RSNumber << "\n";
			switch (currentMap.getStations()[i]->getRailwayStationType())
			{
			case 1:
			{
				cout << "��� �������: ��������" << "\n";
				cout << "��������� ������: " << currentMap.getStations()[i]->getTranspotableResource(0) << "\n";
				cout << "����������� ������  : " << currentMap.getStations()[i]->getOffloadedResource(0) << "\n";
				break;
			}
			case 2:
			{
				cout << "��� �������: �����������" << "\n";
				cout << "��������� ���������: " << currentMap.getStations()[i]->getTranspotableResource(0) << "\n";
				cout << "���������� ���������: " << currentMap.getStations()[i]->getOffloadedResource(0) << "\n";
				break;
			}
			case 3: 
			{
				cout << "��� �������: ���������" << "\n";
				cout << "��������� �������� ������: " << currentMap.getStations()[i]->getTranspotableResource(0) << " ��������� ���������: "
					<< currentMap.getStations()[i]->getTranspotableResource(1) << "\n";
				cout << "\t����������� ������: " << currentMap.getStations()[i]->getOffloadedResource(0) << " ���������� ���������: " 
					<< currentMap.getStations()[i]->getOffloadedResource(1) << "\n";
				break;
			}
			default:
				break;
			}
			break;
		}
	}
}

void ModelMapUtility::fieldModelling()
{
	this->showTrainsInfo();
	while (true)
	{
		if (routes.empty())
		{
			for (int i = 0; i < currentMap.getTrains().size(); ++i)
			{
				currentMap.getTrains()[i]->reduceLifeTime(1);
				if (currentMap.getTrains()[i]->getCurrentLocomotive().getLifeTime() == 0)
				{
					cout << "����� #" << currentMap.getTrains()[i]->getCurrentLocomotive().getLocomotiveNumber() <<
						" ������\n\n";
					currentMap.deleteObjTrain(i);
				}
			}
			this->showTrainsInfo();
			cout << "��� �������� ��������\n������ �� �� ������ �����?\n1.��.\n2.���.\n";
			int choice = false;
			std::cin >> choice;
			if (choice==1)
			{
				routes.clear();
				positionTracking.clear();
				routePointToPointDistance.clear();
				this->createNewRoutes();
			}
			else
				return;

		}
		for (int i = 0; i < routePointToPointDistance.size(); ++i)
		{
			routePointToPointDistance[i][0] -= currentMap.getTrains()[i]->getTrainSpeed();
			if (routePointToPointDistance[i][0] < 0)
			{
				routePointToPointDistance[i].erase(routePointToPointDistance[i].begin());
				positionTracking[i] = routes[i][0];
				routes[i].erase(routes[i].begin());
				currentMap.getTrains()[i]->setRoute(routes[i]);
				currentMap.getTrains()[i]->setCurrentPosition(positionTracking[i]);
				cout << "\t\t\t����� #" << currentMap.getTrains()[i]->getCurrentLocomotive().getLocomotiveNumber()
					<< " ������";
				this->showRailwayStationInfo(positionTracking[i]);
				cout << "\n������ ��������:\n"
					<< "1.���������\n2.���������\n3.�������\n4.��������� ���������\n";
				int choice = 0;
				std::cin >> choice;
				switch (choice)
				{
				case 1:
				{
					if (currentMap.getObjRailwayStation(positionTracking[i])->getRailwayStationType() == 1)
					{
						while (true)
						{
							cout << "������� ������ ���������� �������: ";
							std::cin >> choice;
							if (currentMap.getObjRailwayStation(positionTracking[i])->loadTrain(*currentMap.getTrains()[i],
								choice, 0) == 3)
								break;
							else if (currentMap.getObjRailwayStation(positionTracking[i])->loadTrain(*currentMap.getTrains()[i],
								choice, 0) == 2)
								cout << "�� ������� ��� ������ ���������� �������\n";
							else
								cout << "������ �� �������� ������� �� ���� ����� ���������� �����\n";
						}
					}
					else if (currentMap.getObjRailwayStation(positionTracking[i])->getRailwayStationType() == 2)
					{
						while (true)
						{
							cout << "������� ������ ���������� �������: ";
							std::cin >> choice;
							if (currentMap.getObjRailwayStation(positionTracking[i])->loadTrain(*currentMap.getTrains()[i],
								choice, 1) == 3)
								break;
							else if (currentMap.getObjRailwayStation(positionTracking[i])->loadTrain(*currentMap.getTrains()[i],
								choice, 1) == 2)
								cout << "�� ������� ��� ������ ���������� �������\n";
							else
								cout << "������ �� �������� ������� �� ���� ����� ���������� �����\n";
						}
					}
					else
					{
						bool flag = false;
						cout << "�������� ��� ��������(0-������, 1-���������): ";
						std::cin >> flag;
						while (true)
						{
							if (flag)
								cout << "������� ������ ���������� ����������: ";
							else
								cout << "������� ������ ���������� �����: ";
							std::cin >> choice;
							if (currentMap.getObjRailwayStation(positionTracking[i])->loadTrain(*currentMap.getTrains()[i],
								choice, flag) == 3)
								break;
							else if (currentMap.getObjRailwayStation(positionTracking[i])->loadTrain(*currentMap.getTrains()[i],
								choice, flag) == 2)
								cout << "�� ������� ��� ������ ���������� �������\n";
							else
								cout << "����� ������� ������� ��� ��� ������ ���������� �������\n";
						}
					}
					break;
				}
				case 2:
				{
				if (currentMap.getObjRailwayStation(positionTracking[i])->getRailwayStationType() == 1)
				{
					while (true)
					{
						cout << "������� ������� �����, ������� ������ ���������: ";
						std::cin >> choice;
						if (choice < 0 || choice >100)
							cout << "������������ ����\n";
						else
						{
							currentMap.getObjRailwayStation(positionTracking[i])->offloadTrain(*currentMap.getTrains()[i],
								choice, 0);
							break;
						}
					}
				}
				else if (currentMap.getObjRailwayStation(positionTracking[i])->getRailwayStationType() == 2)
				{
					while (true)
					{
						cout << "������� ������� ����������, ������� ������ ��������: ";
						std::cin >> choice;
						if (choice < 0 || choice > 100)
							cout << "����������� ����\n";
						else
						{
							currentMap.getObjRailwayStation(positionTracking[i])->offloadTrain(*currentMap.getTrains()[i],
								choice, 0);
							break;
						}
					}
				}
				else
				{
					bool flag = false;
					cout << "�������� ��� �������� (0-������, 1-���������): ";
					std::cin >> flag;
					while (true)
					{
						if (flag)
							cout << "������� ������� �����, ������� ������ ���������: ";
						else
							cout << "������� ������� ����������, ������� ������ ��������: ";
						std::cin >> choice;
						if (choice < 0 || choice >100)
							cout << "����������� ����\n";
						else
						{
							currentMap.getObjRailwayStation(positionTracking[i])->offloadTrain(*currentMap.getTrains()[i], choice, flag);
							break;
						}
					}
				}
					break;
				}
				case 3:
					break;
				case 4:
				{
					routes[i].insert(routes[i].begin(),positionTracking[i]);
					routePointToPointDistance[i].insert(routePointToPointDistance[i].begin(), currentMap.getTrains()[i]->getTrainSpeed());
					continue;
					break;
				}
				default:
					break;
				}
				cout << "\n";
				this->showObjTrainInfo(i);
				this->showObjTrainChainInfo(i);
				cout << "\n";
				this->showRailwayStationInfo(positionTracking[i]);
				cout << "\n";
				if (routes[i].empty())
					routes.erase(routes.begin() + i);
				if (routePointToPointDistance[i].empty())
					routePointToPointDistance.erase(routePointToPointDistance.begin() + i);		
			}
		}
		}
}