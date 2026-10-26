#include <iostream>
#include <cmath>
#include "fraction.h"

using namespace std;

Fraction::Fraction()
{
	if (denominator != 0)
	{
		numerator = 0;
		denominator =  1;
	}
	else
	{
		cout << "Знаменатель равен 0!" << endl;
		exit(0);
	}
}

Fraction::Fraction(int num, int den)
{
	numerator = num;
	denominator = den;
}

double Fraction::toDouble()
{
	return static_cast<double>(numerator) / static_cast<double>(denominator);
}

int Fraction::NOD(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b; // Запомнили остаток, пока a и b еще "старые"
		a = b;			  // a получает старое b
		b = temp;		  // b получает остаток
	}
	
	return a;
}

double Fraction::normalize()
{
	double k = ;
	
	return numerator * k / denominator * k
}

Fraction Fraction::operator+(Fraction f2)
{
	Fraction result;
	result.numerator = numerator * f2.denominator +
					   denominator * f2.numerator;
					   
	result.denominator = denominator * f2.denominator;
	
	return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	os << f.numerator << "/" << f.denominator;
	return os;
}

