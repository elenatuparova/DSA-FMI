#include <iostream>
#include <math.h>
using namespace std;

int getMaxIndex(int* values, int size)
{
	int maxIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (values[maxIndex] < values[i])
		{
			maxIndex = i;
		}
	}
	return maxIndex;
}

bool canDry(int* values, int size, int minutes, int dryer)
{
	long totalMinutes = 0;
	for (int i = 0; i < size; i++)
	{
		double estimated = values[i] - minutes;
		if (estimated > 0)
		{
			estimated = ceil(estimated / (dryer - 1));
			totalMinutes = totalMinutes + estimated;
		}
	}
	if (totalMinutes <= minutes)
	{
		return true;
	}
	return false;
}

int getMinTime(int* values, int size, int dryer, int maxMinutes)
{
	int middle = 0;
	int minTime = maxMinutes;
	int minMinutes = 0;
	while (minMinutes <= maxMinutes)
	{
		middle = minMinutes + (maxMinutes - minMinutes) / 2;
		if (canDry(values, size, middle, dryer))
		{
			minTime = middle;
			maxMinutes = middle - 1;
		}
		else
		{
			minMinutes = middle + 1;
		}
	}
	return minMinutes;
}

int main()
{
	int N = 0;
	int K = 0;
	cin >> N;
	cin >> K;
	int* clothes;
	clothes = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> clothes[i];
	}
	int maxTime = clothes[getMaxIndex(clothes, N)];
    if(K>1)
    {
        cout << getMinTime(clothes, N, K, maxTime) << endl;
    }
	else
    {
        cout<<maxTime<<endl;
    }
	delete[] clothes;
	return 0;
}