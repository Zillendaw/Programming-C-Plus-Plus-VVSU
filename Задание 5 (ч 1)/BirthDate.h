#ifndef BIRTHDATE_H
#define BIRTHDATE_H

#include <iostream>
#include <fstream>
using namespace std;

class BirthDate
{
private:
	long long totalDays;
	bool isDuration; // Булевская переменная для проверки разницы между конкретной даты и разницу между датами
	
	static bool isLeapYear(int y);
	static int daysInMonth(int m, int y);
	static long long toDays(int d, int m, int y);
	static void fromDays(long long z, int& d, int& m, int& y);	
public:
	BirthDate();
	BirthDate(int d, int m, int y);
	
	void setDate(int d, int m, int y);
	void getDate(int& d, int& m, int& y) const;
	
	// Перегрузка операторов для совместимости с шаблонами (templates.h)
	bool operator<(const BirthDate& other) const;
	bool operator>(const BirthDate& other) const;
	bool operator<=(const BirthDate& other) const;
	bool operator>=(const BirthDate& other) const;
	bool operator==(const BirthDate& other) const;
	
	BirthDate& operator+=(const BirthDate& other);
	BirthDate& operator/=(int n);
	BirthDate operator-(const BirthDate& other) const;
	
	friend ostream& operator<<(ostream& out, const BirthDate& date);
	friend istream& operator>>(istream& in, BirthDate& date);
	
	bool saveArrayToFile(const char* filename, const BirthDate* arr, int n);
	int loadArrayFromFile(const char* filename, BirthDate* arr, int maxSize);
};

#endif // BIRTHDATE_H
