#include <iostream>

using namespace std;

long long n;
long long b, c;
long long result;
long long ar[1000001];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	cin >> b >> c;
	result = n;
}

void solve() {
	for (int i = 0; i < n; i++) {
		long long x = ar[i] - b;
		long long d = x / c;
		long long r = x % c;

		if (x > 0) {
			if (r == 0) result += d;
			else result += (d + 1);
		}
	}
}

int main() {
	input();
	solve();
	cout << result << endl;
	return 0;
}