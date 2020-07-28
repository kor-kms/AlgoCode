#include <iostream>

using namespace std;

int ar[50][100];
int t;
int n, m;
int num[8];

int main() {
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n >> m;
		int c = 0;
		int cc = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%1d", &ar[i][j]);
				if (ar[i][j] == 1) {
					c = i;
					cc = j;
				}
			}
		}

		cc -= 55;
		int ct = 0;
		for (int i = cc; i < cc + 56; i = i + 7) {
			if (ar[c][i + 1] == 0) {//00
				if (ar[c][i + 2] == 0) {//000
					if (ar[c][i + 4] == 0) num[ct] = 9;
					else num[ct] = 0;
				}
				else {//001
					if (ar[c][i + 3] == 0) num[ct] = 2;
					else num[ct] = 1;
				}
			}

			else {//01
				if (ar[c][i + 2] == 0) {//010
					if (ar[c][i + 3] == 0) num[ct] = 4;
					else num[ct] = 6;
				}
				else {//011
					if (ar[c][i + 3] == 0) {
						if (ar[c][i + 4] == 0) num[ct] = 5;
						else num[ct] = 8;
					}
					else {
						if (ar[c][i + 4] == 0) num[ct] = 7;
						else num[ct] = 3;
					}
				}
			}
			ct++;
		}

		int result = 0;
		result = (num[0] + num[2] + num[4] + num[6]) * 3 + num[1] + num[3] + num[5] + num[7];
		if (result % 10 == 0) result = num[0] + num[2] + num[4] + num[6] + num[1] + num[3] + num[5] + num[7];
		else result = 0;
		cout << "#" << k + 1 << " " << result << endl;
	}
	return 0;
}