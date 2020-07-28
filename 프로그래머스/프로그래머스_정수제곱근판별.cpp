#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long a = 0;
	for (long long i = 1; i <= n; i++) {
		if (i*i == n) {
			a = i;
			break;
		}
	}
	if (a == 0) answer = -1;
	else answer = (a + 1)*(a + 1);
	return answer;
}