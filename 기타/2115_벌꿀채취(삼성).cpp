#include <iostream>
#include <algorithm>

using namespace std;

int map[10][10];
int visit[10];
int vv[10][10];
int n, m, c;
int re1, re2;
int result;

void input() {
	re1 = 0, re2 = 0, result = 0;
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void dfs(int x, int y, int sum, int ct, int i, int w, int cost) {
	if (c <= sum || w == ct) {
		if (re1 < cost) {
			memset(vv, 0, sizeof(vv));
			for (int q = 0; q < w; q++) {
				vv[x][q] = visit[q];
			}
			re1 = cost;
		}
		return;
	}
	for (int g = i; g < m; g++) {
		if (visit[g] == 0) {
			visit[g] = 1;
			dfs(x, y + 1, sum + map[x][y], ct + 1, g, w, cost + map[x][y] * map[x][y]);
			visit[g] = 0;
		}
	}
}

void dfs2(int x, int y, int sum, int ct, int i, int w, int cost) {
	if (vv[x][y] == 1) return;
	if (c <= sum || w == ct) {
		if (re2 < cost) {
			memset(vv, 0, sizeof(vv));
			for (int q = 0; q < 10; q++) {
				vv[x][q] = visit[q];
			}
			re2 = cost;
		}
		return;
	}
	for (int g = i; g < m; g++) {
		if (visit[g] == 0) {
			visit[g] = 1;
			dfs(x, y + 1, sum + map[x][y], ct + 1, g, w, cost + map[x][y] * map[x][y]);
			visit[g] = 0;
		}
	}
}

void solve() {
	for (int w = 1; w <= m; w++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - w; j++) {
				int cc = 0;
				memset(visit, 0, sizeof(visit));
				dfs(i, j, 0, 0, 0, w, 0);
				memset(visit, 0, sizeof(visit));
				dfs2(i, j, 0, 0, 0, w, 0);
				cc = re1 + re2;
				result = max(result, cc);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << vv[i][j] << " ";
		}cout << endl;
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