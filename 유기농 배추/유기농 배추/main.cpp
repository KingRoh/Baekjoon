#include<iostream>
#include<cstring>
#define MAX 51
using namespace std;

bool check[MAX][MAX];  // �湮 ����
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int a[MAX][MAX];  // ���� 2���� �迭
int m, n, k; // m ���α���, n ���α���, k ���� ����

void dfs(int x, int y) 
{
	check[x][y] = true;  // �湮�ߴ�

	for (int i = 0; i < 4; i++)   
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)  // �����¿� Ȯ���ؼ� ���� ���̸�
		{
			if (a[nx][ny] == 1)   // �װ� ���߸�
			{
				if (!check[nx][ny])   // �湮 ���ߴٸ�
				{
					dfs(nx, ny);  // �� ���� �켱 Ž�� ����
				}
			}
		}

		else 
			continue;  // ���� ���̸� �ٽ�
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

		int cnt = 0;  // ����� ����

		for (int i = 0; i < k; i++) 
		{
			int x, y;
			cin >> x >> y; // x ������ǥ y ������ǥ
			a[y][x] = 1;
		}

		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++) 
			{
				if (a[i][j] == 1)  // ������̰�
				{
					if (!check[i][j])  // �湮�� �������� dfs
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