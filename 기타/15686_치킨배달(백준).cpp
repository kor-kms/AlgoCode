#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int map[50][50];
int n, m;
int result = 1000000;
struct chi {
	int x;
	int y;
};
chi ch[13];
int chivi[13];
vector<chi> v;

void input() {
	cin >> n >> m;
	int w = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				ch[w].x = i;
				ch[w].y = j;
				w++;
			}
		}
	}
	if (w != 13) {
		ch[w].x = -1;
		ch[w].y = -1;
	}
}

int dis(int a, int b, int c, int d) {
	int res = abs(a - c) + abs(b - d);
	return res;
}

void chidis() {
	int ct2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				int ct = 1000000;
				for (int w = 0; w < v.size(); w++) {
					ct = min(dis(i, j, v[w].x, v[w].y), ct);
				}
				ct2 += ct;
			}
		}
	}
	result = min(result, ct2);
}

void dfs(int w, int e, int g) {
	if (w == m) {
		chidis();
		return;
	}

	for (int i = g; i < 13; i++) {
		if (ch[i].x == -1 || ch[i].y == -1) break;
		if (chivi[i] == 0) {
			chivi[i] = 1;
			v.push_back({ ch[i].x, ch[i].y });
			dfs(w + 1, e + 1, i + 1);
			v.pop_back();
			chivi[i] = 0;
		}
	}
}

int main() {
	input();
	dfs(0, 0, 0);
	cout << result << endl;
	return 0;
}