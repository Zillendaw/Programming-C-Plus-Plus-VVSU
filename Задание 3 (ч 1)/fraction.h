#ifndef FRACTIOH_H
#define FRACTIOH_H
#include <iostream>

class Fraction {
public:
	Fraction();
	Fraction(int num, int den = 1);
	
	int getNumerator() const;
	int getDenominator() const;
	
	double toDouble();
	void normalize();
	static int NOD(int a, int b);
	
	
	Fraction operator+(Fraction f2) const;
	Fraction operator-(Fraction f2) const;
	Fraction operator*(Fraction f2) const;
	Fraction operator/(Fraction f2) const;
	
private:
	int numerator;
	int denominator;
};

// Целое и дробь: слева int, поэтому это не могут быть методы класса
Fraction operator+(int a, const Fraction& f);
Fraction operator-(int a, const Fraction& f);
Fraction operator*(int a, const Fraction& f);
Fraction operator/(int a, const Fraction& f);

std::ostream& operator<<(std::ostream& os, const Fraction& f);

#endif // FRACTION_H

