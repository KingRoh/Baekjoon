#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isExist(vector<int> v, int num);
vector<int> remove(vector<int> v, int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	vector<int> v;

	cin >> num;

	string instruction;
	int target = 0;

	for (int i = 0; i < num; i++)
	{
		cin >> instruction;
		if (instruction == "add" || instruction == "remove" || instruction == "check" || instruction == "toggle")
			cin >> target;

		if (instruction == "add")
		{
			if (!isExist(v, target))
			{
				v.push_back(target);
			}
		}

		else if (instruction == "remove")
		{
			v = remove(v, target);
		}

		else if (instruction == "check")
		{
			if (isExist(v, target))
				cout << "1\n";

			else
				cout << "0\n";
		}

		else if (instruction == "toggle")
		{
			if (!isExist(v, target))
				v.push_back(target);

			else
				v = remove(v, target);
		}

		else if (instruction == "all")
		{
			v.clear();
			v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
		}

		else if (instruction == "empty")
		{
			v.clear();
		}
	}
}

bool isExist(vector<int> v, int num)
{
	bool isExist = false;

	for (int j = 0; j < v.size(); j++)
	{
		if (v[j] == num)
		{
			isExist = true;
			break;
		}
	}

	return isExist;
}

vector<int> remove(vector<int> v, int num)
{
	for (int j = 0; j < v.size(); j++)
	{
		if (v[j] == num)
		{
			v.erase(v.begin() + j);
			break;
		}
	}
	return v;
}