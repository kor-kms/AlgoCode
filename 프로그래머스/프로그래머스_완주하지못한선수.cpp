#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct aaa {
	vector<pair<string, int>> v;
};
aaa a[21][27];

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	
	for (int i = 0; i < completion.size(); i++) {
		int ct = completion[i].size();
		int c = completion[i][0] - 96;
		a[ct][c].v.push_back({ completion[i],0 });
	}

	for (int i = 0; i < participant.size(); i++) {
		bool flag = true;
		int ct = participant[i].size();
		int c = participant[i][0] - 96;
		for (int j = 0; j < a[ct][c].v.size(); j++) {
			if (participant[i] == a[ct][c].v[j].first) {
				if (a[ct][c].v[j].second == 0) {
					a[ct][c].v[j].second++;
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			answer = participant[i];
			break;
		}
	}

	return answer;

	/*queue<string> q;
	for (int i = 0; i < completion.size(); i++) q.push(completion[i]);

	int a = participant.size();
	for (int i = 0; i < a; i++) {
		bool flag = true;
		for (int j = 0; j < q.size(); j++) {
			string s = q.front();
			q.pop();
			if (s == participant.back()) {
				participant.pop_back();
				flag = false;
				break;
			}
			else q.push(s);
		}
		if (flag) {
			answer = participant.back();
			break;
		}
	}*/

	/*
	int b[100000] = { 0, };
	for (int i = 0; i < participant.size(); i++) {
		bool flag = true;
		for (int j = 0; j < completion.size(); j++) {
			if (participant[i] == completion[j]) {
				if (b[j] == 0) {
					b[j]++;
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			answer = participant[i];
			return answer;
		}
	}*/
}

int main() {
	vector<string> v = { "mislav", "mislav", "stanko", "ana" };
	vector<string> s = { "mislav", "ana", "mislav" }; 
	cout << solution(v, s) << endl;
	int a = 'z' - 96;
	cout << a;
	return 0;
}