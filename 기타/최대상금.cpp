#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int num;
string n;
int re;

void dfs(int a, int b) {
	if (b == num) {
		re = max(re, stoi(n));
		return;
	}

	for (int i = a; i < n.size(); i++) {
		for (int j = i + 1; j < n.size(); j++) {
			if (n[i] <= n[j]) {
				swap(n[i], n[j]);
				dfs(i, b + 1);
				swap(n[i], n[j]);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n >> num;
		re = 0;
		dfs(0, 0);
		cout << "#" << k + 1 << " " << re << endl;
	}
	return 0;
}