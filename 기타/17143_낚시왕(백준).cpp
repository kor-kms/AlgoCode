#include <iostream>
#include <algorithm>

using namespace std;

struct shark {
	int x;
	int y;
	int v;
	int d;//1위 2아래 3오른쪽 4왼쪾
	int z;
};
shark s[101];
int r, c, m, k = 1;
int map[101][101];
int result;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void input() {
	cin >> r >> c >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> s[i].x >> s[i].y >> s[i].v >> s[i].d >> s[i].z;
			map[s[i].x][s[i].y] = i;
		}
	}
}

void pick() {
	for (int i = 0; i <= r; i++) {
		if (map[i][k] != 0) {
			result += s[map[i][k]].z;
			s[map[i][k]].z = 0;
			break;
		}
	}
	k++;
}

void move() {
	for (int i = 1; i <= m; i++) {
		int xx = s[i].x + dx[s[i].d - 1] * s[i].z;
		int yy = s[i].y + dy[s[i].d - 1] * s[i].z;
		int size = s[i].v;
		while (true) {
			if (size < 0) break;

			size--;
		}
	}
}

void solve() {
	pick();
}

int main() {
	input();
	solve();
	return 0;
}