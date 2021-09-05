#include <iostream>

using namespace std;

int main()
{
	/*ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);*/

	int sMin, sHou, eMin, eHou, target;
	
	cin >> sHou >> sMin >> eHou >> eMin >> target;

	if (eHou - sHou == 0)
	{
		if (eHou % 10 == target || eHou / 10 == target)
		{
			cout << eMin - sMin + 1;
			return 0;
		}
		else
		{
			int count = 0;
			for (sMin; sMin <= eMin; sMin++)
			{
				if (sMin / 10 == target || sMin % 10 == target)
					count++;
			}
			cout << count;
			return 0;
		}
	}

	else
	{
		int count = 0;
		while (1)
		{
			if (sHou / 10 == target || sHou % 10 == target || sMin % 10 == target || sMin / 10 == target)
			{
				count++;
			}

			if (sHou == eHou && sMin == eMin)
			{
				cout << count;
				return 0;
			}

			sMin++;

			if (sMin == 60)
			{
				sMin = 0;
				sHou++;
			}
		}
	}
}