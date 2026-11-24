#include <iostream>
#include "templates.h"

using namespace std;

int main()
{
	int intArr[5] = {5, 2, -1, -8, 10};
	float floatArr[5] = {3.14, 2.71, 8.4, 1.0/123, 9.8};
	
	cout << minValue(intArr,5) << endl;
	cout << maxValue(intArr, 5) << endl;
	cout << avgValue(intArr,5) << endl;
	cout << valueRange(intArr,5) << endl;
	cout << isInRange(-1,-8,10) << endl;
	cout << countInRange(intArr,5,0,10) << endl;
	
	return 0;
}
