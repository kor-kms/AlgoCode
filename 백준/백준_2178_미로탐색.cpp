#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int ar[101][101];
int vi[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, ans = 10000000;
queue<pair<int, int>> q;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%1d", &ar[i][j]);
	}
}

void bfs() {
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			ans = vi[x][y];
			break;
		}

		for (int w = 0; w < 4; w++) {
			int nx = x + dx[w];
			int ny = y + dy[w];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vi[nx][ny] == 0 && ar[nx][ny] == 1) {
				vi[nx][ny] = vi[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

void dfs(int x, int y, int su) {
	if (x == n - 1 && y == m - 1) {
		ans = min(su, ans);
		return;
	}

	for (int w = 0; w < 4; w++) {
		int nx = x + dx[w];
		int ny = y + dy[w];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (vi[nx][ny] == 0 && ar[nx][ny] == 1) {
			vi[nx][ny] = vi[x][y] + 1;
			dfs(nx, ny, vi[nx][ny]);
			vi[nx][ny] = 0;
		}
	}
}

int main() {
	input();
	bfs();
	cout << ans + 1 << endl;

	vi[0][0] = 1;
	dfs(0, 0, 1);
	cout << ans << endl;
	return 0;
}