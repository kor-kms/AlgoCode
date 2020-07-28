#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int map[100][100];
int visit[100][100];
int n, result, h;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> q;
int remax, mx, mi = 100;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			mx = max(mx, map[i][j]);
			mi = min(mi, map[i][j]);
		}
	}
}

void solve(int i, int j) {
	int x = i;
	int y = j;
	q.push({ i,j });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int nx = x + dx[w];
			int ny = y + dy[w];

			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny] > h && visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void check() {
	for (h = mi - 1; h <= mx; h++) {
		memset(visit, 0, sizeof(visit));
		result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > h && visit[i][j] == 0) {
					solve(i, j);
					visit[i][j] = 1;
					result++;
				}
			}
		}
		remax = max(remax, result);
	}
}

int main() {
	input();
	check();
	cout << remax << endl;
	return 0;
}