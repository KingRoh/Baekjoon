#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

int N, M;  // 정점개수, 간선개수
int map[MAX][MAX]; // 인접 행렬 그래프
bool visited[MAX]; // 정점 방문 여부
queue<int> q; // BFS에 사용할 큐

void reset();
void BFS();

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	BFS();

	return 0;
}

void reset()
{
	for (int i = 0; i <= N; i++)
		visited[i] = false;
}

void BFS()
{
	q.push(1);
	visited[1] = true;
	int count = 0;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		for (int i = 1; i <= N; i++)
		{
			if (map[v][i] == 1 && visited[i] == false) // 연결이 되어있고 방문하지 않았으면
			{
				q.push(i);
				visited[i] = true;
				count++;
			}
		}
	}

	cout << count;
}