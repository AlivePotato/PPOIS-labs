#include <iostream>
#include <string>
#include <regex>
#include "Header.h"

using namespace std;

MySet enterSecondSet();

int main()
{
	setlocale(LC_ALL, "Russian");
	
	MySet myset;
	MySet secondSet;
	MySet result;

	//myset.add("a");
	//myset.add("b");
	//myset.add("c");
	//myset.add("{a, d}");
	//myset.display();
	//myset.clear();

	myset.input("{a,v,d,{c,d,{s}},b,{t}}");
	myset.display();
	//cout << endl << endl;

	myset.input("{a,v,d,{c,d,{s,t}},b,{c,{t,s},d}}");
	myset.display();

	//myset.boolean();

	myset.input("{a,b,c,{g,f},{f,g}}");
	myset.display();

	myset.clear();

	string inputStr;

	int n = 1;
	while (n)
	{	
		cout << "1 - ���� ���������\n"
			<< "2 - ����� ���������\n"
			<< "3 - �������� �� ������ ���������\n"
			<< "4 - �������� ������� ���������\n"
			<< "5 - ������� ������� ���������\n"
			<< "6 - �������� ���������\n"
			<< "7 - �������� ���������\n"
			<< "8 - ����� �������� �� �����\n"
			<< "9 - ����������� ��������\n"
			<< "10 - ����������� ��������\n"
			<< "11 - �������� ��������\n"
			<< "12 - ���������� ������� ���������\n";

		int choice;
		cin >> choice;
		cout << endl;


		switch (choice)
		{
		case 1:
			cout << "������� ���������: ";
			cin >> inputStr;

			myset.input(inputStr);
			break;

		case 2:
			myset.display();
			break;

		case 3:
			if (myset.empty())
				cout << "��������� �����" << endl;
			else
			{
				cout << "��������� �� �����: ";
				myset.display();
				cout << endl;
			}
			break;

		case 4:
			cout << "������� �������, ������� ������ ��������: ";
			cin >> inputStr;

			myset.add(inputStr);
			break;

		case 5:
			cout << "������� �������, ������� ������ �������: ";
			cin >> inputStr;

			myset.erase(inputStr);
			break;

		case 6:
			myset.clear();
			cout << "��������� �������" << endl;
			break;

		case 7:
			cout << "�������� ���������: " << to_string(myset.capacity()) << endl;
			break;

		case 8:
			cout << "������� �������, ������� ������ �����: ";
			cin >> inputStr;

			myset.find(inputStr);
			break;

		case 9:
			secondSet = enterSecondSet();

			result = myset + secondSet;
			result.display();

			secondSet.clear();
			result.clear();
			break;

		case 10:
			secondSet = enterSecondSet();

			result = myset * secondSet;
			result.display();

			secondSet.clear();
			result.clear();
			break;

		case 11:
			secondSet = enterSecondSet();

			result = myset - secondSet;
			result.display();

			secondSet.clear();
			result.clear();
			break;

		case 12:
			result = myset.boolean();

			result.display();
			break;

		default:
			cout << "������ �������� ���" << endl;
		}
	}
	return 0;
}

MySet enterSecondSet()
{
	MySet secondSet;

	string inputString;
	cout << "������� ������ ���������: ";
	cin >> inputString;

	secondSet.input(inputString);
	
	return secondSet;
}