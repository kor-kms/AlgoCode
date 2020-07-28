#include <iostream>
#include <queue>

using namespace std;

struct aaa {
	int x;
	int st;
	int ti;
};
aaa map[400][400];
int n, m, k, ans;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void input()
{
	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			map[i][j].x = 0;
			map[i][j].st = 0;
			map[i][j].ti = 0;
		}
	}
	ans = 0;

	cin >> n >> m >> k;
	for (int i = 200; i < n + 200; i++)
	{
		for (int j = 200; j < m + 200; j++)
		{
			cin >> map[i][j].x;
			if(map[i][j].x != 0)
				map[i][j].st = 1;
		}
	}
}

void solve()
{//1ºñ 2È° 3Á×
	for (int t = 0; t < k; t++)
	{
		for (int i = 0; i < 400; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				if (map[i][j].st == 0 || map[i][j].st == 3)
					continue;

				map[i][j].ti++;

				if (map[i][j].x == map[i][j].ti && map[i][j].st == 1)
				{//È°¼ºÀ¸·Î
					map[i][j].ti = 0;
					map[i][j].st = 2;
				}

				else if (map[i][j].st == 2 && map[i][j].ti == 1)
				{//»Ñ¸®±â
					for (int w = 0; w < 4; w++)
					{
						int nx = i + dx[w];
						int ny = j + dy[w];
						if (nx < 0 || nx >= 400 || ny < 0 || ny >= 400)
							continue;
						if (map[nx][ny].st == 0)
						{
							if (map[nx][ny].x < map[i][j].x)
							{
								q.push({ nx,ny });
								map[nx][ny].x = map[i][j].x;
							}
						}
					}

					if (map[i][j].x == 1)//1Á×ÀÌ±â
						map[i][j].st = 3;
				}

				else if (map[i][j].st == 2 && map[i][j].ti == map[i][j].x)//Á×À½
					map[i][j].st = 3;
			}
		}

		while (!q.empty())
		{
			int xx = q.front().first;
			int yy = q.front().second;
			q.pop();

			map[xx][yy].st = 1;
		}

		/*cout << endl << endl;
		for (int i = 164; i < 185; i++)
		{
			for (int j = 164; j < 185; j++)
			{
				cout << map[i][j].x << " ";
			}cout << endl;
		}cout << endl;*/

		/*for (int i = 164; i < 185; i++)
		{
			for (int j = 164; j < 185; j++)
			{
				cout << map[i][j].st << " ";
			}cout << endl;
		}cout << endl;*/
	}

	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			if (map[i][j].st == 1 || map[i][j].st == 2)
				ans++;
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
		solve();
		cout << "#" << k + 1 << " " << ans << endl;
	}
	return 0;
}