#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int map[16][16];
bool vi[16];
int n, ans;
vector<int> v;

void input()
{
	ans = 987654321;
	memset(map, 0, sizeof(map));
	memset(vi, false, sizeof(vi));
	v.clear();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
}

void pro(int ct, int i)
{
	if (ct == n / 2)
	{
		vector<int> nv;
		for (int w = 0; w < n; w++)
		{
			if (!vi[w])
				nv.push_back(w);
		}

		int a = 0, b = 0;
		for (int w = 0; w < v.size() - 1; w++)
		{
			for (int q = w + 1; q < v.size(); q++)
			{
				a += map[v[w]][v[q]] + map[v[q]][v[w]];
				b += map[nv[w]][nv[q]] + map[nv[q]][nv[w]];
			}
		}
		int S = abs(a - b);
		ans = min(ans, S);
		return;
	}

	for (int w = i; w < n; w++)
	{
		if (!vi[w])
		{
			vi[w] = true;
			v.push_back(w);
			pro(ct + 1, w);
			v.pop_back();
			vi[w] = false;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		input();
		pro(0, 0);
		cout << "#" << k + 1 << " " << ans << endl;
	}
	return 0;
}