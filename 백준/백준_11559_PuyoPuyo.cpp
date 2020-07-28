#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

struct cmp
{
	bool operator() (pair<int, int> a, pair<int, int> b)
	{
		if (a.first < b.first)
			return true;
		else if (a.first == b.first)
		{
			if (a.second > b.second)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
char ar[12][6];
int ans;
vector<char> v[6];
bool flag = false;
set<pair<int, int>, cmp> res;

void input()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
			cin >> ar[i][j];
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 11; j >= 0; j--)
			v[i].push_back(ar[j][i]);
	}
}

void break_puyo(char c, int  i, int j)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> bre_pu;
	bool vi[6][12] = { false, };
	q.push(make_pair(i, j));
	vi[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		bre_pu.push_back(make_pair(x, y));

		for (int w = 0; w < 4; w++)
		{
			int nx = x + dx[w];
			int ny = y + dy[w];
			if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12)
				continue;
			if (!vi[nx][ny] && v[nx][ny] == c)
			{
				vi[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}

	if (bre_pu.size() >= 4)
	{
		for (int w = 0; w < bre_pu.size(); w++)
			res.insert(bre_pu[w]);
		flag = true;
	}
}

void solve()
{
	while (true)
	{
		if (res.size() > 0)
			res.clear();
		flag = false;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (v[i][j] == '.')
					break;
				break_puyo(v[i][j], i, j);
			}
		}
		if (!flag)
			break;

		ans++;
		for (set<pair<int, int>, cmp>::iterator iter = res.begin(); iter != res.end(); iter++)
		{
			pair<int, int> s = *iter;
			int x = s.first;
			int y = s.second;
			v[x].erase(v[x].begin() + y);
			v[x].push_back('.');
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