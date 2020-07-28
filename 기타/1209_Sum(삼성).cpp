#include <iostream>
#include <algorithm>

using namespace std;

int ar[100][100];
int result;
int t;

void input() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> ar[i][j];
		}
	}
}

void solve() {
	for (int i = 0; i < 100; i++) {
		int ct = 0;
		for (int j = 0; j < 100; j++) {
			ct += ar[i][j];
		}
		result = max(result, ct);
	}

	for (int i = 0; i < 100; i++) {
		int ct = 0;
		for (int j = 0; j < 100; j++) {
			ct += ar[j][i];
		}
		result = max(result, ct);
	}

	int ct1 = 0;
	for (int i = 0; i < 100; i++) {
		ct1 += ar[i][i];
	}
	result = max(result, ct1);

	int ct2 = 0;
	for (int i = 0; i < 100; i ++) {
		ct2 += ar[i][99 - i];
	}
	result = max(result, ct2);
}

int main() {
	for (int k = 0; k < 10; k++) {
		cin >> t;
		result = 0;
		input();
		solve();
		cout << "#" << t << " " << result << endl;
	}
	return 0;
}