#ifndef TEMPLATES_H
#define TEMPLATES_H

template<class T>
T minValue(T* arn, int n)
{
	T result = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < result)
		{
			result = arr[i];
		}
	}
	return result;
}

#endif // TEMPLATES_H
