#include <iostream>
using namespace std;

void sort(int* values, int leftIndex, int rightIndex)
{
	int i = leftIndex;
	int j = rightIndex;
	int pivot = values[(leftIndex + rightIndex) / 2];

	while (i <= j)
	{
		while (values[i] < pivot)
		{
			i++;
		}
		while (values[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			swap(values[i], values[j]);
			i++;
			j--;
		}
	}

	if (leftIndex < j)
	{
		sort(values, leftIndex, j);
	}
	if (i < rightIndex)
	{
		sort(values, i, rightIndex);
	}
}

int main()
{
	int n = 0;
	int k = 0;
	cin >> n;
	cin >> k;
	int* toys;
	toys = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> toys[i];
	}
	sort(toys, 0, n - 1);
	int toPay = 0;
	int numToys = 0;
	for (int i = 0; i < n; i++)
	{
		if (toPay + toys[i] <= k)
		{
			toPay += toys[i];
			numToys++;
		}
		else
		{
			break;
		}
	}
	cout << numToys << endl;
	delete[] toys;
	return 0;
}