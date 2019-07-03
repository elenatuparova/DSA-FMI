#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;
	int* N;
	N = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> N[i];
	}
    int steps = 0;
	for (int i = 0; i < T; i++)
	{
        if (N[i]!=0)
        {
            steps = floor(log2(N[i])) + 1;
            cout << steps << endl;
        }
        else
        {
            cout<<0<<endl;
        }
	}
	delete[] N;
	return 0;
}