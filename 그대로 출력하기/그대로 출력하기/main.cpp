#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	while (1)
	{
		getline(cin, a);
		if (a == "")
			break;
		cout << a << endl;
	}
}