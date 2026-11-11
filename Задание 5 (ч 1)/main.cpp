#include <iostream>

using namespace std;

int main()
{
	int intArr[5] = {5, 2, -1, -8, 10};
	float floatarr[5] = {3.14, 2.71, 8.4, 1.0/123, 9.8};
	
	cout << minValue(intArr,5) << endl;
	cout << minValue(floatArr, 5) << endl;
	
	return 0;
}
