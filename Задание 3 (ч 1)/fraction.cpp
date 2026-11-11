#include <iostream>
#include <cmath>
#include "fraction.h"

using namespace std;

Fraction::Fraction(): numerator(0), denominator(1)
{
}

Fraction::Fraction(int num, int den): numerator(num), denominator(den)
{
	if (den == 0)
	throw invalid_argument("Знаменатель не может быть равно 0!");
}

int Fraction::getNumerator() const
{
	return numerator;
}

int Fraction::getDenominator() const
{
	return denominator;
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
	
	return abs(a);
}

void Fraction::normalize()
{
	// Знак храним в числителе: 1/-2 -> -1/2
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	
	// Знаменатель не равен 0, поэтому НОД >= 1 и делить безопасно.
	// Для нулевой дроби, НОД = d, получится 0/1
	int d = NOD(numerator,denominator);
	numerator /= d;
	denominator /= d;
}

Fraction Fraction::operator+(Fraction f2) const
{
	Fraction result;
	result.numerator = numerator * f2.denominator +
					   denominator * f2.numerator;
					   
	result.denominator = denominator * f2.denominator;
	
	result.normalize();
	return result;
}

Fraction Fraction::operator-(Fraction f2) const
{
	Fraction result;
	result.numerator = numerator * f2.denominator -
					   denominator * f2.numerator;
					   
	result.denominator = denominator * f2.denominator;
	
	result.normalize();
	return result;
}

Fraction Fraction::operator*(Fraction f2) const
{
	Fraction result;
	result.numerator = numerator * f2.numerator;
					   
	result.denominator = denominator * f2.denominator;
	
	result.normalize();
	return result;
}

Fraction Fraction::operator/(Fraction f2) const
{
	if (f2.numerator == 0)
	{
		throw domain_error("Деление на нулевую дробь!");
	}
	
	Fraction result;
	result.numerator = numerator * f2.denominator;
	result.denominator = denominator * f2.numerator;
	
	result.normalize();
	return result;
}

Fraction operator+(int a, const Fraction& f)
{
	return Fraction(a) + f;
}

Fraction operator-(int a, const Fraction& f)
{
	return Fraction(a) - f;
}

Fraction operator*(int a, const Fraction& f)
{
	return Fraction(a) * f;
}

Fraction operator/(int a, const Fraction& f)
{
	return Fraction(a) / f;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	os << f.getNumerator() << "/" << f.getDenominator();
	return os;
}

