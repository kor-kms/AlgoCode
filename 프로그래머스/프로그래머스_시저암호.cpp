#include <string>
#include <vector>

using namespace std;
//0~25
//32~57
//-33
string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.size(); i++) {
		int a = s[i] - 'A';
		if (a == -33) answer += s[i];
		else {
			if (a >= 0 && a < 26) {
				a += n;
				if (a >= 26) {
					a -= 26;
					char c = a + 'A';
					answer += c;
				}
				else {
					char c = a + 'A';
					answer += c;
				}
			}
			else if (a > 31 && a < 58) {
				a += n;
				if (a >= 58) {
					a -= 26;
					char c = a + 'A';
					answer += c;
				}
				else {
					char c = a + 'A';
					answer += c;
				}
			}
		}
	}
	return answer;
}