#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

string ReplaceAll(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = 0; //string처음부터 검사
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)  //from을 찾을 수 없을 때까지
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // 중복검사를 피하고 from.length() > to.length()인 경우를 위해서
	}
	return str;
}

bool comp(const string& s1, const string& s2) 
{
	if (s1.size() == s2.size()) 
	{ //사이즈가 같으면, 사전순 앞으로. 
		return s1 < s2;
	}
	return s1.size() > s2.size();    //사이즈 다르면 큰게 앞으로. 
}

int main()
{
	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);

	string a[36] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
					"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
					"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
					"U", "V", "W", "X", "Y", "Z"};

	map<char, int> b;

	b.insert(pair<char, int>('0', 0));	b.insert(pair<char, int>('A', 10));	b.insert(pair<char, int>('K', 20));	b.insert(pair<char, int>('U', 30));
	b.insert(pair<char, int>('1', 1));	b.insert(pair<char, int>('B', 11));	b.insert(pair<char, int>('L', 21));	b.insert(pair<char, int>('V', 31));
	b.insert(pair<char, int>('2', 2));	b.insert(pair<char, int>('C', 12));	b.insert(pair<char, int>('M', 22));	b.insert(pair<char, int>('W', 32));
	b.insert(pair<char, int>('3', 3));	b.insert(pair<char, int>('D', 13));	b.insert(pair<char, int>('N', 23));	b.insert(pair<char, int>('X', 33));
	b.insert(pair<char, int>('4', 4));	b.insert(pair<char, int>('E', 14));	b.insert(pair<char, int>('O', 24));	b.insert(pair<char, int>('Y', 34));
	b.insert(pair<char, int>('5', 5));	b.insert(pair<char, int>('F', 15));	b.insert(pair<char, int>('P', 25));	b.insert(pair<char, int>('Z', 35));
	b.insert(pair<char, int>('6', 6));	b.insert(pair<char, int>('G', 16));	b.insert(pair<char, int>('Q', 26));
	b.insert(pair<char, int>('7', 7));	b.insert(pair<char, int>('H', 17));	b.insert(pair<char, int>('R', 27));
	b.insert(pair<char, int>('8', 8));	b.insert(pair<char, int>('I', 18));	b.insert(pair<char, int>('S', 28));
	b.insert(pair<char, int>('9', 9));	b.insert(pair<char, int>('J', 19));	b.insert(pair<char, int>('T', 29));

	vector<string> v;

	int T, K;
	string str;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	
	sort(v.begin(), v.end(), comp);

	vector<string> v2 = v;

	cin >> K;

	vector<string> toZ;

	int cnt = K;

	while(cnt != 0)
	{
		toZ.push_back(v2[0].substr(0, 1));
		v2[0] = v2[0].substr(1);
		sort(v2.begin(), v2.end(), comp);
		toZ.erase(unique(toZ.begin(), toZ.end()), toZ.end());

		cnt = K - toZ.size();
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < toZ.size(); j++)
		{
			ReplaceAll(v[i], toZ[j], "Z");
		}
	}

	string answer = "";
	int up = 0;
	for (int i = 0; i < v[0].size(); i++)
	{
		int ans = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if ((int)(v[j].size() - i - 1) >= 0)
				ans = ans + b[v[j].at(v[j].size() - i - 1)];
		}
		ans = ans + up;
		up = ans / 36;
		answer.insert(0, a[ans % 36]);
	}

	answer.insert(0, a[up]);
	cout << answer << endl;
}