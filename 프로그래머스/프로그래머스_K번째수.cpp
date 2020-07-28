#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		vector<int> w;
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
			w.push_back(array[j]);
		}
		sort(w.begin(), w.end());
		answer.push_back(w[commands[i][2] - 1]);
	}

	return answer;
}