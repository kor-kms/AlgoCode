#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
int che = 0;

void solve() {
	//if (s.size() > t.size()) swap(s, t);
	int a = 0; int b = 0;
	bool flag = false;
	int ct = 0;
	while (ct <= 500) {
		if (s[a] != t[b]) {
			che = 0;
			flag = true;
			break;
		}
		a++;
		b++;
		if (a == s.size()) a = 0;
		if (b == t.size()) b = 0;
		ct++;
	}
	
	if (!flag) che = 1;
}

int main() {
	cin >> s >> t;
	solve();
	cout << che << endl;
	return 0;
}