//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int ans, n, m;
//int vi[100001];
//queue<int> q;
//int dx[] = { -1,1 };
//
//void solve() {
//	q.push(n);
//	vi[n] = 1;
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//
//		if (x == m) {
//			ans = vi[x];
//			break;
//		}
//
//		for (int w = 0; w < 3; w++) {
//			int nx = 0;
//			if (w != 2) nx = x + dx[w];
//			else nx = x * 2;
//			if (nx < 0 || nx >100000) continue;
//			if (vi[nx] == 0) {
//				vi[nx] = vi[x] + 1;
//				q.push(nx);
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	solve();
//	cout << ans - 1<< endl;
//	return 0;
//}
#include <iostream>
#include <queue>

using namespace std;

int n, m;
bool vi[100001];
queue<pair<int, int>> q;

void solve()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int t = q.front().second;
		q.pop();

		if (x == m)
		{
			cout << t << endl;
			break;
		}

		for (int w = 0; w < 3; w++)
		{
			if (w == 0)
			{
				if (!vi[x + 1] && x + 1 <= 100000)
				{
					vi[x + 1] = true;
					q.push({ x + 1,t + 1 });
				}
			}
			else if (w == 1)
			{
				if (!vi[x - 1] && x - 1 >= 0)
				{
					vi[x - 1] = true;
					q.push({ x - 1,t + 1 });
				}
			}
			else if (w == 2)
			{
				if (!vi[x * 2] && x * 2 <= 100000)
				{
					vi[x * 2] = true;
					q.push({ x * 2,t + 1 });
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	q.push({ n,0 });
	vi[n] = true;
	solve();
	return 0;
}