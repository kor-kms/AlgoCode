#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
	int answer = 0;
	int n = 0;
	vector<int> v;
	for (int i = 0; i < numbers.size(); i++) {
		int a = numbers[i] - '0';
		v.push_back(a);
	}

	do {
		int ct = 0;
		int t = pow(10, v.size() - 1);
		for (int i = 0; i < v.size(); i++) {
			n += t * v[i];
			t /= 10;
		}
		for (int i = 1; i <= n; i++) {
			if (n%i == 0) ct++;
		}
		if (ct == 1) answer++;
	} while (next_permutation(v.begin(), v.end()));

	return answer;
}

int main() {
	solution("17");
}