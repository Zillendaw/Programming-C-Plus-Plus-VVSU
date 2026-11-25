#include "BirthDate.h"
using namespace std;

BirthDate::BirthDate() : totalDays(0),isDuration(false) {}

BirthDate::BirthDate(int d, int m, int y) : isDuration(false)
{
	totalDays = toDays(d,m,y);
}

bool BirthDate::isLeapYear(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int BirthDate::daysInMonth(int m, int y)
{
	const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (m == 2 && isLeapYear(y))
	{
		return 29;
	}
	return days[m - 1];
}

long long BirthDate::toDays(int d, int m, int y)
{
	long long total = 0;
	
	for (int year = 1; year < y; year++)
	{
		if (isLeapYear(year))
		{
			total += 366;
		}
		else
		{
			total += 365;
		}
	}
	
	for (int month = 1; month < m; month++)
	{
		total += daysInMonth(month, y);
	}
	
	total += d;
	
	return total;
}	

void BirthDate::fromDays(long long z, int& d, int& m, int& y)
{
	y = 1;
	
	// Вычитаем полные годы, пока дней хватит на целый год
	while (true)
	{
		int daysInYear = 0;
		if (isLeapYear(y))
		{
			daysInYear = 366;
		}
		else
		{
			daysInYear = 365;
		}
		
		if (z > daysInYear)
		{
			z -= daysInYear;
			y++;
		}
		else
		{
			break;
		}
		
	}
	
	m = 1;
	
	// Ввчитаем полные месяцы, пока дней хватает на целый месяц
	while (true)
	{
		int dim = daysInMonth(m,y);
		if(z > dim)
		{
			z -= dim;
			m++;
		}
		else
		{
			break;
		}
	}
	
	// Присваиваем день месяца
	d = static_cast<int>(z);
	
}

void BirthDate::setDate(int d, int m, int y)
{
	totalDays = toDays(d,m,y);
	isDuration = false;
}

void BirthDate::getDate(int& d, int& m, int& y) const
{
	fromDays(totalDays, d, m, y);
}

bool BirthDate::operator<(const BirthDate& other) const
{
	return totalDays < other.totalDays;
}

bool BirthDate::operator>(const BirthDate& other) const
{
	return totalDays > other.totalDays;
}

bool BirthDate::operator<=(const BirthDate& other) const
{
	return totalDays <= other.totalDays;
}

bool BirthDate::operator>=(const BirthDate& other) const
{
	return totalDays >= other.totalDays;
}

bool BirthDate::operator==(const BirthDate& other) const
{
	return totalDays == other.totalDays;
}

BirthDate& BirthDate::operator+=(const BirthDate& other)
{
	totalDays += other.totalDays;
	return *this;
}

BirthDate& BirthDate::operator/=(int n)
{
	if (n != 0)
	{
		totalDays /= n;
	}
	return *this;
}

BirthDate BirthDate::operator-(const BirthDate& other) const
{
	BirthDate diff;
	diff.totalDays = totalDays - other.totalDays;
	diff.isDuration = true;
	return diff;
}

ostream& operator<<(ostream& out, const BirthDate& date)
{
	if (date.isDuration)
	{
		out << date.totalDays << " дн.";
	}
	else
	{
		int d,m,y;
		BirthDate::fromDays(date.totalDays,d,m,y);
		if (d < 10) out << '0';
		out << d << '.';
		if (m < 10) out << '0';
		out << m << '.' << y;
	}
	return out;
}

istream& operator>>(istream& in, BirthDate& date)
{
	int d,m,y;
	char dot1, dot2;
	if (in >> d >> dot1 >> m >> dot2 >> y)
	{
		if (dot1 == '.' && dot2 == '.')
		{
			date.setDate(d,m,y);
		}
		else
		{
			in.setstate(ios::failbit);
		}
	}
	return in;
}

bool BirthDate::saveArrayToFile(const char* filename, const BirthDate* arr, int n)
{
	ofstream file(filename);
	if (!file.is_open())
	{
		cout << "ОШИБКА: ФАЙЛ НЕ ОТКРЫЛСЯ!!!" << endl;
		return false;
	}
	
	for (int i = 0; i < n; i++)
	{
		file << arr[i] << endl;
	}
	
	file.close();
	return true;
}

int BirthDate::loadArrayFromFile(const char* filename, BirthDate* arr, int maxSize)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "ОШИБКА: ФАЙЛ НЕ ОТКРЫЛСЯ!!!" << endl;
		return false;
	}
	
	int count = 0;
	while (count < maxSize && file >> arr[count])
	{
		count++;
	}
	
	file.close();
	return count;
}
