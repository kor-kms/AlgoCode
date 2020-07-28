#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[12][12];
int visit[12][12];
int vic[12];
int cc;
pair<int, int> core[12];
int n, result = 1000000, rr;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void input() {
	cin >> n;
	result = 1000000;
	cc = 0;
	rr = 0;
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	memset(core, 0, sizeof(core));
	memset(vic, 0, sizeof(vic));
	int q = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				visit[i][j] = 1;
				visit[i][j] = 2;
				if (i > 0 && i < n - 1 && j > 0 && j < n - 1) {
					core[q] = { i,j };	
					q++;
					cc++;
				}
			}
		}
	}
}

void solve(int x, int y, int c, int vc) {
	if (c == cc) {
		if (vc < rr) return;
		int ct = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 1) ct++;
			}
		}
		if (vc >= rr) {
			rr = vc;
			result = min(result, ct);
		}
		return;
	}

	vc++;
	for (int w = 0; w < 4; w++) {
		bool ch = true;
		int q = 1;

		while (true) {
			int nx = x + dx[w] * q;
			int ny = y + dy[w] * q;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
			if (map[nx][ny] == 1 || visit[nx][ny] == 1) {
				ch = false;
				break;
			}
			q++;
		}

		if (ch == true) {
			q = 1;
			while (true) {
				int nx = x + dx[w] * q;
				int ny = y + dy[w] * q;

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
				visit[nx][ny] = 1;
				q++;
			}
	
			solve(core[c + 1].first, core[c + 1].second, c + 1, vc);

			q = 1;
			while (true) {
				int nx = x + dx[w] * q;
				int ny = y + dy[w] * q;

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
				visit[nx][ny] = 0;
				q++;
			}
		}
	}
	solve(core[c + 1].first, core[c + 1].second, c + 1, vc - 1);
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		input();
		solve(core[0].first, core[0].second, 0, 0);
		cout << "#" << k + 1 << " " << result << endl;
	}
	return 0;
}