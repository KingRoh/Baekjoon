#include <iostream>

using namespace std;

int main()
{
	// only 5kg, 5kg and 3kg, only 3kg
	int sugar;

	cin >> sugar;

	if (sugar % 5 == 0)
	{
		cout << sugar / 5;
		return 0;
	}
	
	else
	{
		int count = 0;
		while (sugar > 0)
		{
			sugar = sugar - 3;
			count++;
			
			if (sugar % 5 == 0)
			{
				cout << count + sugar / 5;
				return 0;
			}
		}

		if (sugar == 0)
			cout << count;
		else
			cout << -1;
	}

	return 0;
}