#include <iostream>

using namespace std;

int main()
{
	int num;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int x, y;

		cin >> x >> y;

		int dis = y - x;

		int count = 0;
		
		int a = 1, b = 1;

		while (dis > 0)
		{
			if (a == b)
			{
				dis = dis - a;
				a++;
				count++;
			}

			else if (a != b)
			{
				dis = dis - b;
				b++;
				count++;
			}
		}

		cout << count << endl;
	}
}