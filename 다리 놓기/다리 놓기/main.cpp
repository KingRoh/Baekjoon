#include <iostream>

using namespace std;

int main()
{
	int T, N, M;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;

		if (N == M)
		{
			cout << 1 << endl;
			continue;
		}
			
		else if (N == 1 || M == 1)
		{
			if (N > M)
				cout << N << endl;
			else
				cout << M << endl;
			continue;
		}

		else if (N - M == 1 || N - M == -1)
		{
			if (N > M)
				cout << N << endl;
			else
				cout << M << endl;
			continue;
		}

		else
		{
			if (M > N)
			{
				int p = N;
				N = M;
				M = p;
			}
			
			if (M < N - M)
				M = N - M;

			long long ans = 1;
			for (long long i = M + 1; i <= N; i++)
			{
				ans = ans * i;
			}
			for (long long i = N - M; i > 1; i--)
			{
				ans = ans / i;
			}
			cout << ans << endl;
		}
	}
}