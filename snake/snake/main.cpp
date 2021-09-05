#include <iostream>
#include <list>
#include <utility>

using namespace std;

int main()
{
	list<pair<int, int>> snake;			// 뱀 몸통 정보
	snake.push_front(make_pair(1, 1));

	int boad[101][101] = {0};		// 보드 * 0 = 공간, 1 = 사과, 2 = 뱀
	boad[1][1] = 2;

	int boadSize;			// 보드 크기 

	cin >> boadSize;

	int apples;				// 사과 갯수
	cin >> apples;
	int x, y;				// 사과 위치
	for (int i = 0; i < apples; i++)
	{
		cin >> x >> y;

		boad[x][y] = 1;
	}

	int wayTime;			// 전진 횟수과 방향 전환 로그 입력 횟수 변수
	cin >> wayTime;
	int times;				// 뱀의 전진 횟수
	char way;				// 뱀의 머리 방향 전환
	int direction = 1;		// 방향 변수
	int count = 1;			// 총 시간
	int preTimes = 0;		// 이전 시간

	for (int i = 0; i < wayTime; i++)
	{
		cin >> times >> way;

		for (int j = 0; j < times - preTimes; j++)
		{
			if (direction == 0)
			{
				pair<int, int> head = snake.front();
				pair<int, int> tail = snake.back();

				// 벽에 닿아있는데 또 전진하려하면
				if (head.first == 1)
				{
					cout << count << endl;
					return 0;
				}

				// 전진했더니 사과라면
				if (boad[head.first - 1][head.second] == 1)
				{
					boad[head.first - 1][head.second] = 2;
					head = make_pair(head.first - 1, head.second);
					snake.push_front(head);
				}
				// 전진했더니 빈 공간이라면
				else if (boad[head.first - 1][head.second] == 0)
				{
					boad[head.first - 1][head.second] = 2;
					head = make_pair(head.first - 1, head.second);
					snake.push_front(head);
					boad[tail.first][tail.second] = 0;
					snake.pop_back();
				}
				// 전진했더니 자기 몸이라면
				else
				{
					cout << count << endl;
					return 0;
				}
			}

			else if (direction == 1)
			{
				pair<int, int> head = snake.front();
				pair<int, int> tail = snake.back();

				// 벽에 닿아있는데 또 전진하려하면
				if (head.second == boadSize)
				{
					cout << count << endl;
					return 0;
				}

				// 전진했더니 사과라면
				if (boad[head.first][head.second + 1] == 1)
				{
					boad[head.first][head.second + 1] = 2;
					head = make_pair(head.first, head.second + 1);
					snake.push_front(head);
				}
				// 전진했더니 빈 공간이라면
				else if (boad[head.first][head.second + 1] == 0)
				{
					boad[head.first][head.second + 1] = 2;
					head = make_pair(head.first, head.second + 1);
					snake.push_front(head);
					boad[tail.first][tail.second] = 0;
					snake.pop_back();
				}
				// 전진했더니 자기 몸이라면
				else
				{
					cout << count << endl;
					return 0;
				}
			}

			else if (direction == 2)
			{
				pair<int, int> head = snake.front();
				pair<int, int> tail = snake.back();

				// 벽에 닿아있는데 또 전진하려하면
				if (head.first == boadSize)
				{
					cout << count << endl;
					return 0;
				}

				// 전진했더니 사과라면
				if (boad[head.first + 1][head.second] == 1)
				{
					boad[head.first + 1][head.second] = 2;
					head = make_pair(head.first + 1, head.second);
					snake.push_front(head);
				}
				// 전진했더니 빈 공간이라면
				else if (boad[head.first + 1][head.second] == 0)
				{
					boad[head.first + 1][head.second] = 2;
					head = make_pair(head.first + 1, head.second);
					snake.push_front(head);
					boad[tail.first][tail.second] = 0;
					snake.pop_back();
				}
				// 전진했더니 자기 몸이라면
				else
				{
					cout << count << endl;
					return 0;
				}
			}

			else if (direction == 3)
			{
				pair<int, int> head = snake.front();
				pair<int, int> tail = snake.back();

				// 벽에 닿아있는데 또 전진하려하면
				if (head.second == 1)
				{
					cout << count << endl;
					return 0;
				}

				// 전진했더니 사과라면
				if (boad[head.first][head.second - 1] == 1)
				{
					boad[head.first][head.second - 1] = 2;
					head = make_pair(head.first, head.second - 1);
					snake.push_front(head);
				}
				// 전진했더니 빈 공간이라면
				else if (boad[head.first][head.second - 1] == 0)
				{
					boad[head.first][head.second - 1] = 2;
					head = make_pair(head.first, head.second - 1);
					snake.push_front(head);
					boad[tail.first][tail.second] = 0;
					snake.pop_back();
				}
				// 전진했더니 자기 몸이라면
				else
				{
					cout << count << endl;
					return 0;
				}
			}

			count++;
		}

		preTimes = times;

		if (way == 'D')
		{
			if (direction == 3)
				direction = 0;
			else
				direction++;
		}
		else
		{
			if (direction == 0)
				direction = 3;
			else
				direction--;
		}
	}

	while (1)
	{
		if (direction == 0)
		{
			pair<int, int> head = snake.front();
			pair<int, int> tail = snake.back();

			// 벽에 닿아있는데 또 전진하려하면
			if (head.first == 1)
			{
				cout << count << endl;
				return 0;
			}

			// 전진했더니 사과라면
			if (boad[head.first - 1][head.second] == 1)
			{
				boad[head.first - 1][head.second] = 2;
				head = make_pair(head.first - 1, head.second);
				snake.push_front(head);
			}
			// 전진했더니 빈 공간이라면
			else if (boad[head.first - 1][head.second] == 0)
			{
				boad[head.first - 1][head.second] = 2;
				head = make_pair(head.first - 1, head.second);
				snake.push_front(head);
				boad[tail.first][tail.second] = 0;
				snake.pop_back();
			}
			// 전진했더니 자기 몸이라면
			else
			{
				cout << count << endl;
				return 0;
			}
		}

		else if (direction == 1)
		{
			pair<int, int> head = snake.front();
			pair<int, int> tail = snake.back();

			// 벽에 닿아있는데 또 전진하려하면
			if (head.second == boadSize)
			{
				cout << count << endl;
				return 0;
			}

			// 전진했더니 사과라면
			if (boad[head.first][head.second + 1] == 1)
			{
				boad[head.first][head.second + 1] = 2;
				head = make_pair(head.first, head.second + 1);
				snake.push_front(head);
			}
			// 전진했더니 빈 공간이라면
			else if (boad[head.first][head.second + 1] == 0)
			{
				boad[head.first][head.second + 1] = 2;
				head = make_pair(head.first, head.second + 1);
				snake.push_front(head);
				boad[tail.first][tail.second] = 0;
				snake.pop_back();
			}
			// 전진했더니 자기 몸이라면
			else
			{
				cout << count << endl;
				return 0;
			}
		}

		else if (direction == 2)
		{
			pair<int, int> head = snake.front();
			pair<int, int> tail = snake.back();

			// 벽에 닿아있는데 또 전진하려하면
			if (head.first == boadSize)
			{
				cout << count << endl;
				return 0;
			}

			// 전진했더니 사과라면
			if (boad[head.first + 1][head.second] == 1)
			{
				boad[head.first + 1][head.second] = 2;
				head = make_pair(head.first + 1, head.second);
				snake.push_front(head);
			}
			// 전진했더니 빈 공간이라면
			else if (boad[head.first + 1][head.second] == 0)
			{
				boad[head.first + 1][head.second] = 2;
				head = make_pair(head.first + 1, head.second);
				snake.push_front(head);
				boad[tail.first][tail.second] = 0;
				snake.pop_back();
			}
			// 전진했더니 자기 몸이라면
			else
			{
				cout << count << endl;
				return 0;
			}
		}

		else if (direction == 3)
		{
			pair<int, int> head = snake.front();
			pair<int, int> tail = snake.back();

			// 벽에 닿아있는데 또 전진하려하면
			if (head.second == 1)
			{
				cout << count << endl;
				return 0;
			}

			// 전진했더니 사과라면
			if (boad[head.first][head.second - 1] == 1)
			{
				boad[head.first][head.second - 1] = 2;
				head = make_pair(head.first, head.second - 1);
				snake.push_front(head);
			}
			// 전진했더니 빈 공간이라면
			else if (boad[head.first][head.second - 1] == 0)
			{
				boad[head.first][head.second - 1] = 2;
				head = make_pair(head.first, head.second - 1);
				snake.push_front(head);
				boad[tail.first][tail.second] = 0;
				snake.pop_back();
			}
			// 전진했더니 자기 몸이라면
			else
			{
				cout << count << endl;
				return 0;
			}
		}

		count++;
	}
}