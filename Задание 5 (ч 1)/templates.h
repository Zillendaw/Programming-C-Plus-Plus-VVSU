#ifndef TEMPLATES_H
#define TEMPLATES_H

template<class T>
T minValue(T* arr, int n)
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

template<class T>
T maxValue(T* arr, int n)
{
	T result = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > result)
		{
			result = arr[i];
		}
	}
	return result;
}

template<class T>
T avgValue(T* arr, int n)
{
	T result = arr[0];
	for (int i = 1; i < n; i++)
	{
		result += arr[i];
	}
	
	result /= n;
	
	return result;
}

template<class T>
T valueRange(T* arr, int n)
{
	T result = maxValue(arr, n) - minValue(arr, n);
	
	return result;
}



#endif // TEMPLATES_H
