#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int ar[50][50];
int n, m, k, result = 1000000;
int q[6][3];
vector<int> v;
queue<int> qu;

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int w, e, r;
		cin >> w >> e >> r;
		q[i][0] = w - 1;
		q[i][1] = e - 1;
		q[i][2] = r;
		v.push_back(i);
	}
}

void sumc() {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += ar[i][j];
		}
		result = min(result, sum);
	}
}

void ro(int r, int c, int s) {
	int cc = 0;
	int flag = 0;
	for (int i = 0; i < 8 * s; i++) {
		if (flag == 0) {
			qu.push(ar[r - s + cc][c - s]);
			cc++;
			if (cc == s * 2) {
				cc = 0;
				flag = 1;
			}
		}
		else if (flag == 1) {
			qu.push(ar[r + s][c - s + cc]);
			cc++;
			if (cc == s * 2) {
				cc = 0;
				flag = 2;
			}
		}
		else if (flag == 2) {
			qu.push(ar[r + s - cc][c + s]);
			cc++;
			if (cc == s * 2) {
				cc = 0;
				flag = 3;
			}
		}
		else if (flag == 3) {
			qu.push(ar[r - s][c + s - cc]);
			cc++;
			if (cc == s * 2) {
				cc = 0;
				flag = 4;
			}
		}
	}

	int temp = qu.front();
	qu.pop();

	qu.push(temp);
	cc = 0;
	flag = 0;
	for (int i = 0; i < 8 * s; i++) {
		int tr = qu.front();
		qu.pop();
		if (flag == 0) {
			ar[r - s + cc][c - s] = tr;
			cc++;
			if (cc == s * 2) {
				cc = 0;
				flag = 1;
			}
		}
		else if (flag == 1) {
			ar[r + s][c - s + cc] = tr;
			cc++;
			if (cc == s * 2) {
				cc = 0;
				flag = 2;
			}
		}
		else if (flag == 2) {
			ar[r + s - cc][c + s] = tr;
			cc++;
			if (cc == s * 2) {
				cc = 0;
				flag = 3;
			}
		}
		else if (flag == 3) {
			ar[r - s][c + s - cc] = tr;
			cc++;
			if (cc == s * 2) {
				cc = 0;
				flag = 4;
			}
		}
	}
}

void solve(int ra, int ca, int sa) {
	int rr = ra;
	int cc = ca;
	int ss = sa;

	while (true) {
		ro(rr, cc, ss);
		ss--;
		if (ss == 0) break;
	}
}

int main() {
	input();
	int cp[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cp[i][j] = ar[i][j];
		}
	}
	do {
		for (int i = 0; i < k; i++) {
			int ra = q[v[i]][0];
			int ca = q[v[i]][1];
			int sa = q[v[i]][2];
			solve(ra, ca, sa);
		}
		sumc();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ar[i][j] = cp[i][j];
			}
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << result << endl;
	return 0;
}