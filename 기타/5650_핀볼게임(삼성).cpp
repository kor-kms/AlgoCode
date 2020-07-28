#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int ar[102][102];
int ans, n, cou;
vector<pair<int, int>> h[11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void input() {
	ans = 0;
	memset(ar, 0, sizeof(ar));
	memset(h, 0, sizeof(h));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ar[i][j];
			if (ar[i][j] > 0) {
				h[ar[i][j]].push_back({ i,j });
			}
		}
	}
}

void dfs(int x, int y, int d) {
	int nx = x;
	int ny = y;
	int flag = 0;
	while (true) {
		int num = ar[nx][ny];
		if (num == -1) break;
		if (nx == x && ny == y && flag == 1) break;
		if (num == 0) {
			if (nx > n && d == 0) {
				d = 1;
				nx = nx + dx[d];
				ny = ny + dy[d];
				cou++;
			}
			else if (nx <= 0 && d == 1) {
				d = 0;
				nx = nx + dx[d];
				ny = ny + dy[d];
				cou++;
			}
			else if (ny > n && d == 2) {
				d = 3;
				nx = nx + dx[d];
				ny = ny + dy[d];
				cou++;
			}
			else if (ny <= 0 && d == 3) {
				d = 2;
				nx = nx + dx[d];
				ny = ny + dy[d];
				cou++;
			}
			else {
				nx = nx + dx[d];
				ny = ny + dy[d];
			}
		}

		else {
			if (num >= 6 && num <= 10) {
				int hx, hy;
				if (nx == h[num][0].first && ny == h[num][0].second) {
					hx = h[num][1].first;
					hy = h[num][1].second;
				}
				else {
					hx = h[num][0].first;
					hy = h[num][0].second;
				}
				nx = hx + dx[d];
				ny = hy + dy[d];
			}
			else if (num >= 1 && num <= 5) {
				if (num == 1) {
					cou++;
					if (d == 0) {
						d = 2;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 1) {
						d = 0;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 2) {
						d = 3;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 3) {
						d = 1;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
				}
				else if (num == 2) {
					cou++;
					if (d == 0) {
						d = 1;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 1) {
						d = 2;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 2) {
						d = 3;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 3) {
						d = 0;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
				}
				else if (num == 3) {
					cou++;
					if (d == 0) {
						d = 1;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 1) {
						d = 3;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 2) {
						d = 0;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 3) {
						d = 2;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
				}
				else if (num == 4) {
					cou++;
					if (d == 0) {
						d = 3;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 1) {
						d = 0;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 2) {
						d = 1;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 3) {
						d = 2;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
				}
				else if (num == 5) {
					cou++;
					if (d == 0) {
						d = 1;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 1) {
						d = 0;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 2) {
						d = 3;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
					else if (d == 3) {
						d = 2;
						nx = nx + dx[d];
						ny = ny + dy[d];
					}
				}
			}
		}
		flag = 1;
	}

	ans = max(ans, cou);
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ar[i][j] == 0) {
				for (int w = 0; w < 4; w++) {
					cou = 0;
					dfs(i, j, w);
				}
			}
		}
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