#include <iostream>
#include "MyTime.h"
using namespace std;

int main()
{
	MyTime test(00,60,30);
	
	cout << "Объект Test: "; 
	test.info();
	
	MyTime test_2(00,00,-59);
	
	cout << "Объект с -59 секундам: ";
	test_2.info();
	
	
	
	return 0;
}
