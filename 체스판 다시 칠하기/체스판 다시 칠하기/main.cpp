#include <iostream>
#include <string>

using namespace std;

int main()
{
	int r, c, cnt = 0;
	int min = 100;
	string input = "";
	bool board[51][51];  // board[0][0]은 사용하지 않는다

	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		cin >> input;

		for (int j = 1; j <= c; j++)
		{
			if (input.at(j - 1) == 'B')
				board[i][j] = false;
			else
				board[i][j] = true;
		}
	}

	for (int i = 1; i <= r - 7; i++)
	{
		for (int j = 1; j <= c - 7; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					if (board[i + 2 * k][j + 2 * l] == false)
						cnt++;

					if (board[i + 2 * k + 1][j + 2 * l + 1] == false)
						cnt++;

					if (board[i + 2 * k][j + 2 * l + 1] == true)
						cnt++;

					if (board[i + 2 * k + 1][j + 2 * l] == true)
						cnt++;
				}
			}

			if (min > cnt)
				min = cnt;

			cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					if (board[i + 2 * k][j + 2 * l] == true)
						cnt++;

					if (board[i + 2 * k + 1][j + 2 * l + 1] == true)
						cnt++;

					if (board[i + 2 * k][j + 2 * l + 1] == false)
						cnt++;

					if (board[i + 2 * k + 1][j + 2 * l] == false)
						cnt++;
				}
			}

			if (min > cnt)
				min = cnt;

			cnt = 0;
		}
	}

	cout << min;
}