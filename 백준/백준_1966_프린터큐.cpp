#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int,int>> q;
int n, m, ans;

void input() {
	while (!q.empty()) q.pop();
	ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push({ a,i });
	}
}

void solve() {
	int ct = 0;
	int fl = 0;
	while (true) {
		int qq = q.size();
		int mx = 0;

		for (int i = 0; i < qq; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			mx = max(x, mx);
			q.push({ x,y });
		}
		for (int i = 0; i < qq; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == mx) {
				ct++;
				fl = y;
				break;
			}
			else q.push({ x,y });
		}

		if (m == fl) {
			ans = ct;
			break;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		input();
		solve();
		cout<<ans<<endl;
	}
	return 0;
}