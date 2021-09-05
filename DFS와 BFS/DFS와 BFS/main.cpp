#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int N, M, V;  // 정점개수, 간선개수, 시작정점
int map[MAX][MAX]; // 인접 행렬 그래프
bool visited[MAX]; // 정점 방문 여부
queue<int> q; // BFS에 사용할 큐

void reset();
void DFS(int v);
void BFS(int v);

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	DFS(V);

	cout << "\n";

	reset();
	BFS(V);

	return 0;
}

void reset()
{
	for (int i = 0; i <= N; i++)
		visited[i] = false;
}

void DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++)
		if (map[v][i] == 1 && visited[i] == false) // 연결이 되어있고 방문하지 않았으면
			DFS(i);
}

void BFS(int v)
{
	q.push(v);
	visited[v] = true;

	cout << v << " ";

	while (!q.empty())
	{
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (map[v][i] == 1 && visited[i] == false) // 연결이 되어있고 방문하지 않았으면
			{
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}