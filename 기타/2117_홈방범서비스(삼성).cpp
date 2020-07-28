#include <iostream>
#include <algorithm>

using namespace std;

int map[20][20];
int n, m, result;
int k, ct, home, cost;

void input() {
	cin >> n >> m;
	home = 0;
	result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) home++;
		}
	}
	cost = home * m;
}

void se(int x, int y) {
	for (int j = 0; j < k; j++) {
		for (int i = y - k + 1 + j; i <= y + k - 1 - j; i++) {
			if (i < 0 || i >= n || (x + j) >= n) continue;
			if (map[x + j][i] == 1) ct++;
		}
	}
	for (int j = 1; j < k; j++) {
		for (int i = y - k + 1 + j; i <= y + k - 1 - j; i++) {
			if (i < 0 || i >= n || (x - j) < 0) continue;
			if (map[x - j][i] == 1) ct++;
		}
	}
}

void solve() {
	k = 2;
	while (true) {
		if (k*k + (k - 1)*(k - 1) >= cost) break;
		k++;
	}
	while (true) {
		if (k < 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ct = 0;
				se(i, j);
				if (k*k + (k - 1)*(k - 1) <= ct*m) result = max(result, ct);
			}
		}
		k--;
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		input();
		solve();
		cout << "#" << k + 1 << " " << result << endl;
	}
	return 0;
}