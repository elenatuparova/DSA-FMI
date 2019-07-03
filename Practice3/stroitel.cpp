#include <iostream>
using namespace std;

struct Building{ int height, price; };

int getMin(Building* b, int size)
{
	int min = b[0].height;
	for (int i = 1; i < size; i++)
	{
		if (b[i].height < min)
		{
			min = b[i].height;
		}
	}
	return min;
}

int getMax(Building* b, int size)
{
	int max = b[0].height;
	for (int i = 1; i < size; i++)
	{
		if (b[i].height > max)
		{
			max = b[i].height;
		}
	}
	return max;
}

int main()
{
	int N = 0;
	cin >> N;
	Building* buildings;
	buildings = new Building[N];
	for (int i = 0; i < N; i++)
	{
		cin >> buildings[i].height;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> buildings[i].price;
	}
	int minHeight = getMin(buildings, N);
	int maxHeight = getMax(buildings, N);
	int difference = maxHeight - minHeight;
	long totalMin = 0;
	for (int i = 0; i < N; i++)
	{
		totalMin = totalMin + abs((buildings[i].height - minHeight))*buildings[i].price;
	}
	long current = 0;
	for (int i = 1; i <= difference; i++)
	{
		for (int j = 0; j < N; j++)
		{
			current = current + abs((buildings[j].height - getMin(buildings, N) - i))*buildings[j].price;
		}
		if (current < totalMin)
		{
			totalMin = current;
		}
		current = 0;
	}
	cout << totalMin << endl;
	return 0;
}