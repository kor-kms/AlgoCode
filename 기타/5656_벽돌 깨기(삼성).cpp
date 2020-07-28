#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, w, h, t;
int cp[15][12];
int result;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
struct aaa {
	int xp;
	int yp;
	int num;
};
queue<aaa> q;

void input() {
	result = 1000000;
	cin >> n >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> cp[i][j];
		}
	}
}

void copy(int(*a)[12], int(*b)[12]) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void down() {
	for (int i = 0; i < w; i++) {
		bool qq = false;
		for (int j = 0; j < h; j++) {
			if (cp[j][i] != 0) {
				qq = true;
			}
			else if (cp[j][i] == 0 && qq == true) {
				for (int w = 0; w < h; w++) {
					if (cp[j - w] == 0 && cp[j - w - 1] == 0) break;
					else if (j - w - 1 < 0) break;
					else swap(cp[j - w][i], cp[j - w - 1][i]);
				}
			}
		}
	}
}

void bre(int x, int y) {
	int xx = x;
	int yy = y;
	int nnum = cp[x][y];
	q.push({ xx,yy,cp[xx][yy] });

	while (!q.empty()) {
		xx = q.front().xp;
		yy = q.front().yp;
		nnum = q.front().num;
		q.pop();

		for (int i = 0; i < nnum; i++) {
			if (xx + i < 0 || xx + i >= h) break;
			else {
				if(cp[xx + i][yy] > 1 ) q.push({ xx + i,yy,cp[xx + i][yy] });
				cp[xx + i][yy] = 0;
			}
		}

		for (int i = 0; i < nnum; i++) {
			if (xx - i < 0 || xx - i >= h) break;
			else {
				if (cp[xx - i][yy] > 1) q.push({ xx - i,yy,cp[xx - i][yy] });
				cp[xx - i][yy] = 0;
			}
		}

		for (int i = 0; i < nnum; i++) {
			if (yy + i < 0 || yy + i >= w) break;
			else {
				if (cp[xx][yy + i] > 1) q.push({ xx,yy + i,cp[xx][yy + i] });
				cp[xx][yy + i] = 0;
			}
		}

		for (int i = 0; i < nnum; i++) {
			if (yy - i < 0 || yy - i >= w) break;
			else {
				if (cp[xx][yy - i] > 1) q.push({ xx,yy - i,cp[xx][yy - i] });
				cp[xx][yy - i] = 0;
			}
		}
	}

	down();
}

void sum() {
	int ct = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (cp[i][j] != 0) ct++;
		}
	}

	result = min(result, ct);
}

void find(int x) {
	int xx = 0;
	int yy = 0;
	for (int i = 0; i < h; i++) {
		if (cp[i][x] != 0) {
			xx = i;
			yy = x;
			break;
		}
	}

	bre(xx, yy);
}

void dfs(int nn) {
	if (nn == n) {
		sum();
		return;
	}

	int ar[15][12];
	for (int i = 0; i < w; i++) {
		copy(cp, ar);
		find(i);
		dfs(nn + 1);
		copy(ar, cp);
	}
}

int main() {
	cin >> t;
	for (int k = 0; k < t; k++) {
		input();
		dfs(0);
		cout << "#" << k + 1 << " " << result << endl;
	}
	return 0;
}