#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int r, c, m, ans;
struct shark
{
	int x;
	int y;
	int s;
	int d;
	int z;
};
shark ar[10201];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<int> map[101][101];

void input()
{
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		ar[i].x = x - 1;
		ar[i].y = y - 1;
		ar[i].s = s;
		ar[i].d = d - 1;
		ar[i].z = z;

		int ro = 0;
		if (ar[i].d == 0 || ar[i].d == 1)
			ro = (r - 1) * 2;
		else if (ar[i].d == 2 || ar[i].d == 3)
			ro = (c - 1) * 2;

		ar[i].s = ar[i].s % ro;
		map[x - 1][y - 1].push(i);
	}
}

void cat(int li)
{
	for (int i = 0; i < r; i++)
	{
		if (!map[i][li].empty())
		{
			int num = map[i][li].front();
			map[i][li].pop();
			ans += ar[num].z;
			break;
		}
	}
}

void mo()
{
	bool vi[10201] = { false, };
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j].empty())
				continue;
			int cnt = map[i][j].size();
			int ct = 0;
			while (true)
			{
				ct++;
				int num = map[i][j].front();
				map[i][j].pop();
				if (!vi[num])
				{
					vi[num] = true;	
					for (int w = 0; w < ar[num].s; w++)
					{
						int nx = ar[num].x + dx[ar[num].d];
						int ny = ar[num].y + dy[ar[num].d];
						if (nx < 0 || nx >= r || ny < 0 || ny >= c)
						{
							if (ar[num].d == 0)
							{
								ar[num].d = 1;
								nx = 1;
							}
							else if (ar[num].d == 1)
							{
								ar[num].d = 0;
								nx = r - 2;
							}
							else if (ar[num].d == 2)
							{
								ar[num].d = 3;
								ny = c - 2;
							}
							else if (ar[num].d == 3)
							{
								ar[num].d = 2;
								ny = 1;
							}
						}

						ar[num].x = nx;
						ar[num].y = ny;

					}
					map[ar[num].x][ar[num].y].push(num);
				}
				else
					map[i][j].push(num);

				if (ct == cnt)
					break;
			}
		}
	}
}

void eat()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j].size() >= 2)
			{
				int num = map[i][j].front();
				shark a = ar[num];
				map[i][j].pop();
				while (!map[i][j].empty())
				{
					int num2 = map[i][j].front();
					shark b = ar[num2];
					map[i][j].pop();

					if (a.z < b.z)
					{
						a = b;
						num = num2;
					}
				}
				map[i][j].push(num);
			}
		}
	}
}

void solve()
{
	for (int i = 0; i < c; i++)
	{
		cat(i);
		mo();
		eat();
	}
}

int main()
{
	input();
	solve();
	cout << ans << endl;
	return 0;
}