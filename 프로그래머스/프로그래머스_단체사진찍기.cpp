#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool vi[8];
char ar[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
int ans;
vector<string> v;

bool check_co(string s) {
	for (int i = 0; i < v.size(); i++) {
		int a = 0;
		int b = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == v[i][0]) a = j;
			if (s[j] == v[i][2]) b = j;
		}

		int sum = abs(a - b) - 1;
		int aa = v[i][4] - '0';

		if (v[i][3] == '=') {
			if (sum != aa) return false;
		}
		else if (v[i][3] == '<') {
			if (sum >= aa) return false;
		}
		else if (v[i][3] == '>') {
			if (sum <= aa) return false;
		}
	}
	return true;
}

void pro(int ct, string s) {
	if (ct == 8) {
		if (check_co(s)) ans++;
		return;
	}

	for (int w = 0; w < 8; w++) {
		if (vi[w] == 0) {
			vi[w] = 1;
			pro(ct + 1, s + ar[w]);
			vi[w] = 0;
		}
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	int answer = 0;
	v = data;
	for (int i = 0; i < 8; i++) {
		vi[i] = 1;
		string s = "";
		s += ar[i];
		pro(1, s);
		vi[i] = 0;
	}
	answer = ans;
	return answer;
}

int main() {
	solution(2, { "N~F=0", "R~T>2" });
}