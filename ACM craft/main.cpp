#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int T, N, K, W;  // 테스트개수, 건물개수, 건설순서개수, 목표건물번호
int map[MAX][MAX]; // 인접 행렬 그래프
int sec[MAX]; // 소모시간
int result[MAX]; // 해당 건물까지 걸리는 시간
queue<int> q; // BFS에 사용할 큐
int cnt; // 최종 걸리는 시간

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
			if (map[i][v] == 1) // 연결이 되어있다면
			{
				if (result[i] < result[v] + sec[i])
					result[i] = result[v] + sec[i];
				cnt = result[i];
				q.push(i);
			}
		}

	}
}