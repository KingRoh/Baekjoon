#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

bool visit[301][301];
int x, y;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int bing[301][301] = { 0, };

void dfs(int init_x, int init_y)
{
	visit[init_x][init_y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = init_x + dx[i];
		int ny = init_y + dy[i];

		if (nx < 1 || nx >= x - 1 || ny < 1 || ny >= y - 1) continue;
		if (bing[nx][ny] > 0 && !visit[nx][ny]) dfs(nx, ny);
	}
}

int main()
{
	cin >> x >> y;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> bing[i][j];
		}
	}

	int count = 0;	

	while (1)
	{
		int san[301][301] = { 0, };
		int bing_count = 0;
		bool check = false;
		memset(visit, false, sizeof(visit));

		for (int i = 1; i < x - 1; i++)
		{
			for (int j = 1; j < y - 1; j++)
			{
				if (bing[i][j] > 0 && !visit[i][j])
				{
					bing_count++;
					if (bing_count == 2)
					{
						check = true;
						break;
					}
					dfs(i, j);
				}
			}
		}
		if (check) break;
		if (bing_count == 0)
		{
			cout << 0;
			return 0;
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (bing[i][j] == 0)
					continue;

				else
				{
					if (bing[i - 1][j] == 0 && bing[i][j] != san[i][j])
						san[i][j]++;
					if (bing[i + 1][j] == 0 && bing[i][j] != san[i][j])
						san[i][j]++;
					if (bing[i][j - 1] == 0 && bing[i][j] != san[i][j])
						san[i][j]++;
					if (bing[i][j + 1] == 0 && bing[i][j] != san[i][j])
						san[i][j]++;
				}
			}
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				bing[i][j] = bing[i][j] - san[i][j];
				//cout << bing[i][j] << " ";
			}
			//cout << endl;
		}

		count++;
	}
	
	cout << count;
}