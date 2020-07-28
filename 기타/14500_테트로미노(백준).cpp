#include <iostream>
#include <algorithm>

using namespace std;

int ar[500][500];
int ans;
int cou;
int n, m;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}
}

void solve() {
	//1번
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 3; j++) {
			cou = ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i][j + 3];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 3; i++) {
		for (int j = 0; j < m; j++) {
			cou = ar[i + 1][j] + ar[i + 2][j] + ar[i + 3][j] + ar[i][j];
			ans = max(ans, cou);
		}
	}
	//2번
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i][j + 1] + ar[i + 1][j + 1];
			ans = max(ans, cou);
		}
	}
	//3번
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 2][j + 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i][j + 1] + ar[i][j + 2];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i][j - 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 2; j < m; j++) {
			cou = ar[i][j] + ar[i - 1][j] + ar[i][j - 1] + ar[i][j - 2];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 2][j - 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m - 2; j++) {
			cou = ar[i][j] + ar[i - 1][j] + ar[i][j + 1] + ar[i][j + 2];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i][j + 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i][j + 1] + ar[i][j + 2];
			ans = max(ans, cou);
		}
	}

	//4번
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i + 1][j + 1] + ar[i + 2][j + 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i][j + 1] + ar[i + 1][j - 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			cou = ar[i][j] + ar[i + 1][j] + ar[i + 1][j - 1] + ar[i + 2][j - 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			cou = ar[i][j] + ar[i + 1][j + 1] + ar[i][j + 1] + ar[i + 1][j + 2];
			ans = max(ans, cou);
		}
	}
	//5번
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			cou = ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			cou = ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			cou = ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 1];
			ans = max(ans, cou);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			cou = ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 1];
			ans = max(ans, cou);
		}
	}
}

int main() {
	input();
	solve();
	cout << ans << endl;
	return 0;
}