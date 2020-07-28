#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int ar[50][50];
bool vi[50][50];
int n, m, r, c, l, ans;
queue<pair<pair<int, int>, int>> q;
vector<pair<pair<int, int>, string>> dxy[8];

void input()
{
	ans = 0;
	memset(ar, 0, sizeof(ar));
	memset(vi, false, sizeof(vi));
	while (!q.empty()) q.pop();
	cin >> n >> m >> r >> c >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> ar[i][j];
	}
	q.push({ {r,c},l });
	vi[r][c] = true;
}

void solve()
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();

		ans++;

		for (int w = 0; w < dxy[ar[x][y]].size(); w++)
		{
			int nx = x + dxy[ar[x][y]][w].first.first;
			int ny = y + dxy[ar[x][y]][w].first.second;
			string ns = dxy[ar[x][y]][w].second;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (ar[nx][ny] != 0 && !vi[nx][ny])
			{
				for (int i = 0; i < ns.size(); i++)
				{
					int ct = ns[i] - '0';
					if (t - 1 > 0 && ct == ar[nx][ny])
					{
						vi[nx][ny] = true;
						q.push({ {nx,ny},t - 1 });
						break;
					}
				}
			}

		}
	}
}

int main()
{
	dxy[1].push_back({ { 1,0 }, "1247" });
	dxy[1].push_back({ { -1,0 }, "1256" });
	dxy[1].push_back({ { 0,1 }, "1367" });
	dxy[1].push_back({ { 0,-1 }, "1345" });

	dxy[2].push_back({ { 1,0 }, "2147" });
	dxy[2].push_back({ { -1,0 }, "2156" });

	dxy[3].push_back({ { 0,1 }, "3167" });
	dxy[3].push_back({ { 0,-1 }, "3145" });

	dxy[4].push_back({ { -1,0 }, "1256" });
	dxy[4].push_back({ { 0,1 }, "1367" });

	dxy[5].push_back({ { 1,0 }, "1247" });
	dxy[5].push_back({ { 0,1 }, "1367" });

	dxy[6].push_back({ { 1,0 }, "1247" });
	dxy[6].push_back({ { 0,-1 }, "1345" });

	dxy[7].push_back({ { -1,0 }, "1256" });
	dxy[7].push_back({ { 0,-1 }, "1345" });

	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		input();
		solve();
		cout << "#" << k + 1 << " " << ans << endl;
	}
	return 0;
}