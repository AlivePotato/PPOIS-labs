/** \file Matrix.h
* ����������� �����
* ����������� ���������� ������
* ����������� ������ ������
* */
#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Matrix{

private:
	vector<vector<double>> b;
	vector<vector<double>> vec;

public:
	int rows = 0, cols = 0;
	double numb = 0, det = 0;
	vector<vector<double>> a;

	///  \brief ���� ����� ��������� ������� ����� ������� 
    void create_one(Matrix &, int, int);

	///  \brief ���� ����� ��������� �������� ����� �������
	static void show_one(vector<vector<double>>&, int, int);

	///  \brief ���� ����� ��������� ���������� ������������ ������� 
	static void deter(vector<vector<double>>&, int, double);

	///  \brief ���� ����� ��������� ���������� ������������ ������� 
	static double cadet(vector<vector<double>>&, int);

	///  \brief ���� ����� ��������� ���������� ������������ ������� 
	static void new_matr(vector<vector<double>>&, vector<vector<double>>& help, int, int, int);

	///  \brief ���� ����� ��������� ���������� M-����� ������� 
	static void m_norm(vector<vector<double>>&, int, int);

	///  \brief ���� ����� ��������� ���������� L-����� ������� 
	static void l_norm(vector<vector<double>>&, int, int);

	///  \brief ���� ����� ��������� ���������� K-����� ������� 
	static void k_norm(vector<vector<double>>&, int, int);

	///  \brief ������ ���������� ��������� ������ ��� ����� ������ 
	Matrix& operator + (Matrix& right) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] = a[i][j] + right.a[i][j];
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� ����� ������
	Matrix& operator += (Matrix& right) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] += right.a[i][j];
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� �������� ������
	Matrix& operator - (Matrix& right) {

		//Matrix tmp = *this;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] = a[i][j] - right.a[i][j];
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� �������� ������
	Matrix& operator -= (Matrix& right) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] -= right.a[i][j];
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� ����� ������� � �����
	Matrix& operator + (double& right) {

		//Matrix tmp = *this;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] = a[i][j] + right;
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� ����� ������� � �����
	Matrix& operator += (double right) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] += right;
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� �������� ������� � �����
	Matrix& operator - (double& right) {

		//Matrix tmp = *this;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] = a[i][j] - right;
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� �������� ������� � �����
	Matrix& operator -= (double right) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] -= right;
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� �������� ������� � �����
	Matrix& operator / (double& right) {

		//Matrix tmp = *this;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] = a[i][j] / right;
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� �������� ������� � �����
	Matrix& operator /= (double right) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] /= right;
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� ������������ ������� � �����
	Matrix& operator * (double& right) {

		Matrix tmp = *this;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] = a[i][j] * right;
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� ������������ ������� � �����
	Matrix& operator *= (double& right) {

		Matrix tmp = *this;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->a[i][j] *= right;
			}
		}
		return *(this);
	}

	///  \brief ������ ���������� ��������� ������ ��� ������������ ������
	Matrix& operator * (Matrix& right) {

		b.resize(rows);
		for (int i = 0; i < rows; i++) {
			b[i].resize(cols);
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{

				for (int x = 0; x < cols; x++) {
					b[i][j] += a[i][x] * right.a[x][j];
				}
			}
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				a[i][j] = b[i][j];
			}
		}
		return *this;

	}

	///  \brief ������ ���������� ��������� ������ ��� ���������� ������� � �������
	Matrix& operator ^ (double right) {

		b.resize(rows);
		for (int i = 0; i < rows; i++) {
			b[i].resize(cols);
		}

		vec.resize(rows);
		for (int i = 0; i < rows; i++) {
			vec[i].resize(cols);
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				vec[i][j] = a[i][j];
			}
		}

		for (int k = 0; k < right - 1; k++)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{

					for (int x = 0; x < cols; x++) {
						b[i][j] += vec[i][x] * a[x][j];
					}
					
				}
			}
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					a[i][j] = b[i][j];
					b[i][j] = 0;
				}
			}
		}
		return *this;

	}

	///  \brief ������ ���������� ��������� ������ ��� ���������� ������� � �������
	Matrix& operator ^= (double right) {

		b.resize(rows);
		for (int i = 0; i < rows; i++) {
			b[i].resize(cols);
		}

		vec.resize(rows);
		for (int i = 0; i < rows; i++) {
			vec[i].resize(cols);
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				vec[i][j] = a[i][j];
			}
		}

		for (int k = 0; k < right - 1; k++)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{

					for (int x = 0; x < cols; x++) {
						b[i][j] += vec[i][x] * a[x][j];
					}

				}
			}
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					a[i][j] = b[i] [j];
					b[i][j] = 0;
				}
			}
		}
		return *this;

	}

	Matrix& operator ++ (int) {
		this->a.resize(this->rows + 1);
		for (int i = 0; i < this->rows + 1; i++) {
			this->a[i].resize(this->cols + 1);
		}
		for (int i = 0; i < this->rows + 1; i++) {
			for (int j = 0; j < this->cols + 1; j++) {
				double d;
				cin >> d;
				this->a[i][j] = d;
			}
		}
		return *this;
	}

	Matrix& operator -- (int) {
		this->a.resize(this->rows - 1);
		for (int i = 0; i < this->rows - 1; i++) {
			this->a[i].resize(cols - 1);
		}
		for (int i = 0; i < this->rows - 1; i++) {
			for (int j = 0; j < this->cols - 1; j++) {
				double d;
				cin >> d;
				this->a[i][j] = d;
			}
		}
		return *this;
	}

	/// \brief ������ ����� ������ ��� ������ �������
	void ShowMatrix()
	{
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				cout << a[i][j] << '\t';
			}
			cout << '\n';
		}
	}
};



