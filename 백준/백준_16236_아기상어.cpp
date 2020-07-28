#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct shark
{
	int x;
	int y;
	int z;
	int cnt;
	int ans;
};
shark s;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<pair<int, int>, pair<int,int>>> v;
int n, ans;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int z;
			cin >> z;
			if (z != 0)
			{
				if (z == 9)
				{
					s.x = i;
					s.y = j;
					s.z = 2;
					s.cnt = 0;
				}
				else
					v.push_back({ {i,j},{z,0} });
			}
		}
	}
}

bool cmp(pair<pair<int, int>, pair<int,int>> a, pair<pair<int, int>, pair<int,int>> b)
{
	if (a.second.second < b.second.second)
		return true;
	else if (a.second.second == b.second.second)
	{
		if (a.first.first < b.first.first)
			return true;
		else if (a.first.first == b.first.first)
		{
			if (a.first.second < b.first.second)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

void solve()
{
	while (true)
	{
		bool flag = false;
		for (int i = 0; i < v.size(); i++)
		{
			int d = abs(s.x - v[i].first.first) + abs(s.y - v[i].first.second);
			v[i].second.second = d;
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].second.first >= s.z)
				continue;
			s.cnt++;
			if (s.cnt == s.z)
			{
				s.z++;
				s.cnt = 0;
			}
			s.ans += abs(s.x - v[i].first.first) + abs(s.y - v[i].first.second);
			s.x = v[i].first.first;
			s.y = v[i].first.second;
			v.erase(v.begin() + i);
			flag = true;
			break;
		}
		if (!flag)
			break;
	}
}

int main()
{
	input();
	solve();
	cout << s.ans << endl;
	return 0;
}