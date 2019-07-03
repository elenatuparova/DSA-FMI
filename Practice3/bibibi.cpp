#include <iostream>
#include <algorithm>
using namespace std;

int findFirst(long* values, int size, long number)
{
	int start = 0;
	int finish = size - 1;
	int middle = 0;
	int index = -1;
	while (start <= finish)
	{
		middle = start + (finish - start) / 2;
		if (values[middle] == number)
		{
			index = middle;
			finish = middle - 1;
		}
		else if (values[middle] > number)
		{
			finish = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}
    if (index != -1)
    {
        index++;
    }
	return index;
}

int findLast(long* values, int size, long number)
{
	int start = 0;
	int finish = size - 1;
	int middle = 0;
	int index = -1;
	while (start <= finish)
	{
		middle = start + (finish - start) / 2;
		if (values[middle] == number)
		{
			index = middle;
			start = middle + 1;
		}
		else if (values[middle] > number)
		{
			finish = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}
    if (index != -1)
    {
        index++;
    }
	return index;
}

int main()
{
	int N = 0;
	cin >> N;
	long* values;
	values = new long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> values[i];
	}
	sort(values, values + N);
	int Q = 0;
	cin >> Q;
	long* searched;
	searched = new long[Q];
	for (int i = 0; i < Q; i++)
	{
		cin >> searched[i];
	}
	for (int i = 0; i < Q; i++)
	{
		cout << findFirst(values, N, searched[i]) << " " << findLast(values, N, searched[i]) << endl;
	}
	delete[] values;
	delete[] searched;
	return 0;
}