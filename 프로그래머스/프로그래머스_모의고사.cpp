#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int c1 = 0; int c2 = 0; int c3 = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (i % 5 == 0) {
			if (answers[i] == 1) c1++;
		}
		else if (i % 5 == 1) {
			if (answers[i] == 2) c1++;
		}
		else if (i % 5 == 2) {
			if (answers[i] == 3) c1++;
		}
		else if (i % 5 == 3) {
			if (answers[i] == 4) c1++;
		}
		else if (i % 5 == 4) {
			if (answers[i] == 5) c1++;
		}
	}

	for (int i = 0; i < answers.size(); i++) {
		if (i % 2 == 0) {
			if (answers[i] == 2) c2++;
		}
		else if (i % 2 == 1) {
			if (i % 8 == 1) {
				if (answers[i] == 1) c2++;
			}
			else if (i % 8 == 3) {
				if (answers[i] == 3) c2++;
			}
			else if (i % 8 == 5) {
				if (answers[i] == 4) c2++;
			}
			else if (i % 8 == 7) {
				if (answers[i] == 5) c2++;
			}
		}
	}

	for (int i = 0; i < answers.size(); i++) {
		if (i % 10 == 0 || i % 10 == 1) {
			if (answers[i] == 3) c3++;
		}
		else if (i % 10 == 2 || i % 10 == 3) {
			if (answers[i] == 1) c3++;
		}
		else if (i % 10 == 4 || i % 10 == 5) {
			if (answers[i] == 2) c3++;
		}
		else if (i % 10 == 6 || i % 10 == 7) {
			if (answers[i] == 4) c3++;
		}
		else if (i % 10 == 8 || i % 10 == 9) {
			if (answers[i] == 5) c3++;
		}
	}

	vector<pair<int, int>> w;
	w.push_back({ c1,1 });
	w.push_back({ c2,2 });
	w.push_back({ c3,3 });
	sort(w.begin(), w.end());

	if (w[2].first == w[1].first) {
		if (w[1].first == w[0].first) {
			answer.push_back(w[2].second);
			answer.push_back(w[1].second);
			answer.push_back(w[0].second);
		}
		else {
			answer.push_back(w[2].second);
			answer.push_back(w[1].second);
		}
	}
	else {
		answer.push_back(w[2].second);
	}

	sort(answer.begin(), answer.end());
	return answer;
}