#include <iostream>
#include <string>

using namespace std;

int ans;
string s[50];
char ar[50][50];
int n, m;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			ar[i][j] = s[i][j];
		}
	}
}

void solve() {
	if (ar[0][0] == 'W') {
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < 8; j++) {
					if (j % 2 == 0) {
						if (ar[i][j] == 'B') ans++;
					}
					else {
						if (ar[i][j] == 'W') ans++;
					}
				}
			}
			else {
				for (int j = 0; j < 8; j++) {
					if (j % 2 == 0) {
						if (ar[i][j] == 'W') ans++;
					}
					else {
						if (ar[i][j] == 'B') ans++;
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < 8; j++) {
					if (j % 2 == 0) {
						if (ar[i][j] == 'W') ans++;
					}
					else {
						if (ar[i][j] == 'B') ans++;
					}
				}
			}
			else {
				for (int j = 0; j < 8; j++) {
					if (j % 2 == 0) {
						if (ar[i][j] == 'B') ans++;
					}
					else {
						if (ar[i][j] == 'W') ans++;
					}
				}
			}
		}
	}
}

int main() {
	input();
	solve();
	cout << ans << endl;
	return 0;
}