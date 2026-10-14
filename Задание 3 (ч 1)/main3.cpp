#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
	cout << "Hello world!" << endl;
	
	Fraction f1,f2(1,2),f3(2,3);
	cout << f1 << ", " << f2 << ", " << f3 << endl;
	f1 = f2 + f3;
	cout << f1 << endl;
	
	return 0;
}
