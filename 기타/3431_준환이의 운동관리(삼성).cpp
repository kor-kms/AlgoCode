#include <iostream>

using namespace std;

int a, b, c;
int result;

void input() {
	result = 0;
	cin >> a >> b >> c;
}

void solve() {
	if (c < a) {
		result = a - c;
	}
	else if (c >= a && c <= b) {
		result = 0;
	}
	else if (c > b) {
		result = -1;
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		input();
		solve();
		cout << "#" << k + 1 << " " << result << endl;
	}
	return 0;
}