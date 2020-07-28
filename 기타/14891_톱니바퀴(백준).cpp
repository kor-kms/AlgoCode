#include <iostream>

using namespace std;

int ar[4][8];
int kk;
int k[100][2];
int result;

void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &ar[i][j]);
		}
	}

	cin >> kk;

	for (int i = 0; i < kk; i++) {
		cin >> k[i][0] >> k[i][1];
	}
}

void ro(int num, int rr) {
	if (rr == 1) {
		int ss = ar[num][7];
		for (int i = 7; i > 0; i--) {
			ar[num][i] = ar[num][i - 1];
		}
		ar[num][0] = ss;
	}
	else {
		int ss = ar[num][0];
		for (int i = 0; i < 7; i++) {
			ar[num][i] = ar[num][i + 1];
		}
		ar[num][7] = ss;
	}
}

void solve() {
	for (int i = 0; i < kk; i++) {
		int num = k[i][0] - 1;
		int rr = k[i][1];

		int st[3] = { 0,0,0 };
		if (ar[0][2] != ar[1][6]) {
			st[0] = 1;
		}
		if (ar[1][2] != ar[2][6]) {
			st[1] = 1;
		}
		if (ar[2][2] != ar[3][6]) {
			st[2] = 1;
		}

		ro(num, rr);

		if (num == 0) {
			if (st[0] == 1) {
				ro(1, -rr);
				if (st[1] == 1) {
					ro(2, rr);
					if (st[2] == 1) {
						ro(3, -rr);
					}
				}
			}
		
		}

		else if (num == 1) {
			if (st[0] == 1) {
				ro(0, -rr);
			}
			if (st[1] == 1) {
				ro(2, -rr);
				if (st[2] == 1) {
					ro(3, rr);
				}
			}
		}

		else if (num == 2) {
			if (st[2] == 1) {
				ro(3, -rr);
			}
			if (st[1] == 1) {
				ro(1, -rr);
				if (st[0] == 1) {
					ro(0, rr);
				}
			}
		}

		else if (num == 3) {
			if (st[2] == 1) {
				ro(2, -rr);
				if (st[1] == 1) {
					ro(1, rr);
					if (st[0] == 1) {
						ro(0, -rr);
					}
				}
			}
		}
	}

	if (ar[0][0] == 1) result += 1;
	if (ar[1][0] == 1) result += 2;
	if (ar[2][0] == 1) result += 4;
	if (ar[3][0] == 1) result += 8;
}

int main() {
	input();
	solve();
	cout << result << endl;
	return 0;
}