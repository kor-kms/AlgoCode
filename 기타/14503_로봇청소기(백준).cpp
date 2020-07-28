#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int map[50][50];
int result;
struct rr {
	int r;
	int c;
	int d;
};
rr ro;

void input() {
	cin >> n >> m;
	cin >> ro.r >> ro.c >> ro.d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void solve(int x, int y, int d) {
	if (map[x][y] == 1) return;
	if (map[x][y] == 0) {
		map[x][y] = -1;
		result++;
	}

	int di = d - 1;
	if (di < 0) di = 3;

	for (int w = 0; w < 4; w++) {
		if (di < 0) di = 3;
		int nx = x + dx[di];
		int ny = y + dy[di];

		if (map[nx][ny] == 0) {
			solve(nx, ny, di);
			return;
		}
		else di--;
	}

	int back;
	if (d == 0) back = 2;
	else if (d == 1) back = 3;
	else if (d == 2) back = 0;
	else if (d == 3) back = 1;

	solve(x + dx[back], y + dy[back], d);
}

int main() {
	input();
	solve(ro.r, ro.c, ro.d);
	cout << result << endl;
	return 0;
}