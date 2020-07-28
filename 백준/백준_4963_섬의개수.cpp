#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int ar[51][51];
int vi[51][51];
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };
int n, m, ct2;
bool flag = false;

void input() {
	flag = false;
	memset(ar, 0, sizeof(ar));
	memset(vi, 0, sizeof(vi));
	ct2 = 0;
	cin >> n >> m;
	if (n == 0 && m == 0) {
		flag = true;
		return;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cin >> ar[i][j];
	}
}

void bfs(int i, int j) {
	ct2++;
	queue<pair<int, int>> q;
	q.push({ i,j });
	vi[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int w = 0; w < 8; w++) {
			int nx = x + dx[w];
			int ny = y + dy[w];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (ar[nx][ny] == 1 && vi[nx][ny] == 0) {
				vi[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void solve() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (ar[i][j] == 1 && vi[i][j] == 0) bfs(i, j);
		}
	}
}

int main() {
	for (;;) {
		input();
		if (flag) break;
		solve();
		cout << ct2 << endl;
	}
	return 0;
}