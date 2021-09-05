#include <iostream>
#include <cmath>
using namespace std;

const long long Max = pow(10, 18);

long long EarnGcd(long long a, long long b);

int main()
{
	//�Է°� ����
	int input;
	cin >> input;

	long long a = 0, b = 0, m = 0;
	// �ܾ�
	m = 0;

	//�ִ�����
	long long gcd = 1;
	//�ּҴ���
	long long min = Max;

	for (int i = 0; i < input; i++)
	{
		cin >> a >> b;

		// �Ա� ��
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
			
			// ��� ���� �� �˰���
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

	//a�� ū ���� ��ġ��Ű�� ���� ���ǹ��Դϴ�.
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	//��Ŭ���� �˰��� �κ��Դϴ�.
	//b�� 0�� �ɶ�����(a%b), �ݺ����� ���Եǰ�, b�� 0�� ������ a�� GCD�� �Ǵ��ϰ� �����մϴ�.
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}