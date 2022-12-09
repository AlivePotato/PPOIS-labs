/// \file game.h
/// \brief ������������ ���� �������, ������������ � ���� ���������.
/// �������� ������ Puzzle, Menu
///
/// \authors DominikFurs
/// \date 29.10.2022

#include <string>
#include <vector>

using  namespace std;

/// \brief ����� Puzzle
/// \details ����� Puzzle ��������� ���� "��������"
class Puzzle
{
private:
	//! ������ ��������, �������� ����� ���������� ����
	vector<vector<int>> solution = { {1,2,3,4},
										 {5,6,7,8},
										 {9,10,11,12},
										 {13,14,15,0} };

	//! ������, ���������� �������� �� 0 �� 15
	vector<int> list;
	//! ������ ��������, ���������� ������� ����
	vector<vector<int>> board{ 4,vector<int>(4) };

	//! ���������� - ���������� "�������" ������
	int X, Y;
	//! ���������� - ������ �������� ����
	static const int board_size = 4;
	//! ���������� - ������ ������ ��������
	static const int list_size = 16;

public:
	/// \brief �����������
	Puzzle();

	/// \brief ������� ��������� ���������� ������ ��������
	/// \see vector<int> list
	void random_sort();

	/// \brief ������� �������� ������
	/// \see vector<vector<int>> game
	/// \see vector<vector<int>> solved_puzzle
	/// \return true, ���� ������� �����
	/// \return false, � ���� ������
	bool checker();

	/// \brief ���������� ������ �������� ����������
	/// \see static const int list_size
	/// \see vector<int> list
	void list_filling();

	/// \brief �������� ����������� ��������� �� ����������� �������
	/// \see vector<int> list
	/// \see static const list_size
	/// \see int res
	/// \see int e 
	/// \return true, ���� ������ ��������
	/// \return false, � ���� ������
	bool solve();

	/// \brief ���������� �������� ����
	/// \see vector<int> list
	/// \see vector<vector<int>> game_board
	/// \see static const board_size
	/// \see static const list_size
	void board_filling();

	/// \brief ����� ��������� "�������" ������
	/// \see vector<vector<int>> game_board
	/// \see static const board_size
	/// \see int X_x
	/// \see int Y_x
	/// 
	void coordinate();
	/// \brief ������� ����������� ������� ������
	/// \see vector<vector<int>> game_board
	/// \see static const board_size
	/// \see int X_x
	/// \see int Y_x
	/// \see char ch
	void move();
	/// \brief ���������� ��������� �������
	/// \param n, ������ �������
	/// \throw exception ��� ������������ ������ ������� list
	int& operator[ ](int);
	/// ���������� ��������� <<
	friend ostream& operator<< (ostream&, Puzzle&);
	/// ����������
	~Puzzle();
};

/// ����� Menu
/// \details ����� Menu ��������� ������� ����
class Menu
{
private:
	//! ���������� ������ ������������ � ����
	int ch;
public:
	/// \brief ������ ��� ���������� ch
	/// \param ch - ����� ������������
	void set_choice(int ch);
	/// \brief �������, ��������� ����
	void start();
	/// \brief �������, ��������� ��������� �� �������� ����
	void conditions();
	/// \brief �������, ��������� ��������� � ����������� ����
	void end();
};