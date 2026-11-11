#include <iostream>
#include <fstream>
#include <cmath>
#include "decart.h"
#include "sphera.h"

using namespace std;

const double PI = acos(-1.0);
const double EARTH_R = 6371000.0;

double degToRad(double deg)
{
	return deg * PI / 180.0;
}

int main()
{
	// Тестирование на простых точках
	cout << "Тест объектов класса:" << endl;
	Decart d1, d2(3, 4, 5), dZero(0, 0, 0);
	Sphera s1, s2(0.5, 1.0, 10.0);

	// Проверка конструкторов преобразования
	d1 = s2;
	cout << "s2 -> d1: " << d1 << endl;
	s1 = d2;
	cout << "d2 -> s1: " << s1 << endl;

	// Проверка защиты от деления на ноль (R = 0)
	Sphera sZero = dZero;
	cout << "dZero (0,0,0) -> sZero: " << sZero << endl;

	// Проверка явного вызова операторов преобразования
	Decart d3 = static_cast<Decart>(s2);
	Sphera s3 = static_cast<Sphera>(d2);

	// Проверка расстояний на простых точках:
	// Точка А (0°, 0°) и Точка Б (0°, 90°) на экваторе (четверть окружности Земли)
	Sphera pA(degToRad(0), degToRad(0), EARTH_R);
	Sphera pB(degToRad(90), degToRad(0), EARTH_R);
	Decart dA = pA;
	Decart dB = pB;

	cout << "Евклидово расстояние (хорда 90 град): " 
	     << Decart::euclideanDistance(dA, dB) << " м" << endl;
	cout << "Расстояние по дуге (дуга 90 град):    " 
	     << Sphera::bigCircleDistance(pA, pB) << " м\n" << endl;


	// Работа с файлом
	cout << "Начинаем работу с файлом..." << endl;
	const int N = 1000;
	Sphera sPoints[N];
	Decart dPoints[N];

	ifstream file("Задание 3 часть 2 данные.txt");
	if (!file.is_open())
	{
		cerr << "Ошибка: не удалось открыть файл!" << endl;
		return 1;
	}

	int count = 0;
	double lat_deg, lon_deg;

	// Чтение в порядке: широта (lat), долгота (lon) в градусах
	while (count < N && (file >> lat_deg >> lon_deg))
	{
		double lat_rad = degToRad(lat_deg);
		double lon_rad = degToRad(lon_deg);

		// В конструктор Sphera передаем (lon, lat, R)
		sPoints[count] = Sphera(lon_rad, lat_rad, EARTH_R);
		dPoints[count] = sPoints[count]; // Преобразование в декартовы координаты
		count++;
	}
	file.close();

	cout << "Прочитано точек: " << count << endl;

	if (count < 2)
	{
		cerr << "Недостаточно точек для поиска расстояний." << endl;
		return 1;
	}

	double maxEuclid = -1.0;
	int eIdx1 = 0, eIdx2 = 0;

	double maxCircle = -1.0;
	int cIdx1 = 0, cIdx2 = 0;

	// Перебор всех пар точек
	for (int i = 0; i < count; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			double eDist = Decart::euclideanDistance(dPoints[i], dPoints[j]);
			if (eDist > maxEuclid)
			{
				maxEuclid = eDist;
				eIdx1 = i;
				eIdx2 = j;
			}

			double cDist = Sphera::bigCircleDistance(sPoints[i], sPoints[j]);
			if (cDist > maxCircle)
			{
				maxCircle = cDist;
				cIdx1 = i;
				cIdx2 = j;
			}
		}
	}

	cout << "\n1) Максимальное евклидово расстояние: " << maxEuclid << " м" << endl;
	cout << "   Между точкой [" << eIdx1 << "]: (" << dPoints[eIdx1] << ")" << endl;
	cout << "   и точкой     [" << eIdx2 << "]: (" << dPoints[eIdx2] << ")" << endl;

	cout << "\n2) Максимальное расстояние по дуге: " << maxCircle << " м" << endl;
	cout << "   Между точкой [" << cIdx1 << "]: (" << sPoints[cIdx1] << ")" << endl;
	cout << "   и точкой     [" << cIdx2 << "]: (" << sPoints[cIdx2] << ")" << endl;

	return 0;
}
