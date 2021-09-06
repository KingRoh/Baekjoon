#include <iostream>
#include <cmath>

using namespace std;

int getMaxPosition(int page);

int main()
{
	int position = 0, max_position, page;

	long long ans[10] = { 0, };

	cin >> page;

	int c_page = page;
	int zeroPage = page;

	while (1)
	{
		if (c_page < 10)
		{
			max_position = c_page;
			position++;
			break;
		}
		c_page = c_page / 10;
		position++;
	}

	int lastNum = page % 10;

	if (page > 10)
	{
		for (int j = 1; j < max_position; j++)
		{
			ans[j] = ans[j] + pow(10, position - 1);
		}
		ans[max_position] = page - (int)(page / pow(10, position - 1)) * pow(10, position - 1) + 1;
	}
	else
	{
		cout << 0 << " ";
		for (int i = 1; i <= page; i++)
			cout << 1 << " ";
		for (int i = 0; i < 9 - page; i++)
			cout << 0 << " ";

		return 0;
	}
	
	// 0이 연속해서 나오는 경우 예외 처리 필요함

	for (int i = position; i > 1; i--)
	{
		for (int j = 1; j < 10; j++)
		{
			max_position = getMaxPosition(page - (int)(page / pow(10, i - 1)) * pow(10, i - 1));

			if (j < max_position)
			{
				ans[j] = ans[j] + (int)(page / pow(10, i - 1) + 1) * pow(10, i - 2);
			}
			else if (j == max_position)
				ans[j] = ans[j] + (int)(page / pow(10, i - 1)) * pow(10, i - 2) + page - (int)(page / pow(10, i - 2)) * pow(10, i - 2) + 1;
			else
				ans[j] = ans[j] + (int)(page / pow(10, i - 1)) * pow(10, i - 2);

		}
	}

	long long num = position * (page - pow(10, position - 1) + 1);

	for (int i = 1; i < position; i++)
	{
		num = num + i * pow(10, i - 1) * 9;
	}

	ans[0] = num;

	for (int i = 1; i < 10; i++)
		ans[0] = ans[0] - ans[i];

	//cout << num << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << ans[i] << " ";
	}
}

int getMaxPosition(int page)
{
	int mp = 0;
	while (1)
	{
		if (page < 10)
		{
			return page;
		}
		page = page / 10;
	}
}