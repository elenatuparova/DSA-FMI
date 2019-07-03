#include <iostream>
using namespace std;

const int CARS_NUM = 3;

int getMinTime(int* time)
{
	int minIndex = 0;
	for (int i = 0; i < CARS_NUM; i++)
	{
		if (time[i] < time[minIndex])
		{
			minIndex = i;
		}
	}
	return time[minIndex];
}

int getMaxTime(int* time)
{
	int maxIndex = 0;
	for (int i = 0; i < CARS_NUM; i++)
	{
		if (time[i] > time[maxIndex])
		{
			maxIndex = i;
		}
	}
	return time[maxIndex];
}

void printTime(int time)
{
	cout << time / 60 << ":";
	if (time % 60 < 10)
	{
		cout << 0 << time % 60 << endl;
	}
	else
	{
		cout << time % 60 << endl;
	}
}

int main()
{
	int hourDep = 0;
	int minutesDep = 0;
	int hourArr = 0;
	int minutesArr = 0;
	bool isValid = 1;
	int time[CARS_NUM];
	for (int i = 0; i < CARS_NUM; i++)
	{
		cin >> hourDep >> minutesDep >> hourArr >> minutesArr;
		if (minutesArr >= minutesDep)
		{
			time[i] = minutesArr - minutesDep;
			if (hourArr >= hourDep)
			{
				time[i] += (hourArr - hourDep) * 60;
			}
			else
			{
				time[i] += (24 - (hourDep - hourArr)) * 60;
			}
		}
		else
		{
			time[i] = 60 + minutesArr - minutesDep;
			if (hourArr >= hourDep)
			{
				time[i] += (hourArr - hourDep - 1) * 60;
			}
			else
			{
				time[i] += (24 - (hourDep - hourArr) - 1) * 60;
			}
		}
	}
	printTime(getMinTime(time));
	printTime(getMaxTime(time));
	return 0;
}