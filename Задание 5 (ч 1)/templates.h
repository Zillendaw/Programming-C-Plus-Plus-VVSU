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

template<class T>
bool isInRange(T value, T min, T max)
{
	bool result;
	
	if (value >= min && value <= max)
	{
		result = 1;
	} 
	else
	{
		result = 0;
	}
	
	return result;
}

template<class T>
int countInRange (T* arr, int n, T min, T max)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (isInRange(arr[i],min,max))
		{
			count++;
		}
	}
	
	return count;
}


#endif // TEMPLATES_H
