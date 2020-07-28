#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ar[8][8];
int n, m, ans = 1000000;
int visit[8][4];
int cp[8][8];

struct aaa {
	int a;
	int b;
	int c;
	int d;
};
vector<aaa> v;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
			cp[i][j] = ar[i][j];
			if (ar[i][j] > 0 && ar[i][j] < 6) {
				if (ar[i][j] == 2) {
					v.push_back({ i,j, ar[i][j], 2 });
				}
				else if (ar[i][j] == 5) {
					v.push_back({ i,j, ar[i][j], 1 });
				}
				else {
					v.push_back({ i,j, ar[i][j], 4 });
				}
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cp[i][j] = ar[i][j];
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].d; j++) {
			if (visit[i][j] == 1) {
				if (v[i].c == 1) {
					if (j == 0) {
						for (int q = 1; q < m; q++) {
							if (v[i].b + q >= m || cp[v[i].a][v[i].b + q] == 6) break;
							if (cp[v[i].a][v[i].b + q] > 0 && cp[v[i].a][v[i].b + q] < 6) continue;
							cp[v[i].a][v[i].b + q] = -3;
						}
					}
					else if (j == 1) {
						for (int q = 1; q < n; q++) {
							if (v[i].a + q >= n || cp[v[i].a + q][v[i].b] == 6) break;
							if (cp[v[i].a + q][v[i].b] > 0 && cp[v[i].a + q][v[i].b] < 6) continue;
							cp[v[i].a + q][v[i].b] = -3;
						}
					}
					else if (j == 2) {
						for (int q = 1; q < m; q++) {
							if (v[i].b - q < 0 || cp[v[i].a][v[i].b - q] == 6) break;
							if (cp[v[i].a][v[i].b - q] > 0 && cp[v[i].a][v[i].b - q] < 6) continue;
							cp[v[i].a][v[i].b - q] = -3;
						}
					}
					else if (j == 3) {
						for (int q = 1; q < n; q++) {
							if (v[i].a - q < 0 || cp[v[i].a - q][v[i].b] == 6) break;
							if (cp[v[i].a - q][v[i].b] > 0 && cp[v[i].a - q][v[i].b] < 6) continue;
							cp[v[i].a - q][v[i].b] = -3;
						}
					}
				}

				else if (v[i].c == 2) {
					if (j == 0) {
						for (int q = 1; q < m; q++) {
							if (v[i].b + q >= m || cp[v[i].a][v[i].b + q] == 6) break;
							if (cp[v[i].a][v[i].b + q] > 0 && cp[v[i].a][v[i].b + q] < 6) continue;
							cp[v[i].a][v[i].b + q] = -3;
						}
						for (int q = 1; q < m; q++) {
							if (v[i].b - q < 0 || cp[v[i].a][v[i].b - q] == 6) break;
							if (cp[v[i].a][v[i].b - q] > 0 && cp[v[i].a][v[i].b - q] < 6) continue;
							cp[v[i].a][v[i].b - q] = -3;
						}
					}
					else if (j == 1) {
						for (int q = 1; q < n; q++) {
							if (v[i].a + q >= n || cp[v[i].a + q][v[i].b] == 6) break;
							if (cp[v[i].a + q][v[i].b] > 0 && cp[v[i].a + q][v[i].b] < 6) continue;
							cp[v[i].a + q][v[i].b] = -3;
						}
						for (int q = 1; q < n; q++) {
							if (v[i].a - q < 0 || cp[v[i].a - q][v[i].b] == 6) break;
							if (cp[v[i].a - q][v[i].b] > 0 && cp[v[i].a - q][v[i].b] < 6) continue;
							cp[v[i].a - q][v[i].b] = -3;
						}
					}
				}

				else if (v[i].c == 3) {
					if (j == 0) {
						for (int q = 1; q < m; q++) {
							if (v[i].b + q >= m || cp[v[i].a][v[i].b + q] == 6) break;
							if (cp[v[i].a][v[i].b + q] > 0 && cp[v[i].a][v[i].b + q] < 6) continue;
							cp[v[i].a][v[i].b + q] = -3;
						}
						for (int q = 1; q < n; q++) {
							if (v[i].a - q < 0 || cp[v[i].a - q][v[i].b] == 6) break;
							if (cp[v[i].a - q][v[i].b] > 0 && cp[v[i].a - q][v[i].b] < 6) continue;
							cp[v[i].a - q][v[i].b] = -3;
						}
					}
					else if (j == 1) {
						for (int q = 1; q < m; q++) {
							if (v[i].b + q >= m || cp[v[i].a][v[i].b + q] == 6) break;
							if (cp[v[i].a][v[i].b + q] > 0 && cp[v[i].a][v[i].b + q] < 6) continue;
							cp[v[i].a][v[i].b + q] = -3;
						}
						for (int q = 1; q < n; q++) {
							if (v[i].a + q >= n || cp[v[i].a + q][v[i].b] == 6) break;
							if (cp[v[i].a + q][v[i].b] > 0 && cp[v[i].a + q][v[i].b] < 6) continue;
							cp[v[i].a + q][v[i].b] = -3;
						}
					}
					else if (j == 2) {
						for (int q = 1; q < n; q++) {
							if (v[i].a + q >= n || cp[v[i].a + q][v[i].b] == 6) break;
							if (cp[v[i].a + q][v[i].b] > 0 && cp[v[i].a + q][v[i].b] < 6) continue;
							cp[v[i].a + q][v[i].b] = -3;
						}
						for (int q = 1; q < m; q++) {
							if (v[i].b - q < 0 || cp[v[i].a][v[i].b - q] == 6) break;
							if (cp[v[i].a][v[i].b - q] > 0 && cp[v[i].a][v[i].b - q] < 6) continue;
							cp[v[i].a][v[i].b - q] = -3;
						}
					}
					else if (j == 3) {
						for (int q = 1; q < n; q++) {
							if (v[i].a - q < 0 || cp[v[i].a - q][v[i].b] == 6) break;
							if (cp[v[i].a - q][v[i].b] > 0 && cp[v[i].a - q][v[i].b] < 6) continue;
							cp[v[i].a - q][v[i].b] = -3;
						}
						for (int q = 1; q < m; q++) {
							if (v[i].b - q < 0 || cp[v[i].a][v[i].b - q] == 6) break;
							if (cp[v[i].a][v[i].b - q] > 0 && cp[v[i].a][v[i].b - q] < 6) continue;
							cp[v[i].a][v[i].b - q] = -3;
						}
					}
				}

				else if (v[i].c == 4) {
					if (j == 0) {
						for (int q = 1; q < m; q++) {
							if (v[i].b + q >= m || cp[v[i].a][v[i].b + q] == 6) break;
							if (cp[v[i].a][v[i].b + q] > 0 && cp[v[i].a][v[i].b + q] < 6) continue;
							cp[v[i].a][v[i].b + q] = -3;
						}
						for (int q = 1; q < m; q++) {
							if (v[i].b - q < 0 || cp[v[i].a][v[i].b - q] == 6) break;
							if (cp[v[i].a][v[i].b - q] > 0 && cp[v[i].a][v[i].b - q] < 6) continue;
							cp[v[i].a][v[i].b - q] = -3;
						}
						for (int q = 1; q < n; q++) {
							if (v[i].a - q < 0 || cp[v[i].a - q][v[i].b] == 6) break;
							if (cp[v[i].a - q][v[i].b] > 0 && cp[v[i].a - q][v[i].b] < 6) continue;
							cp[v[i].a - q][v[i].b] = -3;
						}
					}
					else if (j == 1) {
						for (int q = 1; q < m; q++) {
							if (v[i].b + q >= m || cp[v[i].a][v[i].b + q] == 6) break;
							if (cp[v[i].a][v[i].b + q] > 0 && cp[v[i].a][v[i].b + q] < 6) continue;
							cp[v[i].a][v[i].b + q] = -3;
						}
						for (int q = 1; q < n; q++) {
							if (v[i].a + q >= n || cp[v[i].a + q][v[i].b] == 6) break;
							if (cp[v[i].a + q][v[i].b] > 0 && cp[v[i].a + q][v[i].b] < 6) continue;
							cp[v[i].a + q][v[i].b] = -3;
						}
						for (int q = 1; q < n; q++) {
							if (v[i].a - q < 0 || cp[v[i].a - q][v[i].b] == 6) break;
							if (cp[v[i].a - q][v[i].b] > 0 && cp[v[i].a - q][v[i].b] < 6) continue;
							cp[v[i].a - q][v[i].b] = -3;
						}
					}
					else if (j == 2) {
						for (int q = 1; q < m; q++) {
							if (v[i].b + q >= m || cp[v[i].a][v[i].b + q] == 6) break;
							if (cp[v[i].a][v[i].b + q] > 0 && cp[v[i].a][v[i].b + q] < 6) continue;
							cp[v[i].a][v[i].b + q] = -3;
						}
						for (int q = 1; q < n; q++) {
							if (v[i].a + q >= n || cp[v[i].a + q][v[i].b] == 6) break;
							if (cp[v[i].a + q][v[i].b] > 0 && cp[v[i].a + q][v[i].b] < 6) continue;
							cp[v[i].a + q][v[i].b] = -3;
						}
						for (int q = 1; q < m; q++) {
							if (v[i].b - q < 0 || cp[v[i].a][v[i].b - q] == 6) break;
							if (cp[v[i].a][v[i].b - q] > 0 && cp[v[i].a][v[i].b - q] < 6) continue;
							cp[v[i].a][v[i].b - q] = -3;
						}
					}
					else if (j == 3) {
						for (int q = 1; q < n; q++) {
							if (v[i].a + q >= n || cp[v[i].a + q][v[i].b] == 6) break;
							if (cp[v[i].a + q][v[i].b] > 0 && cp[v[i].a + q][v[i].b] < 6) continue;
							cp[v[i].a + q][v[i].b] = -3;
						}
						for (int q = 1; q < m; q++) {
							if (v[i].b - q < 0 || cp[v[i].a][v[i].b - q] == 6) break;
							if (cp[v[i].a][v[i].b - q] > 0 && cp[v[i].a][v[i].b - q] < 6) continue;
							cp[v[i].a][v[i].b - q] = -3;
						}
						for (int q = 1; q < n; q++) {
							if (v[i].a - q < 0 || cp[v[i].a - q][v[i].b] == 6) break;
							if (cp[v[i].a - q][v[i].b] > 0 && cp[v[i].a - q][v[i].b] < 6) continue;
							cp[v[i].a - q][v[i].b] = -3;
						}
					}
				}

				else if (v[i].c == 5) {
					for (int q = 1; q < m; q++) {
						if (v[i].b + q >= m || cp[v[i].a][v[i].b + q] == 6) break;
						if (cp[v[i].a][v[i].b + q] > 0 && cp[v[i].a][v[i].b + q] < 6) continue;
						cp[v[i].a][v[i].b + q] = -3;
					}
					for (int q = 1; q < n; q++) {
						if (v[i].a + q >= n || cp[v[i].a + q][v[i].b] == 6) break;
						if (cp[v[i].a + q][v[i].b] > 0 && cp[v[i].a + q][v[i].b] < 6) continue;
						cp[v[i].a + q][v[i].b] = -3;
					}
					for (int q = 1; q < m; q++) {
						if (v[i].b - q < 0 || cp[v[i].a][v[i].b - q] == 6) break;
						if (cp[v[i].a][v[i].b - q] > 0 && cp[v[i].a][v[i].b - q] < 6) continue;
						cp[v[i].a][v[i].b - q] = -3;
					}
					for (int q = 1; q < n; q++) {
						if (v[i].a - q < 0 || cp[v[i].a - q][v[i].b] == 6) break;
						if (cp[v[i].a - q][v[i].b] > 0 && cp[v[i].a - q][v[i].b] < 6) continue;
						cp[v[i].a - q][v[i].b] = -3;
					}
				}
			}
		}
	}

	int cou = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cp[i][j] == 0) cou++;
		}
	}

	ans = min(ans, cou);
}

void pro(int co, int i) {
	if (co == v.size()) {
		solve();
		return;
	}

	for (int w = i; w < v.size(); w++) {
		for (int r = 0; r < v[w].d; r++) {
			if (visit[w][r] == 0) {
				visit[w][r] = 1;
				pro(co + 1, w + 1);
				visit[w][r] = 0;
			}
		}
	}
}

int main() {
	input();
	pro(0, 0);
	cout << ans << endl;
	return 0;
}