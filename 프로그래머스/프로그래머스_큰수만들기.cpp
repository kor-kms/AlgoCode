#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	vector<int> s;
	vector<int> v;
	for (int i = 0; i < number.size(); i++) {
		int a = number[i] - '0';
		s.push_back(a);
	}

	int lo = 0;
	v.push_back(s[0]);
	for (int i = 1; i < s.size(); i++) {
		int x = s[i];
		bool flag = false;
		for (int j = v.size() - 1; j >= 0; j--) {
			int y = v.back();
			if (y >= x) {
				v.push_back(x);
				break;
			}
			else {
				v.pop_back();
				k--;
			}
			if (k == 0) {
				lo = i;
				flag = true;
				break;
			}
		}
		if (flag) break;
		if (v.size() == 0) v.push_back(x);
	}

	if (k == 0) {
		for (int i = lo; i < s.size(); i++) v.push_back(s[i]);
		for (int i = 0; i < v.size(); i++) answer += to_string(v[i]);
	}
	else {
		for (int i = v.size() - 1; i > k; i--) v.pop_back();
		for (int i = 0; i < v.size(); i++) answer += to_string(v[i]);
	}
	return answer;
}

int main() {
	solution("54321", 2);
}