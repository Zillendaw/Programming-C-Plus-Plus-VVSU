#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

int main()
{
	int pause;
	
	Rectangle Rect_1;
	cout << Rect_1.getNameFile() << endl;
	cout << Rect_1.toString() << endl;
	cin >> pause;
	cout << "Проверка конструктора копирования..." << endl;
	Rectangle Rect_2(10,20,30,40);
	Rectangle Rect_3(Rect_2);
	cout << Rect_3.toString() << endl;
	cout << "------------------------" << endl;	
	cout << Rect_1.toString() << endl;
	cout << Rect_2.toString() << endl;
	cout << Rect_3.toString() << endl;
	cout << "Проверка оператора присваивания..." << endl;
	Rect_1 = Rect_2;
	cout << Rect_1.toString() << endl;
	cout << Rect_2.toString() << endl;
	Rect_2.setCoordinates(2,2,4,4);
	cin >> pause;
	cout << Rect_2.toString() << endl;
	cout << "Создание массива Triangle..." << endl;
	Triangle array_Triang[3];
	for (int i = 0; i < 3; i++)
	{
		cout << array_Triang[i].getNameFile() << endl;
		cout << array_Triang[i].toString() << endl;
	}
	
	cin >> pause;
}
