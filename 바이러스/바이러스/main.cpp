#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

int N, M;  // ��������, ��������
int map[MAX][MAX]; // ���� ��� �׷���
bool visited[MAX]; // ���� �湮 ����
queue<int> q; // BFS�� ����� ť

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
			if (map[v][i] == 1 && visited[i] == false) // ������ �Ǿ��ְ� �湮���� �ʾ�����
			{
				q.push(i);
				visited[i] = true;
				count++;
			}
		}
	}

	cout << count;
}