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
	
	return 0;
}
