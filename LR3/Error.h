#pragma once
#include <iostream>
#include <type_traits>
class Error
{
public:
	Error(int errorCode)
	{
		errorCode;
		std::cout << "��� ������: " << errorCode;
		switch (errorCode)
		{
		case 0: std::cout << ". ������������ ���.(��������� ���� ������: int, string, double) "; system("pause"); exit(0); break;
		case 100: std::cout << ". ������� ������������� �����: "; break;
		case 101: std::cout << ". ������� �����: "; break;
		case 102: std::cout << ". ������� ������������ �����: "; break;
		case 103: std::cout << ". ������� ������: "; break;
		case 200: std::cout << ". ������ ��������� �� ����������." << std::endl; break;
		case 300: std::cout << ". ������� � ����� �������� �� ����������." << std::endl; break;
		case 301: std::cout << ". ����� � ����� ������ �� ����������." << std::endl; break;
		case 302: std::cout << ". ������ ������� ����� ��� ����� �������." << std::endl; break;
		case 303: std::cout << ". �������� ����� ���������� �����! �������� �������." << std::endl; break;
		case 304: std::cout << ". ������(�/�) �� ����������! �������� �������." << std::endl; break;
		case 305: std::cout << ". ����� ����� ���������� ��������� ��� ����������. �������� ����� ������� ��� ��������� ������ �������." << std::endl; break;
		case 306: std::cout << ". ����� � ����� ������ ��� ����������. ������� ����� � ������ ������." << std::endl; break;
		case 400: std::cout << ". �������� ������ ��������� ������!" << std::endl; break;
		case 401: std::cout << ". �������� ������ ��������� �����!" << std::endl; break;
		}
	}
};
template<class type>
type getChoice()
{
	while (true)
	{
		type choice;
		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			if (std::is_same<type, int>::value)
			{
				Error error(100);
				continue;
			}
			else if (std::is_same<type, char>::value)
			{
				Error error(101);
				continue;
			}
			else if (std::is_same<type, double>::value)
			{
				Error error(102);
				continue;
			}
			else if (std::is_same<type, std::string>::value)
			{
				Error error(103);
				continue;
			}
			else Error error(0);
		}
		else
			return choice;
	}
}
