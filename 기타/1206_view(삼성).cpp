#include <iostream>
#include <algorithm>

using namespace std;

int ar[1000];
int n;
int result;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
}

void solve() {
	int ct = 0;
	int ct2 = 0;
	for (int i = 2; i < n - 2; i++) {
		if (ar[i] > ar[i + 1] && ar[i] > ar[i + 2] && ar[i] > ar[i - 1] && ar[i] > ar[i - 2]) {
			ct = min(ar[i] - ar[i + 1], ar[i] - ar[i + 2]);
			ct2 = min(ar[i] - ar[i - 1], ar[i] - ar[i - 2]);
			result += min(ct, ct2);
		}
	}
}

int main() {
	for (int k = 1; k <= 10; k++) {
		result = 0;
		input();
		solve();
		cout << "#" << k << " " << result << endl;
	}
	return 0;
}