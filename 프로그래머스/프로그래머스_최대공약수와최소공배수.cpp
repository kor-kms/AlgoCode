#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	double a = n; double s = m;
	if (a > s) swap(a, s);

	if (s / a == 0) {
		answer.push_back(n);
		answer.push_back(m);
	}
	else {
		answer
	}
	return answer;
}