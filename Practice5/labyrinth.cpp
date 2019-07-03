#include <iostream>
#include <queue>
using namespace std;

struct Cell
{
	int row;
	int column;
};

void passCell(int** maze, int M, int N, queue<Cell> &passed, int row, int column, int distance)
{
	if (maze[row][column] == 0)
	{
		maze[row][column] = distance + 1;
		Cell newCell;
		newCell.row = row;
		newCell.column = column;
		passed.push(newCell);
	}
}

void findPaths(int** maze, int M, int N)
{
	queue<Cell> passedCells;
	int row = 0;
	int column = 0;
	int distance = 0;
	passCell(maze, M, N, passedCells, row, column, distance);
	while (passedCells.size() > 0)
	{
		Cell currentCell = passedCells.front();
		passedCells.pop();
		row = currentCell.row;
		column = currentCell.column;
		distance = maze[row][column];
		if (column + 1 < M)
		{
			passCell(maze, M, N, passedCells, row, column + 1, distance);
		}
		if (column - 1 >= 0)
		{
			passCell(maze, M, N, passedCells, row, column - 1, distance);
		}
		if (row + 1 < N)
		{
			passCell(maze, M, N, passedCells, row + 1, column, distance);
		}
		if (row - 1 >= 0)
		{
			passCell(maze, M, N, passedCells, row - 1, column, distance);
		}
	}
}

int main()
{
	int M = 0;
	cin >> M;
	int N = 0;
	cin >> N;
	int K = 0;
	cin >> K;
	int** maze;
	maze = new int*[M];
	for (int i = 0; i < M; i++)
	{
		maze[i] = new int[N];
	}
	int input = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			if (input == 0)
			{
				maze[i][j] = 0;
			}
			else
			{
				maze[i][j] = -1;
			}
		}
	}
	findPaths(maze, M, N);
	int* moves;
	moves = new int[K];
	int x = 0;
	int y = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> x;
		cin >> y;
		if (maze[x][y] == -1 || maze[x][y] == 0)
		{
			moves[i] = -1;
		}
		else
		{
			moves[i] = maze[x][y] - 1;
		}
	}
	for (int i = 0; i < K; i++)
	{
		cout << moves[i] << endl;
	}
	return 0;
}