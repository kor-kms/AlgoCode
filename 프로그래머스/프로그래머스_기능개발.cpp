#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
	vector<int> answer;
	vector<pair<int, int>> v;

	for (int i = 0; i < p.size(); i++) {
		v.push_back({ p[i],s[i] });
	}

	int fl = 0;
	int c = 0;
	while (true) {
		if (c == v.size()) break;
		int ct = 0;
		for (int i = fl; i < v.size(); i++) {
			if (v[fl].first < 100) break;
			if (v[i].first >= 100) {
				fl++;
				ct++;
				c++;
			}
		}
		if (ct != 0) answer.push_back(ct);

		for (int i = 0; i < v.size(); i++) v[i].first += v[i].second;
	}
	return answer;
}

int main() {
	solution({ 93,30,55 }, { 1,30,5 });
}