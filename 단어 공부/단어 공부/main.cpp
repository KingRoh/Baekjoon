#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	int alp[26] = { 0, };
	char ans[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
					'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	cin >> word;

	for (int i = 0; i < word.size(); i++)
	{
		if((int)word.at(i) < 91)
			alp[(int)word.at(i) - 65]++;

		else
			alp[(int)word.at(i) - 97]++;
	}

	int max = 0, count = 0;

	for (int i = 0; i < 26; i++)
	{
		if (max < alp[i])
			max = alp[i];
	}

	for (int i = 0; i < 26; i++)
	{
		if (max == alp[i])
			count++;
	}

	if (count == 1)
	{
		for (int i = 0; i < 26; i++)
		{
			if (alp[i] == max)
				cout << ans[i];
		}
	}

	else
		cout << '?' << endl;
}