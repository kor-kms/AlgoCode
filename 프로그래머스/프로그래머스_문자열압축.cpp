#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = s.size();

	for (int i = 1; i <= s.size() / 2; i++) {
		string ans = "";
		string a = s.substr(0, i);
		int ct = 1;
		bool flag = true;
		for (int j = i; j <= s.size(); j = j + i) {
			string w = s.substr(j, i);
			if (w.size() < a.size() && w.size() != 0) {
				flag = false;
			}
			if (a == w) {
				ct++;
			}
			else {
				if (ct == 1) {
					ans += a;
				}
				else {
					if (ct < 10 && ct > 0) {
						ans += "1";
					}
					else if (ct >= 10 && ct < 100) {
						ans += "10";
					}
					else if (ct >= 100 && ct < 1000) {
						ans += "100";
					}
					ans += a;
				}
				a = w;
				ct = 1;
			}
		}
		if (!flag) {
			int rr = s.size() % i;
			for (int j = s.size() - rr; j < s.size(); j++) {
				ans += s[j];
			}
		}
		int qq = ans.size();
		answer = min(answer, qq);
	}

	return answer;
}

int main() {
	string s = "ababcdcdababcdcd";
	string a = s.substr(0, 3);
	cout<<solution(s);
	//cout << s << endl << a << endl;
	return 0;
}