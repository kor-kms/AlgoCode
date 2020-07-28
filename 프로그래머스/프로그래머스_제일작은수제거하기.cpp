#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int mi = 100000; int ct = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (mi > arr[i]) {
			mi = arr[i];
			ct = i;
		}
	}
	arr.erase(arr.begin() + ct);

	if (arr.empty()) answer.push_back(-1);
	else answer = arr;
	return answer;
}