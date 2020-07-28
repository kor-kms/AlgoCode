#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

struct aaa {
	int mo;
	vector<int> v;
};
int n, m, k;
aaa map[10][10];
int mmap[10][10];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int result;

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mmap[i][j];
			map[i][j].mo = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int o, p, l;
		cin >> o >> p >> l;
		map[o - 1][p - 1].v.push_back(l);
	}
}


void solve() {
	for (int t = 0; t < k; t++) {

		/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		sort(map[i][j].v.begin(), map[i][j].v.end(), greater<int>());
		}
		}*/

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int ar[1000] = { 0, };
				int aar[1000] = { 0, };
				int si = map[i][j].v.size();
				int ww = 0;
				int www = 0;
				if (si == 0) continue;
				for (int q = 0; q < si; q++) {
					int tr = map[i][j].v.back();
					map[i][j].v.pop_back();
					if (map[i][j].mo - tr >= 0) {
						map[i][j].mo -= tr;
						ar[ww] = tr + 1;
						ww++;
					}
					else {
						aar[www] = tr / 2;
						www++;
					}
				}
				int temp = ww - 1;
				for (int q = 0; q < ww; q++) {
					map[i][j].v.push_back(ar[temp]);
					temp--;
				}
				int ttemp = www - 1;
				for (int q = 0; q < www; q++) {
					map[i][j].mo += aar[ttemp];
					ttemp--;
				}
			}
		}

		/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		sort(map[i][j].v.begin(), map[i][j].v.end(), greater<int>());
		}
		}*/

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int si = map[i][j].v.size();
				for (int q = 0; q < si; q++) {
					if (map[i][j].v[q] % 5 == 0) {
						for (int w = 0; w < 8; w++) {
							int nx = i + dx[w];
							int ny = j + dy[w];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							map[nx][ny].v.push_back(1);
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j].mo += mmap[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result += map[i][j].v.size();
		}
	}
}

int main() {
	input();
	solve();
	cout << result << endl;
	return 0;
}