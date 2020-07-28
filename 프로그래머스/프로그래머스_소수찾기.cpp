#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	/*for (double i = 2; i <= n; i++) {
		bool flag = true;
		for (double j = 2; j < i; j++) {
			double x = i / j;
			int y = i / j;
			if (x == y) {
				flag = false;
				break;
			}
		}
		if (flag) answer++;
	}*/
	bool ar[1000001] = { false, };
	for (int i = 2; i <= n; i++) {
		if (ar[i] != false) continue;
		for (int j = i; j <= n; j += i) {
			if (j == i) continue;
			ar[j] = true;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (ar[i] == false) answer++;
	}
	return answer;
}

int main() {
	solution(10);
	return 0;
}