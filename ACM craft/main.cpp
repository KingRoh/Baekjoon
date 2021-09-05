#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int T, N, K, W;  // �׽�Ʈ����, �ǹ�����, �Ǽ���������, ��ǥ�ǹ���ȣ
int map[MAX][MAX]; // ���� ��� �׷���
int sec[MAX]; // �Ҹ�ð�
int result[MAX]; // �ش� �ǹ����� �ɸ��� �ð�
queue<int> q; // BFS�� ����� ť
int cnt; // ���� �ɸ��� �ð�

void BFS(int v);
void reset();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;
		
		for (int j = 0; j < N; j++)
		{
			cin >> sec[j + 1];
		}

		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		cin >> W;

		BFS(W);

		cout << cnt << "\n";

		reset();
		cnt = 0;
	}
}

void reset()
{
	for (int i = 0; i <= N; i++)
	{
		sec[i] = 0;
		result[i] = 0;
		for (int j = 0; j <= N; j++)
			map[i][j] = 0;
	}
}

void BFS(int v)
{
	cnt = result[v] = sec[v];
	
	q.push(v);

	while (!q.empty())
	{
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (map[i][v] == 1) // ������ �Ǿ��ִٸ�
			{
				if (result[i] < result[v] + sec[i])
					result[i] = result[v] + sec[i];
				cnt = result[i];
				q.push(i);
			}
		}

	}
}