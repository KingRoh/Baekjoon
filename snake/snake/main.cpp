#include <iostream>
#include <list>
#include <utility>

using namespace std;

int main()
{
	list<pair<int, int>> snake;			// �� ���� ����
	snake.push_front(make_pair(1, 1));

	int boad[101][101] = {0};		// ���� * 0 = ����, 1 = ���, 2 = ��
	boad[1][1] = 2;

	int boadSize;			// ���� ũ�� 

	cin >> boadSize;

	int apples;				// ��� ����
	cin >> apples;
	int x, y;				// ��� ��ġ
	for (int i = 0; i < apples; i++)
	{
		cin >> x >> y;

		boad[x][y] = 1;
	}

	int wayTime;			// ���� Ƚ���� ���� ��ȯ �α� �Է� Ƚ�� ����
	cin >> wayTime;
	int times;				// ���� ���� Ƚ��
	char way;				// ���� �Ӹ� ���� ��ȯ
	int direction = 1;		// ���� ����
	int count = 1;			// �� �ð�
	int preTimes = 0;		// ���� �ð�

	for (int i = 0; i < wayTime; i++)
	{
		cin >> times >> way;

		for (int j = 0; j < times - preTimes; j++)
		{
			if (direction == 0)
			{
				pair<int, int> head = snake.front();
				pair<int, int> tail = snake.back();

				// ���� ����ִµ� �� �����Ϸ��ϸ�
				if (head.first == 1)
				{
					cout << count << endl;
					return 0;
				}

				// �����ߴ��� ������
				if (boad[head.first - 1][head.second] == 1)
				{
					boad[head.first - 1][head.second] = 2;
					head = make_pair(head.first - 1, head.second);
					snake.push_front(head);
				}
				// �����ߴ��� �� �����̶��
				else if (boad[head.first - 1][head.second] == 0)
				{
					boad[head.first - 1][head.second] = 2;
					head = make_pair(head.first - 1, head.second);
					snake.push_front(head);
					boad[tail.first][tail.second] = 0;
					snake.pop_back();
				}
				// �����ߴ��� �ڱ� ���̶��
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

				// ���� ����ִµ� �� �����Ϸ��ϸ�
				if (head.second == boadSize)
				{
					cout << count << endl;
					return 0;
				}

				// �����ߴ��� ������
				if (boad[head.first][head.second + 1] == 1)
				{
					boad[head.first][head.second + 1] = 2;
					head = make_pair(head.first, head.second + 1);
					snake.push_front(head);
				}
				// �����ߴ��� �� �����̶��
				else if (boad[head.first][head.second + 1] == 0)
				{
					boad[head.first][head.second + 1] = 2;
					head = make_pair(head.first, head.second + 1);
					snake.push_front(head);
					boad[tail.first][tail.second] = 0;
					snake.pop_back();
				}
				// �����ߴ��� �ڱ� ���̶��
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

				// ���� ����ִµ� �� �����Ϸ��ϸ�
				if (head.first == boadSize)
				{
					cout << count << endl;
					return 0;
				}

				// �����ߴ��� ������
				if (boad[head.first + 1][head.second] == 1)
				{
					boad[head.first + 1][head.second] = 2;
					head = make_pair(head.first + 1, head.second);
					snake.push_front(head);
				}
				// �����ߴ��� �� �����̶��
				else if (boad[head.first + 1][head.second] == 0)
				{
					boad[head.first + 1][head.second] = 2;
					head = make_pair(head.first + 1, head.second);
					snake.push_front(head);
					boad[tail.first][tail.second] = 0;
					snake.pop_back();
				}
				// �����ߴ��� �ڱ� ���̶��
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

				// ���� ����ִµ� �� �����Ϸ��ϸ�
				if (head.second == 1)
				{
					cout << count << endl;
					return 0;
				}

				// �����ߴ��� ������
				if (boad[head.first][head.second - 1] == 1)
				{
					boad[head.first][head.second - 1] = 2;
					head = make_pair(head.first, head.second - 1);
					snake.push_front(head);
				}
				// �����ߴ��� �� �����̶��
				else if (boad[head.first][head.second - 1] == 0)
				{
					boad[head.first][head.second - 1] = 2;
					head = make_pair(head.first, head.second - 1);
					snake.push_front(head);
					boad[tail.first][tail.second] = 0;
					snake.pop_back();
				}
				// �����ߴ��� �ڱ� ���̶��
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

			// ���� ����ִµ� �� �����Ϸ��ϸ�
			if (head.first == 1)
			{
				cout << count << endl;
				return 0;
			}

			// �����ߴ��� ������
			if (boad[head.first - 1][head.second] == 1)
			{
				boad[head.first - 1][head.second] = 2;
				head = make_pair(head.first - 1, head.second);
				snake.push_front(head);
			}
			// �����ߴ��� �� �����̶��
			else if (boad[head.first - 1][head.second] == 0)
			{
				boad[head.first - 1][head.second] = 2;
				head = make_pair(head.first - 1, head.second);
				snake.push_front(head);
				boad[tail.first][tail.second] = 0;
				snake.pop_back();
			}
			// �����ߴ��� �ڱ� ���̶��
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

			// ���� ����ִµ� �� �����Ϸ��ϸ�
			if (head.second == boadSize)
			{
				cout << count << endl;
				return 0;
			}

			// �����ߴ��� ������
			if (boad[head.first][head.second + 1] == 1)
			{
				boad[head.first][head.second + 1] = 2;
				head = make_pair(head.first, head.second + 1);
				snake.push_front(head);
			}
			// �����ߴ��� �� �����̶��
			else if (boad[head.first][head.second + 1] == 0)
			{
				boad[head.first][head.second + 1] = 2;
				head = make_pair(head.first, head.second + 1);
				snake.push_front(head);
				boad[tail.first][tail.second] = 0;
				snake.pop_back();
			}
			// �����ߴ��� �ڱ� ���̶��
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

			// ���� ����ִµ� �� �����Ϸ��ϸ�
			if (head.first == boadSize)
			{
				cout << count << endl;
				return 0;
			}

			// �����ߴ��� ������
			if (boad[head.first + 1][head.second] == 1)
			{
				boad[head.first + 1][head.second] = 2;
				head = make_pair(head.first + 1, head.second);
				snake.push_front(head);
			}
			// �����ߴ��� �� �����̶��
			else if (boad[head.first + 1][head.second] == 0)
			{
				boad[head.first + 1][head.second] = 2;
				head = make_pair(head.first + 1, head.second);
				snake.push_front(head);
				boad[tail.first][tail.second] = 0;
				snake.pop_back();
			}
			// �����ߴ��� �ڱ� ���̶��
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

			// ���� ����ִµ� �� �����Ϸ��ϸ�
			if (head.second == 1)
			{
				cout << count << endl;
				return 0;
			}

			// �����ߴ��� ������
			if (boad[head.first][head.second - 1] == 1)
			{
				boad[head.first][head.second - 1] = 2;
				head = make_pair(head.first, head.second - 1);
				snake.push_front(head);
			}
			// �����ߴ��� �� �����̶��
			else if (boad[head.first][head.second - 1] == 0)
			{
				boad[head.first][head.second - 1] = 2;
				head = make_pair(head.first, head.second - 1);
				snake.push_front(head);
				boad[tail.first][tail.second] = 0;
				snake.pop_back();
			}
			// �����ߴ��� �ڱ� ���̶��
			else
			{
				cout << count << endl;
				return 0;
			}
		}

		count++;
	}
}