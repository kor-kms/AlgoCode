#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> answer;
string re[100000][3];
int ct;

vector<string> solution(vector<string> record) {
	for (int i = 0; i < record.size(); i++) {
		int n = 0;
		for (int w = 0; w < record[i].size(); w++) {
			if (record[i][w] == ' ') {
				n++;
				continue;
			}
			if (n == 0) {
				re[i][0] += record[i][w];
			}
			else if (n == 1) {
				re[i][1] += record[i][w];
			}
			else if (n == 2) {
				re[i][2] += record[i][w];
			}
		}
	}

	for (int i = 0; i < record.size(); i++) {
		if (re[i][0] == "Enter") {
			for (int j = 0; j < i; j++) {
				if (re[j][1] == re[i][1] && re[j][2] != "") {
					re[j][2] = re[i][2];
				}
			}
		}

		else if (re[i][0] == "Change") {
			for (int j = 0; j < i; j++) {
				if (re[j][1] == re[i][1] && re[j][2] != "") {
					re[j][2] = re[i][2];
				}
			}
		}
	}

	ct = 0;
	for (int i = 0; i < record.size(); i++) {
		if (re[i][0] == "Enter") {
			answer.push_back(re[i][2] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
			ct++;
		}
		else if (re[i][0] == "Leave") {
			for (int j = 0; j < i; j++) {
				if (re[j][1] == re[i][1] && re[j][2] != "") {
					answer.push_back(re[j][2] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
					ct++;
				}
			}
		}
	}

	return answer;
}

int main() {	
	vector<string> ss = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	vector<string> qqq = solution(ss);
	for (int i = 0; i < ct; i++) {
	cout << qqq[i] << endl;
	}
	return 0;
}