#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct aaa {
	char c;
	int s;
};
aaa map[30][30];

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool ch = true;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j].c = board[i][j];
		}
	}

	while (true) {
		ch = true;
		/*for (int i = 0; i < m - 1; i++) {
			for (int j = 1; j < n; j++) {
				if (map[i][j].s == -1) continue;
				if (map[i][j].c == map[i][j - 1].c) {
					if (map[i][j].c == map[i + 1][j].c) {
						if (map[i][j].c == map[i + 1][j - 1].c) {
							map[i][j].s = 1;
							map[i][j - 1].s = 1;
							map[i + 1][j].s = 1;
							map[i + 1][j - 1].s = 1;
							ch = false;
						}
					}
				}
			}
		}*/

		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (map[i][j].s == -1) continue;
				if (map[i][j].c == map[i][j + 1].c) {
					if (map[i][j].c == map[i + 1][j].c) {
						if (map[i][j].c == map[i + 1][j + 1].c) {
							map[i][j].s = 1;
							map[i][j + 1].s = 1;
							map[i + 1][j].s = 1;
							map[i + 1][j + 1].s = 1;
							ch = false;
						}
					}
				}
			}
		}

		if (ch == true) break;

		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (map[j][i].s == 1) {
					answer++;
					map[j][i].c = ' ';
					map[j][i].s = -1;
					for (int q = 1; q < j + 1; q++) {
						if (map[j - q][i].s == 0) {
							map[j][i].c = map[j - q][i].c;
							map[j][i].s = map[j - q][i].s;
							map[j - q][i].c = ' ';
							map[j - q][i].s = -1;
							break;
						}
					}
				}
			}
		}	
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j].c << " ";
			}cout << endl;
		}
		cout << endl;
		cout << answer << endl;
	}
	return answer;
}

int main() {
	//vector<string> v = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	//solution(4, 5, v);
	//vector<string> v = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	vector<string> v = { "TTTTTT", "MMMMMM", "MMMMMM", "MMMMMM", "TTTTTT", "MMMMMM" };
	solution(6, 6, v);
	return 0;
}