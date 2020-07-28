#include <string>
#include <vector>
#include <queue>

using namespace std;

struct aaa {
	int w;
	int t;
};

queue<aaa> q;

int solution(int l, int w, vector<int> v) {
	int answer = 0;
	int ct = 0;
	for (int i = 1;; i++) {
		if (!q.empty()) {
			if (q.front().t + l == i) {
				w += q.front().w;
				q.pop();
			}
		}

		int ww = v[ct];
		w -= ww;
		if (w < 0) {
			w += ww;
		}
		else {
			aaa a;
			a.w = v[ct];
			a.t = i;
			q.push(a);
			ct++;
		}
		if (ct == v.size()) break;
	}
	if (q.size() != 1) {
		while (q.size() > 1) q.pop();
	}
	answer = q.front().t + l;
	return answer;
}

int main() {
	solution(2, 10, { 7,4,5,6 });
}