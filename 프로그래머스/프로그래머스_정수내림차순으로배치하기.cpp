#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

long long solution(long long n) {
	long long answer = 0;
	vector<int> v;
	string s = to_string(n);
	for (int i = 0; i < s.size(); i++) {
		int a = s[i] - '0';
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);

	int t = pow(10, v.size() - 1);
	for (int i = 0; i < v.size(); i++) {
		answer += v[i] * t;
		t /= 10;
	}

	/*char* end = NULL;
	answer = strtoll(ss.c_str(), &end, 10);*/
	return answer;
}