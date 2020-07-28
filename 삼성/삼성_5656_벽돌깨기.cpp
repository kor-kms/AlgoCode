#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, w, h, ans;
int ar[16][13];
int cp[16][13];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<int> v;

void input()
{
	memset(ar, 0, sizeof(ar));
	memset(cp, 0, sizeof(cp));
	ans = 987654321;
	v.clear();
	cin >> n >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> ar[i][j];
			cp[i][j] = ar[i][j];
		}
	}
}

void down()
{
	for (int i = w - 1; i >= 0; i--)
	{
		for (int j = h - 1; j >= 0; j--)
		{
			if (ar[j][i] == 0)
			{
				for (int s = j - 1; s >= 0; s--)
				{
					if (ar[s][i] != 0)
					{
						swap(ar[s][i], ar[j][i]);
						break;
					}
				}
			}
		}
	}
}

void bre(int x, int i, int j)
{
	if (x == 1)
	{
		ar[i][j] = 0;
		return;
	}
	for (int xct = 1; xct <= x; xct++) {
		for (int s = 0; s < 4; s++)
		{
			int nx = i + (dx[s] * xct);
			int ny = j + (dy[s] * xct);
			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;
			if (ar[nx][ny] != 0)
				bre(ar[nx][ny], nx, ny);
		}
	}
}

void solve()
{
	for (int t = 0; t < v.size(); t++)
	{
		int x = v[t];
		for (int i = 0; i < h; i++)
		{
			if (ar[i][x] != 0)
			{
				bre(ar[i][x], i, x);
				break;
			}
		}
		down();
	}
}

void pro(int ct)
{
	if (ct == n)
	{
		solve();
		int ct = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (ar[i][j] != 0)
					ct++;
				ar[i][j] = cp[i][j];
			}
		}
		ans = min(ans, ct);
		return;
	}

	for (int j = 0; j < w; j++)
	{
		v.push_back(j);
		pro(ct + 1);
		v.pop_back();
	}
}

int main()
{
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		input();
		pro(0);
		cout << "#" << k + 1 << " " << ans << endl;
	}
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//struct cmp
//{
//	bool operator() (pair<int, int> a, pair<int, int> b)
//	{
//		if (a.first == b.first)
//		{
//			if (a.second < b.second)
//				return true;
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//};
//
//vector<int> v[12];
//int n, w, h, ans;
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//
//void input()
//{
//	ans = 987654321;
//	cin >> n >> w >> h;
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++)
//		{
//			int a;
//			cin >> a;
//			v[j].push_back(a);
//		}
//	}
//}
//
//void bre(int xx)
//{
//	bool vi[15][12] = { false, };
//	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
//	queue<pair<int, int>> q;
//	for (int i = 0; i < h; i++)
//	{
//		if (v[xx][i] != 0)
//		{
//			q.push(make_pair(xx, i));
//			break;
//		}
//	}
//
//	while (!q.empty())
//	{
//		int x = q.front().first;
//		int y = q.front().second;
//		q.pop();
//
//		vi[x][y] = true;
//		pq.push(make_pair(x, y));
//
//		if (v[x][y] == 1)
//			continue;
//		
//		else
//		{
//			for (int j = 1; j < v[x][y]; j++)
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					int nx = x + dx[i] * j;
//					int ny = y + dy[i] * j;
//					if (nx < 0 || nx >= h || ny < 0 || ny >= w)
//						continue;
//					if (!vi[nx][ny] && v[nx][ny] != 0)
//					{
//						vi[nx][ny] = true;
//						q.push(make_pair(nx, ny));
//						pq.push(make_pair(nx, ny));
//					}
//				}
//			}
//		}
//	}
//
//	while (!pq.empty())
//	{
//		int x = pq.top().first;
//		int y = pq.top().second;
//		pq.pop();
//
//		v[x].erase(v[x].begin() + y);
//		v[x].insert(v[x].begin(), 0);
//	}
//}
//
//void pro(int ct)
//{
//	if (ct == n)
//	{
//		int cnt = 0;
//		for (int i = 0; i < h; i++)
//		{
//			for (int j = 0; j < w; j++)
//			{
//				if (v[i][j] != 0)
//					cnt++;
//			}
//		}
//		ans = min(ans, cnt);
//		return;
//	}
//
//	vector<int> cp[12];
//	for (int i = 0; i < w; i++)
//	{
//		for (int i = 0; i < w; i++)
//			cp[i] = v[i];
//		bre(i);
//
//		cout << endl;
//		cout << "µé¾î°¨" << endl;
//		for (int i = 0; i < h; i++)
//		{
//			for (int j = 0; j < w; j++)
//			{
//				cout << v[j][i] << " ";
//			}cout << endl;
//		}
//		//
//		pro(ct + 1);
//		//
//		for (int i = 0; i < w; i++)
//			v[i] = cp[i];
//		cout << endl;
//		cout << "³ª¿È" << endl;
//		for (int i = 0; i < h; i++)
//		{
//			for (int j = 0; j < w; j++)
//			{
//				cout << v[j][i] << " ";
//			}cout << endl;
//		}
//	}
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	for (int k = 0; k < t; k++)
//	{
//		input();
//		pro(0);
//		cout << "#" << k + 1 << " " << ans << endl;
//	}
//	
//	return 0;
//}