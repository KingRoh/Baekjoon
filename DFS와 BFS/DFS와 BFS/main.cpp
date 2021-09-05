#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int N, M, V;  // ��������, ��������, ��������
int map[MAX][MAX]; // ���� ��� �׷���
bool visited[MAX]; // ���� �湮 ����
queue<int> q; // BFS�� ����� ť

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
		if (map[v][i] == 1 && visited[i] == false) // ������ �Ǿ��ְ� �湮���� �ʾ�����
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
			if (map[v][i] == 1 && visited[i] == false) // ������ �Ǿ��ְ� �湮���� �ʾ�����
			{
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}