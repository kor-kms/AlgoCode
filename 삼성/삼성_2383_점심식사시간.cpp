#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ar[10][10];
struct person
{
	int x;
	int y;
	bool vi;
};
person p[10];
person st[2];
vector<pair<int, int>> v[2];
int cnt, cct;
int ans = 987654321;

void input()
{
	int n;
	cin >> n;
	cnt = 0;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ar[i][j];
			if (ar[i][j] == 1)
			{
				p[cnt].x = i;
				p[cnt].y = j;
				p[cnt].vi = false;
				cnt++;
			}
			else if (ar[i][j] >= 2)
			{
				if (!flag)
				{
					st[0].x = i;
					st[0].y = j;
					flag = true;
				}
				else
				{
					st[1].x = i;
					st[1].y = j;
				}
			}
		}
	}
}

void pro(int i, int ct)
{
	if (ct == cct)
	{
		for (int w = 0; w < cnt; w++)
		{
			if (p[w].vi)
				v[0].push_back({ abs(p[w].x - st[0].x) + abs(p[w].y - st[0].y), 0 });
			else if (!p[w].vi)
				v[1].push_back({ abs(p[w].x - st[1].x) + abs(p[w].y - st[1].y), 0 });
		}

		if (v[0].size() != 1)
			sort(v[0].begin(), v[0].end());
		if (v[1].size() != 1)
			sort(v[1].begin(), v[1].end());

		int vsum[2] = { 0, };
		int check_p = 0;
		for (int w = 0;; w++)
		{
			for (int q = 0; q < v[0].size(); q++)
			{
				if (v[0][q].second == -1)
					continue;
				if (v[0][q].second == ar[st[0].x][st[0].y])
				{
					v[0][q].second = -1;
					vsum[0]--;
					check_p++;
				}
				if (vsum[0] == 3)
					break;
				if (v[0][q].second == 0)
					vsum[0]++;
				v[0][q].second++;
			}


			if (check_p == cnt)
			{
				ans = min(w, ans);
				break;
			}
		}

		v[0].clear();
		v[1].clear();
		return;
	}

	for (int w = i; w < cnt; w++)
	{
		if (!p[w].vi)
		{
			p[w].vi = true;
			pro(w, ct + 1);
			p[w].vi = false;
		}
	}
}

void solve()
{
	for (int i = 1; i < cnt; i++)
	{
		cct = i;
		pro(0, 0);
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		input();
		solve();

	}
	return 0;
}