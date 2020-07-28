#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

string solution(string s) {
	string answer = "";
	vector<char> w[2];
	for (int i = 0; i < s.size(); i++) {
		int a = s[i] - 'A';
		if (a >= 32) w[0].push_back(a);
		else w[1].push_back(a);
	}
	sort(w[0].begin(), w[0].end(), cmp);
	sort(w[1].begin(), w[1].end(), cmp);

	for (int i = 0; i < w[0].size(); i++) {
		char a = w[0][i] + 'A';
		answer += a;
	}
	for (int i = 0; i < w[1].size(); i++) {
		char a = w[1][i] + 'A';
		answer += a;
	}
	return answer;
}