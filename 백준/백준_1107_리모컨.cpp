#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, ans, cnt;
bool vi[10];

void input() {
	ans = 987654321;
	cin >> n;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int b;
		cin >> b;
		vi[b] = true;
	}
}

void pro(int ct, string s) {
	if (ct == cnt) {
		int nn = stoi(s);
		ans = min(ans, abs(n - nn));
		return;
	}

	for (int w = 0; w < 10; w++) {
		if (!vi[w]) {
			string ss = to_string(w);
			pro(ct + 1, s + ss);
		}
	}
}

int main() {
	input();
	string s = to_string(n);
	int ex2 = 987654321;
	for (int i = s.size() - 1; i <= s.size() + 1; i++) {
		if (i <= 0 || i > 6) continue;
		cnt = i;
		pro(0, "");
		ex2 = min(ex2, ans + i);
	}
	int ex = abs(n - 100);
	int res = min(ex, ex2);
	cout << res << endl;
	return 0;
}