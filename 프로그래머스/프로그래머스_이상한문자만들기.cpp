#include <string>
#include <vector>

using namespace std;
//0~25
//32~57
//-33

string solution(string s) {
	string answer = "";
	vector<string> v;
	string a = "";
	for (int i = 0; i < s.size(); i++) {
		if (i == s.size() - 1) {
			a += s[i];
			v.push_back(a);
			break;
		}
		if (s[i] == ' ') {
			v.push_back(a);
			a = "";
			continue;
		}
		a += s[i];
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (j % 2 == 0) {
				int x = v[i][j] - 'A';
				if (x > 31 && x < 58) {
					x -= 32;
					char c = x + 'A';
					answer += c;
				}
				else answer += v[i][j];
			}
			else {
				int x = v[i][j] - 'A';
				if (x >= 0 && x < 26) {
					x += 32;
					char c = x + 'A';
					answer += c;
				}
				else answer += v[i][j];
			}
		}
		if(i != v.size() - 1) answer += ' ';
	}
	return answer;
}

int main() {
	solution("try hello world");
}