#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
string ans;
queue<pair<int, string>> q;


void solve() {
	bool vi[10001] = { false, };
	q.push({ n,"" });
	vi[n] = true;

	while (!q.empty()) {
		int x = q.front().first;
		string f = q.front().second;
		q.pop();

		if (x == m) {
			ans = f;
			break;
		}

		int x1 = x * 2;
		if (x1 >= 10000) x1 = x1 % 10000;
		if (!vi[x1]) {
			vi[x1] = true;
			q.push({ x1, f + 'D' });
		}

		int x2 = x - 1;
		if (x == 0) x2 = 9999;
		if (!vi[x2]) {
			vi[x2] = true;
			q.push({ x2, f + 'S' });
		}

		int x3 = (x % 1000) * 10 + x / 1000;
		if (!vi[x3]) {
			vi[x3] = true;
			q.push({ x3, f + 'L' });
		}

		int x4 = (x % 10) * 1000 + (x / 10);
		if (!vi[x4]) {
			vi[x4] = true;
			q.push({ x4, f + 'R' });
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		if (!q.empty()) while (!q.empty()) q.pop();
		ans = "";
		cin >> n >> m;
		solve();
		cout << ans << endl;
	}
	return 0;
}