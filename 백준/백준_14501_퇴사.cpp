#include <iostream>
#include <algorithm>

using namespace std;

struct aaa {
	int d;
	int f;
};

aaa ar[16];
int result;
int n;

void dfs(int day, int re) {
	if (day == n + 1) {
		result = max(result, re);
		return;
	}

	if (day + ar[day].d <= n + 1) dfs(day + ar[day].d, re + ar[day].f);

	dfs(day + 1, re);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].d >> ar[i].f;
	}

	dfs(1, 0);
	cout << result << endl;
}