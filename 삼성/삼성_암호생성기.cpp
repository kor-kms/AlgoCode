#include <queue>
#include <iostream>

using namespace std;

queue<int> q;

void input() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < 8; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
}

void solve() {
	bool flag = true;
	while (true) {
		for (int i = 1; i < 6; i++) {
			int x = q.front() - i;
			q.pop();
			if(x > 0) q.push(x);
			else {
				q.push(0);
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
}

int main() {
	for (int k = 0; k < 10; k++) {
		int t;
		cin >> t;
		input();
		solve();
		cout << "#" << t << " ";
		for (int i = 0; i < 8; i++) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}