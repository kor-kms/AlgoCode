#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool vi[101];
int ar[20][20];
int n, ans, stx, sty;
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };

void input()
{
	memset(vi, false, sizeof(vi));
	memset(ar, 0, sizeof(ar));
	ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> ar[i][j];
	}
}

void pro(int x, int y, int ct, int di)
{
	for (int w = di; w < 4; w++)
	{
		int nx = x + dx[w];
		int ny = y + dy[w];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		if (ct > 3 && nx == stx && ny == sty)
		{
			ans = max(ans, ct);
			break;
		}

		if (vi[ar[nx][ny]])
			continue;
		else
		{
			vi[ar[nx][ny]] = true;
			pro(nx, ny, ct + 1, w);
			vi[ar[nx][ny]] = false;
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
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				stx = i;
				sty = j;
				vi[ar[i][j]] = true;
				pro(i, j, 1, 0);
				vi[ar[i][j]] = false;
			}
		}
		if (ans == 0)
			ans = -1;
		cout << "#" << k + 1 << " " << ans << endl;
	}
}