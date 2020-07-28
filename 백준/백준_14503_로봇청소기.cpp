#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans;
int map[50][50];
bool vi[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct robot
{
	int x;
	int y;
	int dir;
};
robot R;

void input()
{
	cin >> n >> m;
	cin >> R.x >> R.y >> R.dir;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) vi[i][j] = 1;
		}
	}
}

void solve()
{
	vi[R.x][R.y] = true;
	ans++;
	while (true)
	{
		int x = R.x;
		int y = R.y;
		int dir = R.dir;

		bool che = false;
		for (int i = 3; i >= 0; i--)
		{
			int ndir = (i + dir) % 4;
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0 && !vi[nx][ny])
			{
				vi[nx][ny] = true;
				che = true;
				R.x = nx;
				R.y = ny;
				R.dir = ndir;
				ans++;
				break;
			}
		}

		if (!che)
		{
			if(dir == 0) R.x += 1;
			else if (dir == 1) R.y -= 1;
			else if (dir == 2) R.x -= 1;
			else if (dir == 3) R.y += 1;

			if (map[R.x][R.y] == 1 || R.x < 0 || R.x >= n || R.y < 0 || R.y >= m) break;
		}
	}
}

int main()
{
	input();
	solve();
	cout << ans << endl;
	return 0;
}