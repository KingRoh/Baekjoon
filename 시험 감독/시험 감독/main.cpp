#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int placeNum = 0, mainMan = 0, subMan = 0;
	
	cin >> placeNum;

	int *testPlace = new int[placeNum];

	long long count = placeNum;

	for (int i = 0; i < placeNum; i++)
	{
		cin >> testPlace[i];
	}

	cin >> mainMan >> subMan;

	for (int i = 0; i < placeNum; i++)
	{
		testPlace[i] = testPlace[i] - mainMan;

		if (testPlace[i] > 0)
		{
			int share = testPlace[i] / subMan;

			if (testPlace[i] % subMan != 0)
				share++;

			count = count + share;
		}
	}

	cout << count;

	delete[] testPlace;
}