#include <iostream>
#include <cmath>
using namespace std;

const long long Max = pow(10, 18);

long long EarnGcd(long long a, long long b);

int main()
{
	//입력값 갯수
	int input;
	cin >> input;

	long long a = 0, b = 0, m = 0;
	// 잔액
	m = 0;

	//최대공약수
	long long gcd = 1;
	//최소단위
	long long min = Max;

	for (int i = 0; i < input; i++)
	{
		cin >> a >> b;

		// 입금 시
		if (a > 0)
		{
			if (m == 0)
			{
				if (a == b)
					m = b;
				else
				{
					cout << -1 << endl;
					return 0;
				}
			}

			else
			{
				if (b != m + a)
				{
					cout << -1 << endl;
					return 0;
				}

				else
					m = b;
			}
		}
		
		else if (a == 0)
		{
			if (m != b)
			{
				cout << -1 << endl;
				return 0;
			}
		}

		// a < 0
		else
		{
			if (m >= -a)
			{
				if (b != m + a)
				{
					cout << -1 << endl;
					return 0;
				}

				else
					m = b;
			}
			
			// 출금 오버 시 알고리즘
			else
			{
				if (gcd == 1)
					gcd = -(m + a - b);
				else
				{
					gcd = EarnGcd(gcd, -(m + a - b));
				}

				m = b;

				if (b != 0 && b < min)
					min = b;

				if (min != Max && min >= gcd)
				{
					cout << -1 << endl;
					return 0;
				}

				if (gcd == 1 && b != 0)
				{
					cout << -1 << endl;
					return 0;
				}

			}
		}
	}

	cout << gcd << endl;
}

long long EarnGcd(long long a, long long b) {
	long long tmp, n;

	//a에 큰 값을 위치시키기 위한 조건문입니다.
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	//유클리드 알고리즘 부분입니다.
	//b가 0이 될때까지(a%b), 반복문을 돌게되고, b가 0인 순간의 a를 GCD로 판단하고 리턴합니다.
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}