#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int inning;
int player[50][9];
int per[8] = { 1,2,3,4,5,6,7,8 };
int temp[9];
queue<int> q;
int ar[4];
int out, result, remax;
bool nex;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> player[i][j];
		}
	}
	temp[3] = 0;
	q.push(0);
	q.push(0);
	q.push(0);
}

void solve() {
	result = 0;
	int st = 0;

	for (int k = 0; k < n; k++) {
		out = 0;
		nex = false;
		while(true) {
			for (int i = st; i < 9; i++) {
				int xx = player[k][temp[i]];
				if (xx == 0)
					out++;
				if (xx == 1) {
					if (ar[3] == 1) {
						ar[3] = 0;
						result++;
					}
					for (int ss = 3; ss > 1; ss--) {
						if (ar[ss - 1] != 0) {
							ar[ss] = 1;
							ar[ss - 1] = 0;
						}
					}
					ar[1] = 1;
				}
				if (xx == 2) {
					if (ar[3] == 1) {
						ar[3] = 0;
						result++;
					}
					if (ar[2] == 1) {
						ar[2] = 0;
						result++;
					}
					if (ar[1] == 1) {
						ar[1] = 0;
						ar[3] = 1;
					}
					ar[2] = 1;
				}
				if (xx == 3) {
					for (int j = 1; j <= 3; j++) {
						if (ar[j] == 1) {
							ar[j] = 0;
							result++;
						}
					}
					ar[3] = 1;
				}
				if (xx == 4) {
					for (int j = 1; j <= 3; j++) {
						if (ar[j] == 1) {
							ar[j] = 0;
							result++;
						}
					}
					result++;
				}
				if (out == 3) {
					if (i + 1 == 9) {
						st = 0;
					}
					else
						st = i + 1;
					for (int j = 1; j <= 3; j++) {
						ar[j] = 0;
					}
					nex = true;
					break;
				}
			}
			if (nex) break;
			st = 0;
			/*int xx = player[k][temp[i]];
			if (xx == 0) {
				out++;
			}

			else if (xx == 1) {
				q.push(1);
			}

			else if (xx == 2) {
				q.push(1);
				q.push(0);
			}

			else if (xx == 3) {
				q.push(1);
				q.push(0);
				q.push(0);
			}

			else if (xx == 4) {
				q.push(1);
				q.push(0);
				q.push(0);
				q.push(0);
			}

			if (out == 3) {
				if (i + 1 == 9) i = 0;
				else st = i + 1;
				break;
			}

			while (true) {
				if (q.size() == 3) break;
				int ss = q.front();
				q.pop();
				if (ss == 1) result++;
			}

			if (i + 1 == 9) i = 0;*/
		}
	}
}

void nep() {
	do {
		int cc = 0;
		for (int i = 0; i < 9; i++) {
			if (i == 3) continue;
			temp[i] = per[cc];
			cc++;
		}
		solve();
		remax = max(remax, result);
	} while (next_permutation(per, per + 8));
}

int main() {
	input();
	nep();
	cout << remax << endl;
	return 0;
}