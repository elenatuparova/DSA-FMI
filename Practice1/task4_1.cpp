#include <iostream>
#include <algorithm>
using namespace std;

struct SockPair
{
	int lengthDiff, shorterSock, longerSock;
};

bool comparePairs(SockPair first, SockPair second)
{
	if (first.lengthDiff != second.lengthDiff)
	{
		return first.lengthDiff < second.lengthDiff;
	}
	return first.shorterSock < second.shorterSock;
}

int main()
{
	int n, k;
	cin >> n;
	cin >> k;

	int* socksLength;
	socksLength = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> socksLength[i];
	}

	sort(socksLength, socksLength + 1);

	int numPairs = n*(n - 1) / 2;
	SockPair* pairs;
	pairs = new SockPair[numPairs];
	int currentPair = -1;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			currentPair++;
			pairs[currentPair].lengthDiff = socksLength[j] - socksLength[i];
			pairs[currentPair].shorterSock = socksLength[i];
			pairs[currentPair].longerSock = socksLength[j];
		}
	}

	sort(pairs, pairs + numPairs, comparePairs);
	cout << pairs[k - 1].shorterSock << " " << pairs[k - 1].longerSock << endl;

	delete[] socksLength;
	delete[] pairs;
	return 0;
}