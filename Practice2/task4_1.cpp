#include <iostream>
using namespace std;

long mergeAndCount(int** values, int queryNumber, int start, int middle, int finish)
{
	int i = start;
	int j = middle;
	int k = start;
	long inversionsNumber = 0;
	int* temp;
	temp = new int[finish + 1];

	while ((i <= middle - 1) && (j <= finish))
	{
		if (values[queryNumber][i] <= values[queryNumber][j])
		{
			temp[k] = values[queryNumber][i];
			k++;
			i++;
		}
		else
		{
			temp[k] = values[queryNumber][j];
			k++;
			j++;
			inversionsNumber = inversionsNumber + (middle - i);
		}
	}
	
	while (i <= middle - 1)
	{
		temp[k] = values[queryNumber][i];
		k++;
		i++;
	}

	while (j <= finish)
	{
		temp[k] = values[queryNumber][j];
		k++;
		j++;
	}

	for (int n = start; n <= finish; n++)
	{
		values[queryNumber][n] = temp[n];
	}

	delete[] temp;
	return inversionsNumber;
}

long sortAndCount(int** values, int queryNumber, int start, int finish)
{
    long inversionsNumber = 0;

	if (start < finish)
	{
		int middle = (start + finish) / 2;
		inversionsNumber = sortAndCount(values, queryNumber, start, middle);
		inversionsNumber += sortAndCount(values, queryNumber, middle + 1, finish);
		inversionsNumber += mergeAndCount(values, queryNumber, start, middle + 1, finish);
	}

	return inversionsNumber;
}

int main()
{
	int q = 0;
	int n = 0;
	cin >> q;
	int** queries;
	queries = new int*[q];
	long* inversions;
	inversions = new long[q];

	for (int i = 0; i < q; i++)
	{
		inversions[i] = 0;
		cin >> n;
		queries[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> queries[i][j];
		}
		inversions[i] = sortAndCount(queries, i, 0, n - 1);
	}

	for (int i = 0; i < q; i++)
	{
		cout << inversions[i] << endl;
	}

	delete[] inversions;
	for (int i = 0; i < q; i++)
	{
		delete[] queries[i];
	}
	delete[] queries;
	return 0;
}