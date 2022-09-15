/*!
\file
\brief �������� ���� ����������� ������ ������ ����������� ������

������ ���� �������� � ���� ���������� ������� ������ ����������� ������ �� ������
*/

#include "Fraction.h"
#include <iostream>
#include <cmath>
using namespace std;
/*!
	\brief ����������� ����� �� ���������
	����������� �� ��������� ������� ��������� �����:
	\code
	 Fraction::Fraction()
	{
		this->numeration = 1;
		this->denominator = 1;
		this->integer = 0;
	}
	\endcode
	 �.�. ����� 1.

*/

Fraction::Fraction()
{
	this->numeration = 1;
	this->denominator = 1;
	this->integer = 0;
}

/*!
	\brief ����������� �����

	\param numeration	��������� �����
	\param denominator ����������� �����
	\param integer ����� ����� �����

	� ����� �������� ����� NormalForm.
*/

Fraction::Fraction(int numeration, int denominator, int integer)
{
	this->numeration = numeration;
	this->denominator = denominator;
	this->integer = integer;
	this->NormalForm();
}
/*!
	\brief ����������� ����������� �����

	\param other ���������� �����
*/
Fraction::Fraction(const Fraction& other)
{
	this->numeration = other.numeration;
	this->denominator = other.denominator;
	this->integer = other.integer;
}
/*!
	\brief ������ ���������

	\param numeration ��������������� ��������
*/
void Fraction::SetNumeration(int numeration)
{
	this->numeration = numeration;
}
/*!
	\brief ������ �����������

	\param denominator ��������������� ��������
*/
void Fraction::SetDenominator(int denominator)
{
	this->denominator = denominator;
}
/*!
	\brief ������ ����� �����

	\param integer ��������������� ��������
*/
void Fraction::SetInteger(int integer)
{
	this->integer = integer;
}
/*!
	\brief ������ ���������

	\return �������� ���������
*/
int Fraction::GetNumeration()
{
	return this->numeration;
}
/*!
	\brief ������ �����������

	\return �������� �����������
*/
int Fraction::GetDenominator()
{
	return this->denominator;
}
/*!
	\brief ������ ����� �����

	\return �������� ����� �����
*/
int Fraction::GetInteger()
{
	return this->integer;
}
/*! \brief ������� �������� ���� ����������� ������
	\param other ������ ���������
	\return ����� - ��������� �������� ���� ������
*/
Fraction Fraction::operator+(const Fraction& other)
{
	Fraction temp_1(this->WithoutInt()), temp_2(other);
	temp_2.WithoutInt(1);
	temp_1.numeration = temp_1.numeration * temp_2.denominator + temp_2.numeration * temp_1.denominator;
	temp_1.denominator *= temp_2.denominator;
	temp_1.NormalForm();
	return temp_1;
}
/*! \brief ������� ��������� ���� ����������� ������
		\param other ����������
		 \return ����� - ��������� ��������� ���� ������
*/
Fraction Fraction::operator-(const Fraction& other)
{
	Fraction temp_1(this->WithoutInt()), temp_2(other);
	temp_2.WithoutInt(1);
	temp_1.numeration = temp_1.numeration * temp_2.denominator - temp_2.numeration * temp_1.denominator;
	temp_1.denominator *= temp_2.denominator;
	temp_1.NormalForm();
	return temp_1;
}
/*! \brief ������� �������� � ����������� �����
	\param other ������ ���������
*/
Fraction& Fraction::operator+=(const Fraction& other)
{
	this->WithoutInt(1);
	Fraction temp(other);
	temp.WithoutInt(1);
	this->numeration = this->numeration * temp.denominator + temp.numeration * this->denominator;
	this->denominator *= temp.denominator;
	this->NormalForm();
	return *this;
}
/*! \brief ������� ��������� � ����������� �����
		\param other ����������
*/
Fraction& Fraction::operator-=(const Fraction& other)
{
	this->WithoutInt(1);
	Fraction temp(other);
	temp.WithoutInt(1);
	this->numeration = this->numeration * temp.denominator - temp.numeration * this->denominator;
	this->denominator *= temp.denominator;
	this->NormalForm();
	return *this;
}
/*! \brief ������� ��������� ���� ����������� ������
		\param other ������ ���������
		 \return ����� - ��������� ��������� ���� ������
*/
Fraction Fraction::operator*(const Fraction& other)
{
	Fraction temp_1(this->WithoutInt()), temp_2(other);
	temp_2.WithoutInt(1);
	temp_1.numeration *= temp_2.numeration;
	temp_1.denominator *= temp_2.denominator;
	temp_1.NormalForm();
	return temp_1;
}
/*! \brief ������� ��������� � ����������� �����
		\param other ������ ���������
*/
Fraction& Fraction::operator*=(const Fraction& other)
{
	this->WithoutInt(1);
	Fraction temp(other);
	temp.WithoutInt(1);
	this->numeration *= temp.numeration;
	this->denominator *= temp.denominator;
	this->NormalForm();
	return *this;
}
/*! \brief ������� ������� ���� ����������� ������
	\param other ��������
	\return ����� - ��������� ������� ���� ������
	\warning ��� ������� �� 0 ���������� �������� �����
*/
Fraction Fraction::operator/(const Fraction& other)
{
	if (other.numeration == 0)
	{
		cout << "ERROR:DENOMINATOR IS ZERO" << endl;
		return *this;
	}
	Fraction temp_1(this->WithoutInt()), temp_2(other);
	temp_2 = temp_2.WithoutInt();
	temp_1.numeration *= temp_2.denominator;
	temp_1.denominator *= temp_2.numeration;
	temp_1.NormalForm();
	return temp_1;
}
/*! \brief ������� �������� ����� �����

	������� ���������, ������������ �� ����� �����, ���� ��, �� ������ �� ����. ����������� ��� ���������� ��������.
*/
void Fraction::MinusInteger()
{
	if (this->integer<0)
	{
		this->integer *= -1;
	}
}
/*! \brief ������� ������� � ����������� �����
	\param other ��������
	\warning ��� ������� �� 0 ���������� �������� �����
*/
Fraction& Fraction::operator/=(const Fraction& other)
{
	if (other.numeration == 0)
	{
		cout << "ERROR:DENOMINATOR IS ZERO" << endl;
		return *this;
	}
	this->WithoutInt(1);
	Fraction temp(other);
	temp.WithoutInt(1);
	this->numeration *= temp.denominator;
	this->denominator *= temp.numeration;
	this->NormalForm();
	return *this;
}
/*! \brief ������� �������� ����������� ����� � ����� ������
		\param other ������ ���������
		 \return ����� - ��������� �������� ����� � ����� ������
*/
Fraction Fraction::operator+(const int& other)
{
	Fraction temp(this->WithoutInt());
	temp.numeration += other * temp.denominator;
	temp.NormalForm();
	return temp;
}
/*! \brief ������� ��������� ����������� ����� � ������ �����
		\param other ����������
		 \return ����� - ��������� ��������� ����� � ������ �����
*/
Fraction Fraction::operator-(const int& other)
{
	Fraction temp(this->WithoutInt());
	temp.numeration -= other * temp.denominator;
	temp.NormalForm();
	return temp;
}
/*! \brief ������� �������� � ����������� ����� � ������ �����
	\param other ������ ���������
*/
Fraction& Fraction::operator+=(const int& other)
{
	this->WithoutInt(1);
	this->numeration += other * this->denominator;
	this->NormalForm();
	return *this;
}
/*! \brief ������� ��������� � ����������� ����� � ������ �����
		\param other ����������
*/
Fraction& Fraction::operator-=(const int& other)
{
	this->WithoutInt(1);
	this->numeration -= other * this->denominator;
	this->NormalForm();
	return *this;
}
/*! \brief ������� ��������� ����������� ����� � ������ �����
		\param other ������ ���������
		 \return ����� - ��������� ��������� ����������� ����� � ������ �����
*/
Fraction Fraction::operator*(const int& other)
{
	if (other == 0)
	{
		return Fraction(0, 1, 0);
	}
	Fraction temp(this->WithoutInt());
	temp.numeration *= other;
	temp.NormalForm();
	return temp;
}
/*! \brief ������� ��������� � ����������� ����� � ������ �����
		\param other ������ ���������

*/
Fraction& Fraction::operator*=(const int& other)
{
	if (other == 0)
	{
		this->numeration = 0;
		this->denominator = 1;
		this->integer = 0;
		return *this;
	}
	this->WithoutInt(1);
	this->numeration *= other;
	this->NormalForm();
	return *this;
}
/*! \brief ������� ������� ����� �� ����� �����
		\param other ��������
		 \return ����� - ��������� ������� ����� �� ����� �����
		 \warning ��� ������� �� 0 ���������� �������� �����
*/
Fraction Fraction::operator/(const int& other)
{
	if (other == 0)
	{
		cout << "ERROR:DENOMINATOR IS ZERO" << endl;
		return *this;
	}
	Fraction temp(this->WithoutInt());
	temp.denominator *= other;
	temp.NormalForm();
	return temp;
}
/*! \brief ������� ������� ����� �� ����� �����
		\param other ��������
		\warning ��� ������� �� 0 ���������� �������� �����
*/
Fraction& Fraction::operator/=(const int& other)
{
	if (other == 0)
	{
		cout << "ERROR:DENOMINATOR IS ZERO" << endl;
		return *this;
	}
	this->WithoutInt(1);
	this->denominator *= other;
	this->NormalForm();
	return *this;
}
/*! \brief ������� ������������
	
	���������� ������� � ��������� ��������  
*/
Fraction& Fraction::operator++()
{
	this->WithoutInt(1);
	this->numeration += this->denominator;
	this->NormalForm();
	return *this;
}
/*! \brief ������� ������������
	
	�������� ������� � ��������� ��������
*/
Fraction& Fraction::operator--()
{
	this->WithoutInt(1);
	this->numeration -= this->denominator;
	this->NormalForm();
	return *this;
}
/*! \brief ������� �������������
	
	��������� �������� � ���������� �������
*/
Fraction& Fraction::operator++(int other)
{
	Fraction temp(*this);
	this->WithoutInt(1);
	this->numeration += this->denominator;
	this->NormalForm();
	return temp;
}
/*! \brief ������� �������������
		
	��������� �������� � �������� �������
*/
Fraction& Fraction::operator--(int other)
{
	Fraction temp(*this);
	this->WithoutInt(1);
	this->numeration -= this->denominator;
	this->NormalForm();
	return temp;
}
/*! \brief ������� ��������� < ���� ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ������ other, false �� ���� ��������� �������
*/
bool Fraction::operator<(const Fraction& other)
{
	return this->compareTo(other) < 0;
}
/*! \brief ������� ��������� <= ���� ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ������ ���� ����� other, false �� ���� ��������� �������
*/
bool Fraction::operator<=(const Fraction& other)
{
	return this->compareTo(other) <= 0;
}
/*! \brief ������� ��������� ���� > ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ������ other, false �� ���� ��������� �������
*/
bool Fraction::operator>(const Fraction& other)
{
	return this->compareTo(other) > 0;
}
/*! \brief ������� ��������� ���� >= ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ������ ���� ����� other, false �� ���� ��������� �������
*/
bool Fraction::operator>=(const Fraction& other)
{
	return this->compareTo(other) >= 0;
}
/*! \brief ������� ��������� ���� == ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ����� other, false �� ���� ��������� �������
*/
bool Fraction::operator ==(const Fraction& other)
{
	return this->compareTo(other) == 0;
}
/*! \brief ������� ��������� ���� != ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� �� ����� other, false �� ���� ��������� �������
*/
bool Fraction::operator !=(const Fraction& other)
{
	return this->compareTo(other) != 0;
}
/*! \brief ������� ���������� ����������� ����� � ���� double
	\return �����, ����������� � double
*/
double Fraction::ToDouble()
{
	double denominator = this->denominator;
	double integer = this->integer;
	double numeration = this->numeration + denominator * integer;
	return numeration/this->denominator;
}
/*! \brief ������� ��������� < ���� ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ������ other, false �� ���� ��������� �������
*/
bool Fraction::operator<(const int& other)
{
	return this->compareTo(other) < 0;
}
/*! \brief ������� ��������� <= ���� ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ������ ���� ����� other, false �� ���� ��������� �������
*/
bool Fraction::operator<=(const int& other)
{
	return this->compareTo(other) <= 0;
}
/*! \brief ������� ��������� ���� > ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ������ other, false �� ���� ��������� �������
*/
bool Fraction::operator>(const int& other)
{
	return this->compareTo(other) > 0;
}
/*! \brief ������� ��������� ���� >= ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ������ ���� ����� other, false �� ���� ��������� �������
*/
bool Fraction::operator>=(const int& other)
{
	return this->compareTo(other) >= 0;
}
/*! \brief ������� ��������� ���� == ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� ����� other, false �� ���� ��������� �������
*/
bool Fraction::operator ==(const int& other)
{
	return this->compareTo(other) == 0;
}
/*! \brief ������� ��������� ���� != ����������� ������
	\param other �����, � ������� ����������
	\return true, ���� ����� �� ����� other, false �� ���� ��������� �������
*/
bool Fraction::operator !=(const int& other)
{
	return this->compareTo(other) != 0;
}
/*! \brief ������� ��������� ���� �����
	\return ��������� �����, ��� ����� �����

	������� ������� ����� �����, �������� ����� ����� � ���������. �� �������� ������� �����. �������� �����. ����������� ��� ���������� ��������.
*/
Fraction Fraction::WithoutInt()
{
	Fraction temp;
	this->numeration > 0 ? temp.numeration = this->numeration + this->integer * this->denominator : temp.numeration = this->numeration - this->integer * this->denominator;
	temp.denominator = this->denominator;
	temp.integer = 0;
	temp.Simplify();
	return temp;
}
/*! \brief ������� ��������� ���� �����

	������� �������� ������� �����, �������� ����� ����� � ���������. �������� �����. ����������� ��� ���������� ��������.
*/
void Fraction::WithoutInt(int n)
{
	this->numeration > 0 ? this->numeration += this->integer * this->denominator : this->numeration -= this->integer * this->denominator;
	this->integer = 0;
	this->Simplify();
}
/*! \brief ������� ��������� �����

	������� �������� ������� �����. ����������� ��� ���������� ��������.
*/
void Fraction::Simplify()
{
	this->MinusDenominator();
	if (abs(this->numeration) < 2) return;
	int gcd = GetGCD(abs(this->numeration), this->denominator);
	this->numeration /= gcd;
	this->denominator /= gcd;
}
/*! \brief ������� �������� �����������

	������� ���������, ����������� �� ����������, ���� ��, �� ������ ����� ����������� � ���������. ����������� ��� ���������� ��������.
*/
void Fraction::MinusDenominator()
{
	if (this->denominator < 0)
	{
		this->denominator *= -1;
		this->numeration *= -1;
	}
}
/*! \brief ������� ��������� ���� �����

	������� �������� ������� �����, ������� ����� �����, ���� ��� ��������. �������� �����. ����������� ��� ���������� ��������.
*/
void Fraction::NormalForm()
{
	this->Simplify();
	this->integer += this->numeration / this->denominator;
	this->MinusInteger();
	this->numeration = this->numeration % this->denominator;
}
/*! \brief ������� ���������� ���
	\param	a,b �����, ��� ������� ���� ��������� ���

	������� ��������� ��� a � b, ��������� �������� ���������. ����������� ��� ��������� �����.
*/
int Fraction::GetGCD(int a, int b) {
	while (a != b)
		a > b ? a -= b : b -= a;
	return a;
}
/*! \brief ������� ��������� ���� ������
	\param	other �����, � ������� ����������
	\return �������� ���� ������

	������� ��������� �������� ���� ������. ����������� ��� �������� ���������.
*/
int Fraction::compareTo(const Fraction& other)
{
	Fraction temp_1(this->WithoutInt()), temp_2(other);
	temp_2 = temp_2.WithoutInt();
	return temp_1.numeration * temp_2.denominator - temp_1.denominator * temp_2.numeration;
}
/*! \brief ������� ��������� ����� � ������ �����
	\param	other �����, � ������� ����������
	\return ����� � ������ �����

	������� ��������� �������� ����� � ������ �����. ����������� ��� �������� ���������.
*/
int Fraction::compareTo(const int& other)
{
	Fraction temp_1(this->WithoutInt());
	return temp_1.numeration - temp_1.denominator * other;
}