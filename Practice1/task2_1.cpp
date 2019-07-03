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
	int n, k;
	cin >> n;
	cin >> k;
	int* items;
	items = new int[n];
	int toPay = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> items[i];
		toPay += items[i];
	}
	sort(items, 0, n - 1);
	for (int i = n - 1; i > n%k; i-=k)
	{
		toPay -= items[i - k + 1];
	}
	cout << toPay << endl;
	delete[] items;
	return 0;
}