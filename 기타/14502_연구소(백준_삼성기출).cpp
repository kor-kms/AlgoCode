#include <iostream>
#include <algorithm>

using namespace std;

int ar[8][8];
int re[8][8];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int result;
struct virus {
	int q;
	int w;
};

virus v[10];

void spread(int a, int x, int y) {
	if (v[a].q != -1 && v[a].w != -1) {
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && re[xx][yy] == 0) {
				re[xx][yy] = 2;
				spread(a, xx, yy);
			}
		}
	}
}

void block(int a, int x, int y) {
	if (a == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				re[i][j] = ar[i][j];
			}
		}

		for (int i = 0; i < 10; i++) spread(i, v[i].q, v[i].w);

		int ct = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (re[i][j] == 0) ct++;
			}
		}
		result = max(result, ct);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ar[i][j] == 0) {
				ar[i][j] = 1;
				if(j == 6) block(a + 1, i + 1, 0);
				else block(a + 1, i, j + 1);
				ar[i][j] = 0;
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < 10; i++) {
		v[i].q = -1;
		v[i].w = -1;
	}
	int ww = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
			if (ar[i][j] == 2) {
				v[ww].q = i;
				v[ww].w = j;
				ww++;
			}
		}
	}
	block(0, 0, 0);
	cout << result << endl;
	return 0;
}