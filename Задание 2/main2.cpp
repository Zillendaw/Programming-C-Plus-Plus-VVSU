#include <iostream>
#include "MyTime.h"
using namespace std;

int main()
{
	MyTime test(00,90,30);
	
	cout << "ДО нормализации: "; 
	test.info();
	
	cout << "ПОСЛЕ нормализации: ";
	test.normalize();
	test.info();
	
	cout << "Вычитаем секунд 30: ";
	test.substract_seconds(30);
	test.info();
	
	MyTime test_2(00,30,00);
	test.substract_time(test_2);
	test.info();
	
	return 0;
}
