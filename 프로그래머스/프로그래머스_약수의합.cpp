#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
	int answer = 0;
	double q = n;
	for (int i = 1; i <= n; i++) {
		if (q / i == n / i) answer += i;
	}
	return answer;
}