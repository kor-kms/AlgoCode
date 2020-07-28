#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, tt = 1;
queue<string> q1;
queue<string> q2;

void input() {
	cin >> n;
	for (int i = 0; i < n / 2; i++) {
		string w;
		cin >> w;
		q1.push(w);
	}
	if (n % 2 == 1) {
		string w;
		cin >> w;
		q1.push(w);
	}
	for (int i = 0; i < n / 2; i++) {
		string w;
		cin >> w;
		q2.push(w);
	}
}

void solve() {
	cout << "#" << tt;
	tt++;
	while (!q2.empty()) {
		string s1 = q1.front();
		string s2 = q2.front();
		q1.pop();
		q2.pop();
		cout << " " << s1 << " " << s2;
	}
	if (!q1.empty()) {
		cout << " " << q1.front();
		q1.pop();
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		input();
		solve();
		cout << endl;
	}
	return 0;
}

//#include <iostream>
//#include <string>
//#include <cstring>
//
//using namespace std;
//
//int n;
//string s1[500];
//string s2[500];
//
//void input() {
//	for (int i = 0; i < 500; i++) {
//		s1[i] = "";
//		s2[i] = "";
//	}
//	cin >> n;
//	int q = 0;
//	if (n % 2 == 0) {
//		for (int i = 0; i < n; i++) {
//			if (i < n / 2) cin >> s1[i];
//			else {
//				cin >> s2[q];
//				q++;
//			}
//		}
//	}
//	else {
//		for (int i = 0; i < n; i++) {
//			if (i <= n / 2) cin >> s1[i];
//			else {
//				cin >> s2[q];
//				q++;
//			}
//		}
//	}
//}
//
//void solve() {
//	for (int i = 0; i < n / 2; i++) {
//		cout << s1[i] << " " << s2[i] << " ";
//	}
//	if (n % 2 == 1) cout << s1[n / 2] << endl;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	for (int k = 0; k < t; k++) {
//		input();
//		cout << "#" << k + 1 << " ";
//		solve();
//		cout << endl;
//	}
//	return 0;
//}