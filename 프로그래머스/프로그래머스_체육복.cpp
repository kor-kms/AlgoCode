#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int ar[32];
	for (int i = 1; i <= n; i++) ar[i] = 1;

	for (int i = 0; i < lost.size(); i++) {
		ar[lost[i]]--;
	}
	for (int i = 0; i < reserve.size(); i++) {
		ar[reserve[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (ar[i] == 2) {
			if (ar[i - 1] == 0) {
				ar[i]--;
				ar[i - 1]++;
			}
			else if (ar[i + 1] == 0) {
				ar[i]--;
				ar[i + 1]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) if (ar[i] != 0) answer++;

	return answer;
}