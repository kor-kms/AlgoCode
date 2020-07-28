#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int ar[16][16];
int vi[16][16];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> q;
bool qq = false;
int t, g, h;

void input() {
	memset(vi, 0, sizeof(vi));
	qq = false;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			scanf("%1d", &ar[i][j]);
			if (ar[i][j] == 2) {
				g = i;
				h = j;
			}
		}
	}
}

void bfs() {
	int x = g;
	int y = h;
	q.push(pair<int, int>(x, y));
	vi[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int xx = x + dx[w];
			int yy = y + dy[w];
			if (vi[xx][yy] == 0 && ar[xx][yy] == 0 && xx >= 0 && xx < 16 && yy >= 0 && yy < 16) {
				vi[xx][yy] = 1;
				q.push(pair<int, int>(xx, yy));
			}
			else if (ar[xx][yy] == 3) {
				qq = true;
				break;
			}
		}
	}
}

int main() {
	for (int k = 0; k < 10; k++) {
		cin >> t;
		input();
		bfs();
		if (qq) cout << "#" << t << " " << 1 << endl;
		else cout << "#" << t << " " << 0 << endl;
	}
	return 0;
}