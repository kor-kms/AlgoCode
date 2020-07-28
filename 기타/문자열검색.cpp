#include <iostream>
#include <string>

using namespace std;

string s;
string a;
int main() {
	int t;
	
	for (int k = 0; k < 10; k++) {
		cin >> t;
		cin >> a >> s;
		int ct = 0;
		for (int i = 0; i < s.size(); i++) {
			if (a[0] == s[i]) {
				for (int j = 0; j < a.size(); j++) {
					if (a[j] != s[j + i]) break;
					else if (a.size() - 1 == j) ct++;
				}
			}
		}
		cout << "#" << t << " " << ct << endl;
	}
	return 0;
}