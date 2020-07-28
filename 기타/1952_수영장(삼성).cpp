#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int ar[13];
int dm[13];
int dp[13];
int ans;
int a, b, c, d;

void input() {
	ans = 0;
	memset(ar, 0, sizeof(ar));
	memset(dm, 0, sizeof(dm));
	memset(dp, 0, sizeof(dp));
	cin >> a >> b >> c >> d;
	for (int i = 1; i < 13; i++) {
		cin >> ar[i];
	}
}

void solve() {
	for (int i = 1; i < 13; i++) {
		dm[i] = min(ar[i] * a, b);
	}
	dp[1] = dm[1] + dp[0];
	dp[2] = dm[2] + dp[1];
	for (int i = 3; i < 13; i++) {
		dp[i] = min(dp[i - 1] + dm[i], dp[i - 3] + c);
	}
	ans = min(dp[12], d);
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		input();
		solve();
		cout << "#" << k + 1 << " " << ans << endl;
	}
	return 0;
}