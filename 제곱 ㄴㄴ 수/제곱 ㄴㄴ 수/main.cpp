#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool sosu(int num);

int main()
{
	// 제곱수의 배수를 범위에서 빼면 남는 것이 제곱 ㄴㄴ 수 
	// 제곱수의 배수를 구하면 됨

	// 4 9 16 25 36 49 64 81 100 ... 소수의 제곱으로 나누어 떨어지면 된다... 
	// 
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long min, max;

	cin >> min >> max;

	long long* primeNumSquare = new long long[1000000];

	vector<bool> range(max - min + 1, false);

	long long ans = max - min + 1;

	int index = 0;
	for (long long i = 1; i <= (int)sqrt(max); i++)
	{
		if (sosu(i))
		{
			primeNumSquare[index] = i * i;
			index++;
		}
	}

	long long startNumber = 0;

	for (int i = 0; i < index; i++)
	{
		if (min % primeNumSquare[i] != 0)
		{
			startNumber = min / primeNumSquare[i] + 1;
		}
		else
			startNumber = min / primeNumSquare[i];

		while (startNumber * primeNumSquare[i] <= max)
		{
			if (range[startNumber * primeNumSquare[i] - min] == false)
			{
				range[startNumber * primeNumSquare[i] - min] = true;
				ans--;
			}

			startNumber++;
		}

	}
	
	cout << ans;

	delete[] primeNumSquare;
}

bool sosu(int num) {
	if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}