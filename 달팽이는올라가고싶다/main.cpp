#include <iostream>

using namespace std;

int main()
{
	int A, B, V, result;

	cin >> A >> B >> V;

	if ((V - A) % (A - B) == 0)
	{
		result = (V - A) / (A - B);
		result = result + 1;
	}

	else
	{
		result = (V - A) / (A - B);
		result = result + 2;
	}

	cout << result;
}