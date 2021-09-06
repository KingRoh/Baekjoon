#include <iostream>
#include <string>

using namespace std;

int main()
{
	string ctr[4];

	double ctr_score[4] = {0, };

	cin >> ctr[0] >> ctr[1] >> ctr[2] >> ctr[3];

	string a_team, b_team;

	double w, d, l;

	cout << fixed;
	cout.precision(10);

	for (int i = 0; i < 6; i++)
	{
		cin >> a_team >> b_team >> w >> d >> l;

		if (a_team == ctr[0])
		{
			ctr_score[0] = ctr_score[0] + 3 * w + d;

			if (b_team == ctr[1])
				ctr_score[1] = ctr_score[1] + 3 * l + d;

			else if (b_team == ctr[2])
				ctr_score[2] = ctr_score[2] + 3 * l + d;

			else if (b_team == ctr[3])
				ctr_score[3] = ctr_score[3] + 3 * l + d;
		}

		else if (a_team == ctr[1])
		{
			ctr_score[1] = ctr_score[1] + 3 * w + d;

			if (b_team == ctr[0])
				ctr_score[0] = ctr_score[0] + 3 * l + d;

			else if (b_team == ctr[2])
				ctr_score[2] = ctr_score[2] + 3 * l + d;

			else if (b_team == ctr[3])
				ctr_score[3] = ctr_score[3] + 3 * l + d;
		}

		else if (a_team == ctr[2])
		{
			ctr_score[2] = ctr_score[2] + 3 * w + d;

			if (b_team == ctr[0])
				ctr_score[0] = ctr_score[0] + 3 * l + d;

			else if (b_team == ctr[1])
				ctr_score[1] = ctr_score[1] + 3 * l + d;

			else if (b_team == ctr[3])
				ctr_score[3] = ctr_score[3] + 3 * l + d;
		}

		else if (a_team == ctr[3])
		{
			ctr_score[3] = ctr_score[3] + 3 * w + d;

			if (b_team == ctr[0])
				ctr_score[0] = ctr_score[0] + 3 * l + d;

			else if (b_team == ctr[1])
				ctr_score[1] = ctr_score[1] + 3 * l + d;

			else if (b_team == ctr[2])
				ctr_score[2] = ctr_score[2] + 3 * l + d;
		}
	}

	double ctr_probability[4] = {0,};
	
	bool exist = false;
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		if (ctr_score[i] == 9)
		{
			ctr_probability[i] = 1;
			exist = true;
			count++;
			continue;
		}

		else
		{
			ctr_probability[i] = ctr_score[i] / (ctr_score[0] + ctr_score[1] + ctr_score[2] + ctr_score[3]);
		}
	}

	if (count >= 2)
	{
		for (int i = 0; i < 4; i++)
			cout << ctr_probability[i] << endl;

		return 0;
	}

	if (!exist)
	{
		for (int i = 0; i < 4; i++)
			cout << 2 * ctr_probability[i] << endl;
	}

	else
	{
		double all_probability = 0;

		for (int i = 0; i < 4; i++)
		{
			if (ctr_probability[i] != 1)
			{
				all_probability = all_probability + ctr_probability[i];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (ctr_probability[i] != 1)
			{
				ctr_probability[i] = ctr_probability[i] / all_probability;
			}
			cout << ctr_probability[i] << endl;
		}
	}
}