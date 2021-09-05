#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	bool underBar = false;
	bool upper = false;

	cin >> a;

	if (a[0] < 97 || a[0] > 122 || a[0] == 95 || a[a.size() - 1] == 95)
	{
		cout << "Error!" << endl;
		return 0;
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 65 && a[i] <= 90)
		{
			upper = true;
		}

		else if (a[i] == 95)
		{
			if (a[i + 1] == 95)
			{
				cout << "Error!" << endl;
				return 0;
			}
			underBar = true;
		}
	}

	if (upper && underBar)
	{
		cout << "Error!" << endl;
		return 0;
	}

	// camel to snake
	else if (upper == true && underBar == false)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a.insert(i, "_");
				i++;
			}
		}

		for (int i = 0; i < a.size(); i++)
		{
			a[i] = tolower(a[i]);
		}
	}

	// snake to camel
	else if (upper == false && underBar == true)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '_')
			{
				a[i + 1] = toupper(a[i + 1]);
				a.erase(i, 1);
			}
		}
	}

	cout << a << endl;
	return 0;
}