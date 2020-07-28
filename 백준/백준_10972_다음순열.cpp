#include <algorithm>
#include <iostream>

using namespace std;

int n;
int v[10001];
int ar[10001];
int ans[10001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> ar[i];
	bool che = false;

	int cc[10001];
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
		cc[i] = i + 1;
	}

	sort(cc, cc + n, cmp);

	bool ff = false;
	for (int i = 0; i < n; i++) {
		if (cc[i] != ar[i]) {
			ff = true;
			break;
		}
	}

	if (!ff) cout << -1 << endl;

	else {
		do {
			if (che) {
				for (int i = 0; i < n; i++) ans[i] = v[i];
				break;
			}

			bool flag = false;
			for (int i = 0; i < n; i++) {
				if (ar[i] != v[i]) {
					flag = true;
					break;
				}
			}
			if (!flag) che = true;
		} while (next_permutation(v, v + n));

		for (int i = 0; i < n; i++) cout << ans[i] << " ";
	}

	return 0;
}