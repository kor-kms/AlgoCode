#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int ans, n, m, c;
int flag;
int map[10][10];
bool vi[10][10];

void input()
{
	memset(map, 0, sizeof(map));
	memset(vi, false, sizeof(vi));
	flag = 0;
	ans = 0;
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
}

void pro(int x, int res)
{
	if (flag == 2)
	{
		ans = max(ans, res);
		return;
	}

	for (int i = x; i < n; i++)
	{
		for (int j = 0; j <= n - m; j++)
		{
			if (!vi[i][j])
			{
				bool che = false;
				vector<pair<int, pair<int, int>>> v;
				vector<pair<int,int>> chev;

				for (int w = j; w < j + m; w++)
				{
					if (vi[i][w])
					{
						che = true;
						break;
					}
					v.push_back({ map[i][w],{i,w} });
				}
				if (che)
					continue;

				int resmx = 0;
				do {
					vector<pair<int,int>> cc;
					int mx = 0;
					int csize = 0;
					for (int w = 0; w < v.size(); w++)
					{
						csize += v[w].first;
						if (csize <= c)
						{
							mx += v[w].first * v[w].first;
							cc.push_back({ v[w].second.first,v[w].second.second });
						}
						else
							continue;
					}

					if (resmx < mx)
					{
						chev = cc;
						resmx = mx;
					}
				} while (next_permutation(v.begin(), v.end()));

				for (int w = 0; w < chev.size(); w++)
					vi[chev[w].first][chev[w].second] = true;

				flag++;
				pro(i + 1, res + resmx);
				flag--;

				for (int w = 0; w < chev.size(); w++)
					vi[chev[w].first][chev[w].second] = false;
			}
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