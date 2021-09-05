#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b);

int main()
{
	int num;
	cin >> num;

	int arr[100] = { 0, };

	vector<int> remainder_gcd;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + num);

	int remainder = arr[0];

	for (int i = 0; i < remainder; i++)
	{
		int now_gcd = 0;
		int j = 1;

		now_gcd = gcd(arr[0] - i, arr[1] - i);

		while (j < num)
		{
			if (now_gcd == 1)
				break;

			now_gcd = gcd(arr[j] - i, now_gcd);
			j++;
		}

		if (now_gcd != 1)
		{
			remainder_gcd.push_back(now_gcd);
		}
	}

	sort(remainder_gcd.begin(), remainder_gcd.end());
	remainder_gcd.erase(unique(remainder_gcd.begin(), remainder_gcd.end()), remainder_gcd.end());

	int end = remainder_gcd.size();

	for (int i = 0; i < end; i++)
	{
		for (int j = 2; j * j < remainder_gcd[i]; j++)
		{
			if (remainder_gcd[i] % j == 0)
			{
				remainder_gcd.push_back(j);
				remainder_gcd.push_back(remainder_gcd[j]/j);
			}
		}
	}

	sort(remainder_gcd.begin(), remainder_gcd.end());
	remainder_gcd.erase(unique(remainder_gcd.begin(), remainder_gcd.end()), remainder_gcd.end());

	for (int i = 0; i < remainder_gcd.size(); i++)
	{
		cout << remainder_gcd[i] << " ";
	}
}

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}