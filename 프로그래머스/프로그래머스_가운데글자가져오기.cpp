#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int a = s.size() / 2;
	if (s.size() % 2 == 0) {
		answer = s[a - 1];
		answer += s[a];
	}
	else answer = s[a];
	return answer;
}