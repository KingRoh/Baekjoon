#include <iostream>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;

int main()
{
	int rc[4] = { 0 };
	
	stack<int> s;

	cin >> rc[0] >> rc[1] >> rc[2] >> rc[3];

	int max = rc[0];

	for (int i = 0; i < 4; i++)
	{
		if (max < abs(rc[i]))
			max = abs(rc[i]);
	}

	int setw_max = pow(max * 2, 2) + 1;
	int count = 0;
	while (setw_max != 0)
	{
		setw_max = setw_max / 10;
		count++;
	}

	for (int i = 0; i < max * 2 + 1; i++)
	{
		// 왼쪽
		for (int k = 0; k < max - abs(max - i); k++)
		{
			cout << setw(count) << 1 + pow(max * 2 - k * 2, 2) + i - k << " ";
		}
		// 위
		for (int k = 0; k < max * 2 + 1 - i * 2; k++)
		{
			cout << setw(count) << 1 + pow(max * 2 - i * 2, 2) - k << " ";
		}
		// 아래
		for (int k = 0; k < (i - max) * 2 + 1 && i > max; k++)
		{
			cout << setw(count) << pow((i - max) * 2, 2) + (i - max) * 2 + k + 1 << " ";
		}
		// 오른쪽
		for (int k = 0; k < max - abs(max - i); k++)
		{
			s.push(pow(abs(k * 2 - max * 2), 2) - (max * 2 - (k * 2 + 1)) - i + k);
		}
		for (int k = 0; k < max - abs(max - i); k++)
		{
			cout << setw(count) << s.top() << " ";
			s.pop();
		}

		cout << endl;
	}
}