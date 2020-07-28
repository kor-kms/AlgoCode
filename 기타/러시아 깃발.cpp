#include <iostream>
#include <string>

using namespace std;

char ar[50][50];
int color[50][4];
int ww[3];

int main() {
	int t;
	int n, m;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int w = 0;
		int b = 0;
		int r = 0;
		int ct = 0;
		int sp = 0;
		int wb = 0;
		int bw = 0;
		int br = 0;
		int rb = 0;

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				color[i][j] = 0;
			}
		}

		for (int j = 0; j < 3; j++) {
			ww[j] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ar[i][j];
				if (ar[i][j] == 'W') {
					color[i][0]++;
					if (i > 0 && i < n - 2) ww[0]++;
				}
				else if (ar[i][j] == 'B') {
					color[i][1]++;
					if (i > 0 && i < n - 2) ww[1]++;
				}
				else if (ar[i][j] == 'R') {
					color[i][2]++;
					if (i > 0 && i < n - 2) ww[2]++;
				}
			}

			if (color[i][0] > color[i][1]) wb++;
			else if (color[i][0] < color[i][1]) bw++;
			if (color[i][1] > color[i][2]) br++;
			else if (color[i][1] < color[i][2]) rb++;
		}

		ct = color[0][1] + color[0][2];//흰줄 최소하나 만들기

		if (ww[0] > ww[1] && ww[0] > ww[2]) {
			for (int i = 1; i < n; i++) {
				if (n - i > 2) ct += color[i][1] + color[i][2];
				else if (n - i == 2) ct += color[i][0] + color[i][2];
				else ct += color[i][0] + color[i][1];
			}
		}

		if (ww[1] >= ww[0] && ww[1] > ww[2]) {
			for (int i = 1; i < n; i++) {
				if (n - i > 1) ct += color[i][0] + color[i][2];
				else if (n - i == 1) ct += color[i][0] + color[i][1];
			}
		}

		if (ww[2] >= ww[0] && ww[2] >= ww[1]) {
			for (int i = 1; i < n; i++) {
				if (i == 1) ct += color[i][0] + color[i][2];
				else ct += color[i][0] + color[i][1];
			}
		}

		cout << "#" << k + 1 << " " << ct << endl;
	}

	return 0;
}