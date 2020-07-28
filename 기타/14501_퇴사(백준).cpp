#include <iostream>
#include <algorithm>

using namespace std;

int ar[16];
int fee[16];
int result;
int n;

void dfs(int day, int re) {
	if (day == n + 1) {
		result = max(result, re);
		return;
	}

	if (day + ar[day] <= n + 1) dfs(day + ar[day], re + fee[day]);

	dfs(day + 1, re);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i] >> fee[i];
	}

	dfs(1, 0);
	cout << result << endl;
}