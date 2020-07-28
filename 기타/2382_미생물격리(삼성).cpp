#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int map[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m, k, ans;
struct aaa {
	int x;
	int y;
	int c;
	int z;
};
aaa mm[1000];

void input() {
	memset(map, 0, sizeof(map));
	ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> mm[i].x >> mm[i].y >> mm[i].c >> mm[i].z;
		mm[i].z--;
		map[mm[i].x][mm[i].y]++;
	}
}

bool cmp(aaa a, aaa b) {
	return a.c > b.c;
}

void solve() {
	for (int ti = 0; ti < m; ti++) {
		for (int i = 0; i < k; i++) {
			if (mm[i].x == -3) continue;
			int nx = mm[i].x + dx[mm[i].z];
			int ny = mm[i].y + dy[mm[i].z];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (nx == n - 1 || ny == n - 1 || nx == 0 || ny == 0) {
				if (mm[i].z % 2 == 0) mm[i].z++;
				else mm[i].z--;
				mm[i].c = mm[i].c / 2;
			}
			map[nx][ny]++;
			map[mm[i].x][mm[i].y]--;
			mm[i].x = nx;
			mm[i].y = ny;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > 1) {
					aaa bb[100];
					int cc = 0;
					int che = 0;
					vector<int> v;
					for (int q = 0; q < k; q++) {
						if (mm[q].x == i && mm[q].y == j) {
							bb[cc] = mm[q];
							v.push_back(q);
							cc++;
						}
					}

					sort(bb, bb + cc, cmp);

					for (int q = 0; q < v.size(); q++) {
						if (mm[v[q]].c == bb[0].c) {
							che = v[q];
							break;
						}
					}

					int ssum = 0;
					for (int q = 0; q < v.size(); q++) {
						if (q == che) continue;
						ssum += mm[v[q]].c;
						mm[v[q]].x = -3;
						mm[v[q]].y = -3;
						mm[v[q]].c = 0;
						mm[v[q]].z = 0;
					}
					mm[che].c += ssum;
				}
			}
		}

	}

	for (int q = 0; q < k; q++) {
		ans += mm[q].c;
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		input();
		solve();
		cout << "#" << k + 1 << " " << ans << endl;
	}
	return 0;
}