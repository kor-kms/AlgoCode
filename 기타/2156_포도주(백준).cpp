#include <iostream>
#include <algorithm>

using namespace std;

int n;
int ar[10000];
int dp[10000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> ar[i];

	dp[0] = ar[0];
	dp[1] = dp[0] + ar[1];
	dp[2] = max(dp[1], ar[0] + ar[2]);
	dp[2] = max(dp[2], ar[1] + ar[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 3] + ar[i - 1] + ar[i]);
		dp[i] = max(dp[i], dp[i - 2] + ar[i]);
	}

	cout << dp[n - 1] << endl;

	return 0;
}