#include <iostream>
#include <vector>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(0, "");
	Set a, c;
	int size, q;
	string str;
	int chose = -1;
	bool key = true;
	while (key)
	{
		Set b;
		cout << "\n1-->�������� �������\n2-->������� ���������\n3-->�������� �� ������ ���������\n4-->������� ��������� �������\n5-->�������� ��������a\n6-->����� ��������\n7-->����������\n8-->�����������\n9-->��������\n10-->������ ���������\n0-->�����\n";
		cin >> chose;
		switch (chose)
		{
		case 0:
			key = false;
			break;
		case 1:
			a.Add();
			break;
		case 2:
			a.Show();
			break;
		case 3:
			a.Empti();
			break;
		case 4:
			a.Delete();
			break;
		case 5:
			a.Mochnost();
			break;
		case 6:
			/*cout << "������� ����� ��������: ";
			cin >> q;
			str = a[q - 1];
			cout << str;
			break;*/
			cout << "������� ������� �������: ";
			cin >> str;
			a[str];
			break;
		case 7:
			cout << "������� ������ ������� ���������: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				b.Add();
			system("cls");
			cout << "1--> +\n2--> +=";
			cin >> chose;
			switch (chose)
			{
			case 1:
				a.Show();
				cout << " + ";
				b.Show();
				c = a + b;
				cout << " = ";
				c.Show();
				break;
			case 2:
				a.Show();
				cout << " + ";
				b.Show();
				a += b;
				cout << " = ";
				a.Show();
				break;
			}
			break;
		case 8:
			cout << "������� ������ ������� ���������: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				b.Add();
			system("cls");
			cout << "1--> *\n2--> *=";
			cin >> chose;
			switch (chose)
			{
			case 1:
				a.Show();
				cout << " * ";
				b.Show();
				c = a * b;
				cout << " = ";
				c.Show();
				break;
			case 2:
				a.Show();
				cout << " * ";
				b.Show();
				a *= b;
				cout << " = ";
				a.Show();
				break;
			}
			break;
		case 9:
			cout << "������� ������ ������� ���������: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				b.Add();
			system("cls");
			cout << "1--> -\n2--> -=";
			cin >> chose;
			switch (chose)
			{
			case 1:
				a.Show();
				cout << " - ";
				b.Show();
				c = a - b;
				cout << " = ";
				c.Show();
				break;
			case 2:
				a.Show();
				cout << " - ";
				b.Show();
				a -= b;
				cout << " = ";
				a.Show();
				break;
			}
			break;
		case 10:

			a.Bulian();
			a.Show();
			break;
		default:
			cout << "����� ������ �� ����������!";
		}
	}
}