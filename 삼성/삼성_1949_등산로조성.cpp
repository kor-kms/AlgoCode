#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, k, mx, ans;
int ar[8][8];
bool vi[8][8];
bool flag;
queue<pair<int, int>> q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void input()
{
	memset(ar, 0, sizeof(ar));
	memset(vi, false, sizeof(vi));
	flag = false;
	mx = 0;
	ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ar[i][j];
			mx = max(mx, ar[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ar[i][j] == mx)
				q.push({ i,j });
		}
	}
}

void pro(int i, int j, int ct, int dk)
{
	for (int w = 0; w < 4; w++)
	{
		int nx = i + dx[w];
		int ny = j + dy[w];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		if (!vi[nx][ny])
		{
			if (ar[i][j] <= ar[nx][ny])
			{
				if (!flag)
				{
					ar[nx][ny] -= dk;
					if (ar[i][j] > ar[nx][ny])
					{
						vi[nx][ny] = true;
						flag = true;
						pro(nx, ny, ct + 1, dk);
						flag = false;
						vi[nx][ny] = false;
					}
					ar[nx][ny] += dk;
				}

				ans = max(ans, ct);
			}
			else
			{
				vi[nx][ny] = true;
				pro(nx, ny, ct + 1, dk);
				vi[nx][ny] = false;
			}
		}
	}
}

void solve()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 1; i <= k; i++)
		{
			vi[x][y] = true;
			pro(x, y, 1, i);
			vi[x][y] = false;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int kk = 0; kk < t; kk++)
	{
		input();
		solve();
		cout << "#" << kk + 1 << " " << ans << endl;
	}
	return 0;
}