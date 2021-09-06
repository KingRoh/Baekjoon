#include<iostream>
#include<cstring>
#define MAX 51
using namespace std;

bool check[MAX][MAX];  // 방문 여부
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int a[MAX][MAX];  // 배추 2차원 배열
int m, n, k; // m 가로길이, n 세로길이, k 배추 개수

void dfs(int x, int y) 
{
	check[x][y] = true;  // 방문했다

	for (int i = 0; i < 4; i++)   
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)  // 상하좌우 확인해서 범위 안이면
		{
			if (a[nx][ny] == 1)   // 그게 배추면
			{
				if (!check[nx][ny])   // 방문 안했다면
				{
					dfs(nx, ny);  // 또 깊이 우선 탐색 시작
				}
			}
		}

		else 
			continue;  // 범위 밖이면 다시
	}
}

void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = 0;
			check[i][j] = false;
		}
	}
}
int main() {

	int t;

	cin >> t;

	while (t--) 
	{
		cin >> m >> n >> k;

		int cnt = 0;  // 양배추 무리

		for (int i = 0; i < k; i++) 
		{
			int x, y;
			cin >> x >> y; // x 가로좌표 y 세로좌표
			a[y][x] = 1;
		}

		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++) 
			{
				if (a[i][j] == 1)  // 양배추이고
				{
					if (!check[i][j])  // 방문을 안했으면 dfs
					{
						cnt++;  
						dfs(i, j);
					}
				}
			}
		}

		cout << cnt << '\n';

		reset();
		/*memset(check, false, sizeof(check));
		memset(a, 0, sizeof(a));*/
	}
}