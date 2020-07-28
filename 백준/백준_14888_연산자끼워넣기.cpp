#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[11];
int vi[4];
int ar[4];
int resmax = -1000000001, resmin = 1000000001, n;
vector<int> v;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < 4; i++)
		cin >> ar[i];
}

void pro(int ct)
{
	if (ct == n - 1)
	{
		int S = map[0];
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 0)
				S += map[i + 1];
			else if (v[i] == 1)
				S -= map[i + 1];
			else if (v[i] == 2)
				S *= map[i + 1];
			else if (v[i] == 3)
				S /= map[i + 1];
		}
		resmax = max(resmax, S);
		resmin = min(resmin, S);
		return;
	}

	for (int w = 0; w < 4; w++)
	{
		if (ar[w] == 0)
			continue;
		if (vi[w] < ar[w])
		{
			vi[w]++;
			v.push_back(w);
			pro(ct + 1);
			v.pop_back();
			vi[w]--;
		}
	}
}

int main()
{
	input();
	pro(0);
	vector<int> v;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < ar[i]; j++)
			v.push_back(i);
	}

	do {
		int S = map[0];
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 0)
				S += map[i + 1];
			else if (v[i] == 1)
				S -= map[i + 1];
			else if (v[i] == 2)
				S *= map[i + 1];
			else if (v[i] == 3)
				S /= map[i + 1];
		}
		resmax = max(resmax, S);
		resmin = min(resmin, S);
	} while (next_permutation(v.begin(), v.end()));

	cout << resmax << endl << resmin << endl;
	return 0;
}